package dogrun2

import "errors"
import "log"
import "time"
import "dogrun2cs"
import "labix.org/v2/mgo"
import "labix.org/v2/mgo/bson"
import proto "code.google.com/p/goprotobuf/proto"

// dog in database
type dogOne struct {
	Id uint32
	Name string
	Level uint32
	Exp uint32
	Str uint32
	Speed uint32
	Intimacy uint32
	CD [3]uint32
}

type dogDB struct {
	UserId string `bson:"_id"`
	Dogs []dogOne
}

// dog in memory
type DogKeeper struct {
	dd dogDB
	dirty bool
	user *User
}

const (
	CD_FEED = 0
	CD_PLAY = 1
	CD_TRAIN = 2
)

var ErrDogNotFound = errors.New("dog id not found")
var ErrOperationInCD = errors.New("operation is in cd")

func init() {
}

// read dog info from database
func (dk *DogKeeper) Load(userid string) error {
	c := SharedDBSession().DB("dogrun2").C("dog")
	err := c.Find(bson.M{"_id": userid}).One(&dk.dd)
	if err == mgo.ErrNotFound {
		dk.dd.UserId = userid
	} else if err != nil {
		log.Println(err)
		return err
	}
	return nil
}

func (dk *DogKeeper) Store() error {
	c := SharedDBSession().DB("dogrun2").C("dog")
	_, err := c.Upsert(bson.M{"_id": dk.dd.UserId}, &dk.dd)
	if err != nil {
		log.Printf("Store err %v\n", err)
		return err
	}

	return nil
}

func (dk *DogKeeper) Feed(req *dogrun2cs.DogFeedReq) error {
	dog := dk.getDog(req.GetDogid());
	if dog == nil {
		log.Printf("dog id %d not found\n", req.GetDogid())
		return ErrDogNotFound
	}

	now := uint32(time.Now().Unix())
	if now < dog.CD[CD_FEED] {
		return ErrOperationInCD
	}

	foodresarray := ResGet(RES_FOOD).(*dogrun2cs.FoodConfigArray)
	if int(req.GetFeedtype()) >= len(foodresarray.Cfg) {
		log.Printf("invalid feed type %d\n", req.GetFeedtype())
		return ErrInvalidParam
	}
	foodres := foodresarray.Cfg[req.GetFeedtype()]

	// cost
	if err := dk.user.UseMoney(int(foodres.GetConsumeGold())); err != nil {
		return err
	}
	if err := dk.user.UseHeart(int(foodres.GetConsumeHeart())); err != nil {
		return err
	}

	// update attr
	dog.Exp = dog.Exp + foodres.GetExp()
	dog.Str = dog.Str + foodres.GetStrong()
	dog.Speed = dog.Speed + foodres.GetSpeed()
	dog.Intimacy = dog.Intimacy + foodres.GetIntimacy()
	dog.CD[CD_FEED] = now + foodres.GetCd()
	dk.dirty = true
	return nil
}

func (dk *DogKeeper) getDog(id uint32) *dogOne {
	for i := 0; i < len(dk.dd.Dogs); i++ {
		if id == dk.dd.Dogs[i].Id {
			return &dk.dd.Dogs[i]
		}
	}
	return nil
}

func ProcFeedDog(c *Client, msg *Msg) int {
	if !c.U.IsLogin() {
		return CLI_PROC_RET_KICK
	}

	var req dogrun2cs.DogFeedReq
	if err := proto.Unmarshal(msg.Body, &req); err != nil {
		return CLI_PROC_RET_KICK
	}

	dk := c.U.dk;
	if err := dk.Feed(&req); err != nil {
		log.Printf("dog feed error %v\n", err)
		return CLI_PROC_RET_ERR
	}

	return CLI_PROC_RET_SUCC
}

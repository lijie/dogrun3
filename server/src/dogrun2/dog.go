package dogrun2

import "errors"
import "log"
//import "time"
import "dogrun2cs"
import "labix.org/v2/mgo"
import "labix.org/v2/mgo/bson"
import proto "code.google.com/p/goprotobuf/proto"

// dog in database
type DogOne struct {
	Id uint32
	Name string
	Level uint32
	Exp uint32
	Str uint32
	Speed uint32
	CD [3]uint32
}

type DogDB struct {
	UserId string `bson:"_id"`
	Dogs []DogOne
}

const (
	CD_FEED = 0
	CD_Play = 1
	CD_TRAIN = 2
)

var ErrDogNotFound = errors.New("dog id not found")

func init() {
}

func (dd *DogDB) Load(userid string) error {
	c := SharedDBSession().DB("dogrun2").C("dog")
	err := c.Find(bson.M{"_id": userid}).One(dd)
	if err == mgo.ErrNotFound {
		dd.UserId = userid
	} else if err != nil {
		log.Println(err)
		return err
	}
	return nil
}

func (dd *DogDB) Store() error {
	c := SharedDBSession().DB("dogrun2").C("dog")
	_, err := c.Upsert(bson.M{"_id": dd.UserId}, dd)
	if err != nil {
		log.Printf("Store err %v\n", err)
		return err
	}

	return nil
}

func (dd *DogDB) Feed(req *dogrun2cs.DogFeedReq) error {
	dog := dd.getDog(req.GetDogid());
	if dog == nil {
		log.Printf("dog id %d not found\n", req.GetDogid())
		return ErrDogNotFound
	}

	// Test
	dog.Level++
	dog.Exp++
	dog.Str++
	dog.Speed++
	return nil
}

func (dd *DogDB) getDog(id uint32) *DogOne {
	for i := 0; i < len(dd.Dogs); i++ {
		if id == dd.Dogs[i].Id {
			return &dd.Dogs[i]
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

	dd := c.U.dogs;
	if err := dd.Feed(&req); err != nil {
		log.Printf("dog feed error %v\n", err)
		return CLI_PROC_RET_ERR
	}

	return CLI_PROC_RET_SUCC
}
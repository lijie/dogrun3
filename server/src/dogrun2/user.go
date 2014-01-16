package dogrun2

import "errors"
import "log"
import "dogrun2cs"
import "labix.org/v2/mgo"
import "labix.org/v2/mgo/bson"
import proto "code.google.com/p/goprotobuf/proto"

func init() {
	// register login cmd
	ClientProcRegister(int(dogrun2cs.Command_kCmdUserLoginReq), ProcUserLogin)
}

// user in memory
type User struct {
	ready bool
	c *Client
	udb UserDb
}

// user in database
type UserDbDog struct {
	Id uint32
	Name string
	Level uint32
	Exp uint32
	Str uint32
	Speed uint32
	CD [3]uint32
}

type UserDbAttr struct {
	Name string
	Title string
	Money uint32
	Heart uint32
}

type UserDb struct {
	UserId string `bson:"_id"`
	Dogs UserDbDog
	Attr UserDbAttr
	LastLogin uint32
}

func (u *User) Load(userid string) error {
	c := SharedDBSession().DB("dogrun2").C("user")
	err := c.Find(bson.M{"_id": userid}).One(&u.udb)
	if err == mgo.ErrNotFound {
		u.udb.UserId = userid
	} else if err != nil {
		log.Println(err)
		return err
	}
	u.ready = true
	return nil
}

func (u *User) Store() error {
	return nil
}

func (u *User) Init(c *Client) {
	u.c = c
	u.ready = false
}

func (u *User) Logout() {
	u.ready = false
}

func (u *User) Login(userid string) error {
	if err := u.Load(userid); err != nil {
		return errors.New("DBError")
	}

	// TODO: update login timestamp

	if err := u.Store(); err != nil {
		return errors.New("DBError")
	}

	u.ready = true
	return nil
}

func (u *User) IsLogin() bool {
	return u.ready
}

func ProcUserLogin(c *Client, msg *Msg) int {
	if c.U.IsLogin() {
		return CLI_PROC_RET_SUCC
	}

	// TODO: check if user already login in other server

	var req dogrun2cs.UserLoginReq
	if err := proto.Unmarshal(msg.Body, &req); err != nil {
		return CLI_PROC_RET_KICK
	}

	if err := c.U.Login(req.GetUserid()); err != nil {
		return CLI_PROC_RET_KICK
	}

	return CLI_PROC_RET_SUCC
}

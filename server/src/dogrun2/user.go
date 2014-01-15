package dogrun2

import "errors"

func init() {
	// register login cmd
	ClientProcRegister(1, ProcUserLogin)
}

// user in memory
type User struct {
	ready bool
	c *Client
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

func (u *User) Load() error {
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

func (u *User) Login() error {
	if err := u.Load(); err != nil {
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

	if err := c.U.Login(); err != nil {
		return CLI_PROC_RET_KICK
	}

	return CLI_PROC_RET_SUCC
}

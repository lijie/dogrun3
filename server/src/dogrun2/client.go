package dogrun2

import "net"
import "fmt"
import "os"
import "time"
import "errors"
import proto "code.google.com/p/goprotobuf/proto"
import "dogrun2cs"

// each client has a Client object
// we can pre-alloc many Client objects for performance
type Client struct {
	conn *net.TCPConn
	enable bool
}

// Header for client request packet
type Header struct {
	Magic int
	Cmd int
	Seq int
	Err int
	Userid string
}

// Save client request/response's header and body
type Msg struct {
	H Header
	M proto.Message
}

const (
	CLI_PROC_RET_SUCC = iota
	CLI_PROC_RET_ERR  = iota
	CLI_PROC_RET_KICK = iota
)

type ClientProc interface {
	Proc(*Msg) int
}

// cmd proc func array
var procFuncArray [128]ClientProc

func init() {
	for i := 0; i < 128; i++ {
		procFuncArray[i] = nil
	}
}

// Register your client cmd proc function
func ClientProcRegister(cmd int, proc ClientProc) error {
	if cmd >= 128 {
		return errors.New("Command is too big")
	}

	procFuncArray[cmd] = proc
	return nil
}

func checkError(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
		os.Exit(1)
	}
}

// main process function for each client
func (c *Client) Proc() {
	// clear Client tmp data
	defer c.Close()
	req_chan := make(chan *Msg, 1)
	// read request from client
	// process req and send rsp
	for c.enable {
		select {
		case msg := <-c.readMsg(req_chan):
			c.procMsg(msg)
		case <-time.After(2 * time.Second):
			c.procTimeout()
		}
	}

	// end here
}

// read packet from tcp conn
func (c *Client) readMsg(req_chan chan *Msg) chan *Msg {
	var msg Msg

	// protobuf test
	r := dogrun2cs.DogFeedReq {
		Dogid: proto.Int32(1),
		Feedtype: proto.Int32(2),
	}

	msg.M = &r
	req_chan <- &msg
	c.enable = false
	return req_chan
}

// proc request by cmd
func (c *Client) procMsg(msg *Msg) {
	if r, ok := msg.M.(*dogrun2cs.DogFeedReq); ok {
		fmt.Printf("DogFeedReq.Dogid %d\n", r.GetDogid());
		fmt.Printf("DogFeedReq.Feedtype %d\n", r.GetFeedtype());
	}

	if msg.H.Cmd >= 128 {
		fmt.Printf("Unknown cmd\n")
		return
	}

	proc := procFuncArray[msg.H.Cmd]
	ret := proc.Proc(msg)

	// proc error and client should be kick off
	if ret == CLI_PROC_RET_KICK {
		c.enable = false
	}
}

// heartbeat timeout
func (c *Client) procTimeout() {
	c.enable = false
}

// client current client
func (c *Client) Close() {
	if c.conn != nil {
		c.conn.Close()
	}
}

func NewClient(conn *net.TCPConn) *Client {
	return &Client{
		conn: conn,
		enable: true,
	}
}

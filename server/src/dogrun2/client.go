package dogrun2

import "net"
import "fmt"
import "os"
import "time"
import "errors"
import "io"
import proto "code.google.com/p/goprotobuf/proto"
import "dogrun2cs"

var ErrReadPacket = errors.New("Read packet from client error")
var ErrUnmarshalMessage = errors.New("Unmarshal protobuff message error")
var ErrInvalidHeader = errors.New("Invalid message header")

const (
	Dogrun2ProtoMagic = 0x20140114
)

// each client has a Client object
// we can pre-alloc many Client objects for performance
type Client struct {
	U User
	Conn *net.TCPConn
	Enable bool
}

// Header for client request packet
type Header struct {
	Magic uint32
	Cmd uint32
	Seq uint32
	Err uint32
	Size uint32
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

type ClientProc func(*Client, *Msg) int

// cmd proc func array
var procFuncArray [128]ClientProc

func init() {
	for i := 0; i < 128; i++ {
		procFuncArray[i] = nil
	}

	// cmd 0 is reserved
	t := func(c *Client, msg *Msg) int {
		return 0
	}

	ClientProcRegister(0, t)
}

// Register your client cmd proc function
func ClientProcRegister(cmd int, proc ClientProc) error {
	if cmd >= 128 {
		return errors.New("Command is too big")
	}

	if procFuncArray[cmd] != nil {
		return errors.New("Command is already registed")
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
	for c.Enable {
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
	if msg, err := readPacket(c.Conn); err != nil {
		// if readPacket err, close client
		c.Enable = false
		req_chan <- nil
	} else {
		req_chan <- msg
	}
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
	ret := proc(c, msg)

	// proc error and client should be kick off
	if ret == CLI_PROC_RET_KICK {
		c.Enable = false
	}
}

// heartbeat timeout
func (c *Client) procTimeout() {
	c.Enable = false
}

// client current client
func (c *Client) Close() {
	if c.Conn != nil {
		c.Conn.Close()
	}
}

func NewClient(conn *net.TCPConn) *Client {
	return &Client{
		Conn: conn,
		Enable: true,
	}
}

const (
	HeaderSize = 20 + 64
)

func parseUint32(buf []byte) uint32 {
	return uint32(buf[0]) << 24 | uint32(buf[1]) << 16 | uint32(buf[2]) << 8 | uint32(buf[0])
}

func parseHeader(buf []byte, h *Header) error {
	h.Magic = parseUint32(buf[0:4])
	if h.Magic != Dogrun2ProtoMagic {
		return ErrInvalidHeader
	}
	h.Cmd = parseUint32(buf[4:8])
	if h.Cmd >= 128 {
		return ErrInvalidHeader
	}
	h.Seq = parseUint32(buf[8:12])
	h.Err = parseUint32(buf[12:16])
	h.Size = parseUint32(buf[16:20])
	h.Userid = string(buf[20:])
	return nil
}

func readPacket(conn *net.TCPConn) (*Msg, error) {
	var hbuf [HeaderSize]byte

	n, err := io.ReadFull(conn, hbuf[0:])
	if n != HeaderSize || err != nil {
		return nil, ErrReadPacket
	}

	msg := Msg{}
	if err = parseHeader(hbuf[0:], &msg.H); err != nil {
		return nil, err
	}

	bodysize := int(msg.H.Size - HeaderSize)
	body := make([]byte, bodysize)
	n, err = io.ReadFull(conn, body)
	if n != bodysize || err != nil {
		return nil, ErrReadPacket
	}

	if err = proto.Unmarshal(body, msg.M); err != nil {
		return nil, ErrUnmarshalMessage
	}

	return &msg, nil
}

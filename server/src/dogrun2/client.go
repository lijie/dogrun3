package dogrun2

import "net"
import "fmt"
import "os"
import proto "code.google.com/p/goprotobuf/proto"
import "dogrun2cs"

// each client has a Client object
// we can pre-alloc many Client objects for performance
type Client struct {
	conn *net.TCPConn
}

func init() {
	// protobuf test
	r := dogrun2cs.DogFeedReq {
		Dogid: proto.Int32(1),
		Feedtype: proto.Int32(2),
	}
	test(1, &r)
}

func checkError(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
		os.Exit(1)
	}
}

// protobuf test
func test(cmd int, msg proto.Message) {
	if r, ok := msg.(*dogrun2cs.DogFeedReq); ok {
		fmt.Printf("DogFeedReq.Dogid %d\n", r.GetDogid());
		fmt.Printf("DogFeedReq.Feedtype %d\n", r.GetFeedtype());
	}
}

// main process function for each client
func (c *Client) Proc() {
	// read request from client
	// process req and send rsp
	// check heartbeat

	// clear Client tmp data
	defer c.Close()
}

func (c *Client) Close() {
	c.conn.Close()
}

func NewClient(conn *net.TCPConn) *Client {
	return &Client{
		conn: conn,
	}
}

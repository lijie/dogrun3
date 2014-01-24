package dogrun2

import "os"
import "io/ioutil"
import "log"
import "dogrun2cs"
import proto "code.google.com/p/goprotobuf/proto"

const (
	RES_FOOD = iota
	RES_NR = iota
)

func init() {
	resInit()
}

var resMap [RES_NR]proto.Message

type resfile struct {
	name string
	id int
	pb proto.Message
}

func resInit() {
	files := []resfile {
		{"../etc/food.cfg", RES_FOOD, &dogrun2cs.FoodConfigArray{}},
	}

	for i := 0; i < len(files); i++ {
		resLoadFile(&files[i])
	}
}

func resLoadFile(file *resfile) {
	f, err := os.Open(file.name)
	if err != nil {
		log.Printf("Load res file %s error %v\n", file.name, err)
		return
	}
	content, err := ioutil.ReadAll(f)
	if err != nil {
		log.Printf("Load res file %s error %v\n", file.name, err)
		return
	}
	err = proto.Unmarshal(content, file.pb)
	if err != nil {
		log.Printf("Load res file %s error %v\n", file.name, err)
		return
	}
	resMap[file.id] = file.pb
}

func ResGet(resid int) proto.Message {
	if resid >= RES_NR {
		return nil
	}
	return resMap[resid]
}


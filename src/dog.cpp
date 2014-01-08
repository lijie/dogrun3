#include "assert.h"
#include "time.h"
#include "cocos2d.h"
#include "dog.h"

static dogrun2::FoodConfigArray *FoodCfg = NULL;
static dogrun2::TrainConfigArray *TrainCfg = NULL;
static dogrun2::PlayConfigArray *PlayCfg = NULL;

Dog::Dog() {
  attr_.set_name("FirstDog");
  feedcd_ = 0;
  traincd_ = 0;
  playcd_ = 0;
}

int Dog::Feed(int feedtype) {
  time_t now = time(NULL);
  if (feedcd_ > now) {
    CCLOGERROR("feed in cd.\n");
    return -1;
  }

  const dogrun2::FoodConfig& cfg = FoodCfg->cfg(feedtype);
  attr_.set_str(attr_.str() + cfg.str());
  attr_.set_exp(attr_.exp() + cfg.exp());
  feedcd_ = now + kDefalutFeedCD;
  return 0;
}

int Dog::Train(int traintype) {
  time_t now = time(NULL);
  if (traincd_ > now) {
    CCLOGERROR("Train in cd.\n");
    return -1;
  }

  const dogrun2::TrainConfig& cfg = TrainCfg->cfg(traintype);
  attr_.set_speed(attr_.speed() + cfg.speed());
  attr_.set_exp(attr_.exp() + cfg.exp());
  traincd_ = now + kDefaultTrainCD;
  return 0;
}

int Dog::Play(int playtype) {
  time_t now = time(NULL);
  if (playcd_ > now) {
    CCLOGERROR("Play in cd.\n");
    return -1;
  }

  attr_.set_exp(attr_.exp() + 1);
  attr_.set_intimacy(attr_.intimacy() + 1);
  playcd_ = now + kDefaultPlayCD;
  return 0;
}

int Dog::Levelup() {
  return 0;
}

User* User::current_;

void User::InitCurrent() {
  User *u = new User();
  assert(u != NULL);

  u->set_id("FirstUser");
  u->set_title("FirstTitle");
  u->set_money(1000);
  u->set_heart(1000);

  Dog *dog = new Dog();
  assert(u != NULL);
  u->AddDog(dog);
  dog->set_owner(u);

  User::set_current(u);
}

int User::AddDog(Dog *dog) {
  dogs_.push_back(dog);
  return 0;
}

int User::UseMoney(int money) {
  if (money_ < money)
    return -1;

  CCLOGINFO("Use Money %d -> %d\n", money_, money_ - money);
  money_ -= money;
  return 0;
}

#ifdef WIN32
#include <io.h>
#endif
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"

using google::protobuf::io::FileInputStream;
using google::protobuf::io::ZeroCopyInputStream;
using google::protobuf::TextFormat;

int ParseFromFile(const string& filepath, google::protobuf::Message *output) {
#ifdef WIN32
  int fd = _open(filepath.c_str(), _O_RDONLY);
#else
  int fd = open(filepath.c_str(), O_RDONLY);
#endif
  if (fd < 0) {
    CCLOGERROR("open %s error\n", filepath.c_str());
    return -1;
  }
  ZeroCopyInputStream *input = new FileInputStream(fd);
  bool succ = TextFormat::Parse(input, output);
  assert(succ);
#ifdef WIN32
  _close(fd);
#else
  close(fd);
#endif
  string s = output->DebugString();
  CCLOG("Parse %s\n", s.c_str());
  return 0;
}

int DogRunInit() {
  printf("%s\n", __FUNCTION__);
  if (!FoodCfg) {
    FoodCfg = new dogrun2::FoodConfigArray;
    assert(FoodCfg != NULL);
    ParseFromFile("etc/food.cfg", FoodCfg);
  }
  if (!TrainCfg) {
    TrainCfg = new dogrun2::TrainConfigArray;
    assert(TrainCfg != NULL);
    ParseFromFile("etc/train.cfg", TrainCfg);
  }
  if (!PlayCfg) {
    PlayCfg = new dogrun2::PlayConfigArray;
    assert(PlayCfg != NULL);
    ParseFromFile("etc/Play.cfg", PlayCfg);
  }

  return 0;
}

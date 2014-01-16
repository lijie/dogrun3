#include "assert.h"
#include "time.h"
#include "cocos2d.h"
#include "dog.h"
#include "common.h"

static dogrun2::FoodConfigArray *FoodCfg = NULL;
static dogrun2::TrainConfigArray *TrainCfg = NULL;
static dogrun2::PlayConfigArray *PlayCfg = NULL;
static dogrun2::DogLevelConfigArray *DogLevelCfg = NULL;

Dog::Dog() {
  attr_.set_name("FirstDog");
  memset(cd_, 0, sizeof(cd_));
}

int Dog::Feed(int feedtype) {
  time_t now = time(NULL);
  if (cd_[kFeedCD] > now) {
    CCLOGERROR("feed in cd.\n");
    return -1;
  }

  const dogrun2::FoodConfig& cfg = FoodCfg->cfg(feedtype);
  attr_.set_str(attr_.str() + cfg.str());
  attr_.set_exp(attr_.exp() + cfg.exp());
  cd_[kFeedCD] = now + kDefalutFeedCD;
  return 0;
}

int Dog::Train(int traintype) {
  time_t now = time(NULL);
  if (cd_[kTrainCD] > now) {
    CCLOGERROR("Train in cd.\n");
    return -1;
  }

  const dogrun2::TrainConfig& cfg = TrainCfg->cfg(traintype);
  attr_.set_speed(attr_.speed() + cfg.speed());
  attr_.set_exp(attr_.exp() + cfg.exp());
  cd_[kTrainCD] = now + cfg.cd();
  owner_->set_money(owner_->money() - cfg.consume_gold());
  owner_->set_heart(owner_->heart() - cfg.consume_heart());
  return 0;
}

int Dog::Play(int playtype) {
  time_t now = time(NULL);
  if (cd_[kPlayCD] > now) {
    CCLOGERROR("Play in cd.\n");
    return -1;
  }

  attr_.set_exp(attr_.exp() + 1);
  attr_.set_intimacy(attr_.intimacy() + 1);
  cd_[kPlayCD] = now + kDefaultPlayCD;
  return 0;
}

int Dog::Levelup() {
  int nextlv = attr_.lv() + 1;
  if (nextlv >= DogLevelCfg->cfg_size()) {
    CCLOGERROR("Dog reaches max level %d\n", attr_.lv());
    return -1;
  }
  const dogrun2::DogLevelConfig& c = DogLevelCfg->cfg(nextlv);
  if (attr_.exp() >= c.exp()) {
    CCLOG("levelup %d -> %d\n", attr_.lv(), nextlv);
    attr_.set_lv(nextlv);
  }
  return 0;
}

int Dog::ClearCD(int cdtype) {
  if (cdtype >= kOperationCDNR)
    return -1;

  time_t now = time(NULL);
  if (cd_clear_count_[cdtype] < 10) {
    // first clear
    if (cd_clear_count_[cdtype] == 0) {
      cd_clear_time_[cdtype] = now;
    }
  }

  // if beyond one day
  time_t last = cd_clear_time_[cdtype];
  if (now - last >= kTimeDaySeconds) {
    cd_clear_count_[cdtype] = 0;
    cd_clear_time_[cdtype] = now;
  } else {
    return -1;
  }

  cd_clear_count_[cdtype]++;
  cd_[cdtype] = 0;
  return 0;
}

User* User::current_;

void User::InitCurrent() {
  User *u = new User();
  assert(u != NULL);

  u->set_id("FirstUser");
  u->set_title("吉娃娃饲养家");
  u->set_money(10000);
  u->set_heart(10000);

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
    ParseFromFile("etc/play.cfg", PlayCfg);
  }

  return 0;
}

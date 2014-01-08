#include "assert.h"
#include "time.h"
#include "cocos2d.h"
#include "dog.h"

Dog::Dog() {
  lv_ = 1;
  star_ = 1;
  str_ = 1;
  speed_ = 1;
  intimacy_ = 1;
  name_ = "FirstDog";
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

  str_++;
  exp_++;
  feedcd_ = now + kDefalutFeedCD;
  return 0;
}

int Dog::Train(int traintype) {
  time_t now = time(NULL);
  if (traincd_ > now) {
    CCLOGERROR("Train in cd.\n");
    return -1;
  }

  speed_++;
  exp_++;
  traincd_ = now + kDefaultTrainCD;
  return 0;
}

int Dog::Play(int playtype) {
  time_t now = time(NULL);
  if (playcd_ > now) {
    CCLOGERROR("Play in cd.\n");
    return -1;
  }

  intimacy_++;
  exp_++;
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

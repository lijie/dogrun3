#include "assert.h"
#include "time.h"
#include "cocos2d.h"
#include "dog.h"

Dog::Dog()
{
    lv_ = 1;
    star_ = 1;
    str_ = 1;
    speed_ = 1;
    intimacy_ = 1;
    name_ = "FirstDog";
    feedcd_ = 0;
    traincd_ = 0;
}

int Dog::Feed(int feedtype)
{
  time_t now = time(NULL);
  if (feedcd_ > now) {
    CCLOGERROR("feed in cd.\n");
    return -1;
  }

  intimacy_++;
  feedcd_ = now + 60;
  return 0;
}

int Dog::Train(int traintype)
{
  time_t now = time(NULL);
  if (traincd_ > now) {
    CCLOGERROR("Train in cd.\n");
    return -1;
  }

  str_++;
  traincd_ = now + 60;
  return 0;
}

User* User::current_;

void User::InitCurrent()
{
    User *u = new User();
    assert(u != NULL);

    u->set_id("FirstUser");
    u->set_title("¼ªÍÞÍÞÎ¹Ñø×¨¼Ò");
    u->set_money(1000);
    u->set_heart(1000);

    Dog *dog = new Dog();
    assert(u != NULL);
    u->AddDog(dog);
    dog->set_owner(u);

    User::set_current(u);
}

int User::AddDog(Dog *dog)
{
    dogs_.push_back(dog);
    return 0;
}

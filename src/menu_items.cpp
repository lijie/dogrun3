#include "menu_items.h"

bool ClockMenuItem::init() {
  return CCMenuItemSprite::init();
}

void ClockMenuItem::OnTime() {
  
}

void ClockMenuItem::StartClock() {
  if(clock_time_ >= 0) {
    //this->scheduleOnce( schedule_selector(ClockMenuItem::OnTime), float(clock_time_));
  }
}

bool FSMenuItem::init() {
  CCSprite* sprite = CCSprite::create();
  sprite->initWithSpriteFrameName("like.png");
  this->addChild(sprite, 1);
  sprite->setScale(0.4f);
  sprite->setPosition(ccp(30,20));

  CCLabelTTF *label = CCLabelTTF::create("训练", "Arial", 21);
  this->addChild(label, 1);
  label->setPosition(ccp(40, 60));
  
  return CCMenuItemSprite::init();
}


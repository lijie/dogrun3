#pragma once
#include "cocos2d.h"

USING_NS_CC;

class ClockMenuItem : public CCMenuItemSprite {
public:
  ClockMenuItem()
    :clock_time_(0){}

  virtual ~ClockMenuItem(){}

  virtual bool init();

  CREATE_FUNC(ClockMenuItem);
protected:
  void OnTime();
  void StartClock();
public:
  uint32_t clock_time(){return clock_time_;}
  void set_clock_time(uint32_t clock_time){clock_time_ = clock_time;}
protected:
  uint32_t clock_time_;
};

class FSMenuItem : public CCMenuItemSprite {
public:
  FSMenuItem(){}

  virtual ~FSMenuItem(){}

  virtual bool init();

  static FSMenuItem * create(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite, CCObject *target, SEL_MenuHandler selector)
  {
    FSMenuItem *ret = new FSMenuItem();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = NULL;
        return NULL;
    }
    ret->initWithNormalSprite(normalSprite, selectedSprite, disabledSprite, target, selector);
    return ret;
  }
  CREATE_FUNC(FSMenuItem);
};


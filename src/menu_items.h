#pragma once
#include "cocos2d.h"

USING_NS_CC;
static CCDictionary *g_dict = CCDictionary::createWithContentsOfFile("etc/ui.xml");

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
  unsigned int clock_time_;
};

class FSMenuItem : public CCMenuItemSprite {
public:
  FSMenuItem(){}

  virtual ~FSMenuItem(){}

  static FSMenuItem * create(CCNode *normalSprite, 
                             CCNode *selectedSprite, 
                             CCNode *disabledSprite, 
                             CCObject *target, 
                             SEL_MenuHandler selector);

  void InitData(const char* desc, int icon_type );
  //CREATE_FUNC(FSMenuItem);
};


#pragma once
#include "cocos2d.h"

USING_NS_CC;

class ClockMenuItem : public CCMenuItem {
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


#include "menu_items.h"

bool ClockMenuItem::init() {
  return CCMenuItem::init();
}

void ClockMenuItem::OnTime() {
  
}

void ClockMenuItem::StartClock() {
  if(clock_time_ >= 0) {
    //this->scheduleOnce( schedule_selector(ClockMenuItem::OnTime), float(clock_time_));
  }
}

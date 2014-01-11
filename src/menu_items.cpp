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

FSMenuItem* FSMenuItem::create(CCNode *normalSprite, 
                               CCNode *selectedSprite, 
                               CCNode *disabledSprite, 
                               CCObject *target, 
                               SEL_MenuHandler selector) {
  FSMenuItem *ret = new FSMenuItem();
  if (ret) {
    ret->autorelease();
  } else {
    delete ret;
    ret = NULL;
    return ret;
  }
  ret->initWithNormalSprite(normalSprite, selectedSprite, disabledSprite, target, selector);
  return ret;
}

void FSMenuItem::InitData(const char* desc_type, int icon_type ) {
  const char *desc = ((CCString*)g_dict->objectForKey(desc_type))->m_sString.c_str();
  //const char *walk_desc = ((CCString*)g_dict->objectForKey("walk_desc"))->m_sString.c_str();
  //const char *touch_desc = ((CCString*)g_dict->objectForKey("touch_desc"))->m_sString.c_str();
  //const char *ball_desc = ((CCString*)g_dict->objectForKey("ball_desc"))->m_sString.c_str();
  //const char *frisbee_desc = ((CCString*)g_dict->objectForKey("frisbee_desc"))->m_sString.c_str();
  int desc_pos_x = ((CCString*)g_dict->objectForKey("desc_pos_x"))->intValue();
  int desc_pos_y = ((CCString*)g_dict->objectForKey("desc_pos_y"))->intValue();

  const char *speed_desc = ((CCString*)g_dict->objectForKey("speed_desc"))->m_sString.c_str();
  int speed_pos_x = ((CCString*)g_dict->objectForKey("speed_pos_x"))->intValue();
  int speed_pos_y = ((CCString*)g_dict->objectForKey("speed_pos_y"))->intValue();

  const char *exp_desc = ((CCString*)g_dict->objectForKey("exp_desc"))->m_sString.c_str();
  int exp_pos_x = ((CCString*)g_dict->objectForKey("exp_pos_x"))->intValue();
  int exp_pos_y = ((CCString*)g_dict->objectForKey("exp_pos_y"))->intValue();
  
  const char *icon_heart_name = ((CCString*)g_dict->objectForKey("icon_heart_name"))->m_sString.c_str();
  const char *icon_gold_name  = ((CCString*)g_dict->objectForKey("icon_gold_name"))->m_sString.c_str();
  int icon_pos_x = ((CCString*)g_dict->objectForKey("icon_pos_x"))->intValue();
  int icon_pos_y = ((CCString*)g_dict->objectForKey("icon_pos_y"))->intValue();

  CCLabelTTF *label_desc = CCLabelTTF::create(desc, "Arial", 21);
  addChild(label_desc, 1);
  label_desc->setAnchorPoint(ccp(0,0));
  label_desc->setPosition(ccp(desc_pos_x, desc_pos_y));

  CCLabelTTF *label_speed_desc = CCLabelTTF::create(speed_desc, "Arial", 14);
  addChild(label_speed_desc, 1);
  label_speed_desc->setAnchorPoint(ccp(0,0));
  label_speed_desc->setPosition(ccp(speed_pos_x, speed_pos_y));

  CCLabelTTF *label_exp_desc = CCLabelTTF::create(exp_desc, "Arial", 14);
  addChild(label_exp_desc, 1);
  label_exp_desc->setAnchorPoint(ccp(0,0));
  label_exp_desc->setPosition(ccp(exp_pos_x, exp_pos_y));

  CCSprite* sprite = CCSprite::create();
  const char *icon_name = (icon_type == 1? icon_heart_name: icon_gold_name);
  sprite->initWithSpriteFrameName(icon_name);
  addChild(sprite, 1);
  sprite->setScale(0.4f);
  sprite->setAnchorPoint(ccp(0,0));
  sprite->setPosition(ccp(icon_pos_x, icon_pos_y));

  return ;
}


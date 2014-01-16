#include "menu_items.h"
#include "ui_config_init.h"
#include "protocol/uiconfig.pb.h"
#include "dog.h"
#include "event_mgr.h"

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

void FSMenuItem::InitData(int item_type, int data_index) {
  const dogrun2::UIItemConf* cfg = NULL;
  switch(item_type) {
  case dogrun2::kItemTrain:
    {
      cfg = &(GetUITrainCfg()->conf(data_index));
      break;
    }
  case dogrun2::kItemPlay:
    {
      cfg = &(GetUIPlayCfg()->conf(data_index));
      break;
    }
  default:
    return;
  }
  item_type_ = item_type;
  data_index_ = data_index;

  CCLabelTTF *label_desc = CCLabelTTF::create(
    cfg->title().desc().c_str(),
    cfg->title().font().c_str(),
    cfg->title().font_size());

  addChild(label_desc, 1);
  label_desc->setAnchorPoint(ccp(0,0));
  label_desc->setPosition(ccp(cfg->title().pos_x(), cfg->title().pos_y()));

  CCLabelTTF *label_speed_desc = CCLabelTTF::create(
    cfg->speed().desc().c_str(),
    cfg->speed().font().c_str(),
    cfg->speed().font_size());
  addChild(label_speed_desc, 1);
  label_speed_desc->setAnchorPoint(ccp(0,0));
  label_speed_desc->setPosition(ccp(cfg->speed().pos_x(), cfg->speed().pos_y()));

  CCLabelTTF *label_exp_desc = CCLabelTTF::create(
    cfg->exp().desc().c_str(),
    cfg->exp().font().c_str(),
    cfg->exp().font_size());
  addChild(label_exp_desc, 1);
  label_exp_desc->setAnchorPoint(ccp(0,0));
  label_exp_desc->setPosition(ccp(cfg->exp().pos_x(), cfg->exp().pos_y()));

  CCSprite* sprite = CCSprite::createWithSpriteFrameName(cfg->icon().icon().c_str());
  addChild(sprite, 1);
  sprite->setScale((float)cfg->icon().scale()/100.0f);
  sprite->setAnchorPoint(ccp(0,0));
  sprite->setPosition(ccp(cfg->icon().pos_x(), cfg->icon().pos_y()));

  CCLabelTTF *label_icon_num = CCLabelTTF::create(
    cfg->icon_num().desc().c_str(),
    cfg->icon_num().font().c_str(),
    cfg->icon_num().font_size());
  addChild(label_icon_num, 1);
  label_icon_num->setAnchorPoint(ccp(0,0));
  label_icon_num->setPosition(ccp(cfg->icon_num().pos_x(), cfg->icon_num().pos_y()));

  return ;
}

void FSMenuItem::ItemClickCallback() {
  int ret = 0;
  ret = User::current()->dogs(0)->Train(this->data_index_);
  if(ret >= 0) {
    EventMgr::Instance().Response(kEventDogAttrChange);
    EventMgr::Instance().Response(kEventUserInfoChange);
  }
}


#pragma once
#include "cocos2d.h"
#include <string>
USING_NS_CC;

class MultiSpriteMenuItem : public CCMenuItemSprite {
public:
  MultiSpriteMenuItem(){}
  virtual void onEnter()
  {
    int a = 0;
    a++;
  }
  virtual ~MultiSpriteMenuItem(){}

  static MultiSpriteMenuItem * create(std::string item_type, CCPoint& pos);

  void ClickItemCallback(CCObject* sender);
  void ClickDoingItemCallback(CCObject* sender);
  void ClickDoneItemCallback(CCObject* sender);
  void ChangeDoingItemCallback(CCObject* sender);

  int GetItemWidth();
  void AddToArray(CCArray* array);
  void OnTime(float f);
protected:
  void InitItem();
  void InitItemPos();

protected:
  CCMenuItemSprite* normal_item_;
  CCMenuItemSprite* doing_item_;
  CCMenuItemSprite* done_item_;
  std::string item_type_;
  CCPoint item_pos_;
  int cd_time_;
  CCLabelTTF *label_cd_;
};

class FSMenuItem : public CCMenuItemSprite {
public:
  FSMenuItem(){}

  virtual ~FSMenuItem(){}

  static FSMenuItem * create(int item_type, int data_index);

  static FSMenuItem * create(CCNode *normalSprite, 
                             CCNode *selectedSprite, 
                             CCNode *disabledSprite, 
                             CCObject *target, 
                             SEL_MenuHandler selector);
  void ItemClickCallback(CCObject* sender);
  void InitData(int item_type, int data_index);
protected:
  int item_type_;
  int data_index_;
};


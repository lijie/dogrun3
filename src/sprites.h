#pragma once
#include "cocos2d.h"
#include "dog.h"

USING_NS_CC;

class DogSprite : public CCSprite,
  public CCTargetedTouchDelegate {
public:
  virtual bool init();
  virtual void onEnter();
  virtual void onExit();

  virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
  virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
  virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

  virtual void touchDelegateRetain();
  virtual void touchDelegateRelease();
  bool containsTouchLocation(CCTouch* touch);

  CREATE_FUNC(DogSprite);
protected:
  CCPoint last_xy_;
  CCPoint start_xy_;
  CCRect rect();
  Dog* dog_;
  CCSprite* ability_sprite_;
  bool ability_status_;
};

class HeartProgressBar{
public:
  HeartProgressBar(){};
  void SetMaxNum(int max_num);
  void SetHeartProgressBar(float cur_num);
  void CreateSprite(CCNode* parent);
protected:
  float max_num_;
  CCSprite* heart_left_;
  CCSprite* heart_mid_;
  CCSprite* heart_right_;
};



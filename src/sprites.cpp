#include "sprites.h"
#include "dog.h"
#include "event_mgr.h"

bool DogSprite::init() {
  if (!CCSprite::init())
    return false;

  ability_status_ = false;
  this->initWithSpriteFrameName("dog.png");
  dog_ = User::current()->dogs(0);

  ability_sprite_ = CCSprite::create();
  ability_sprite_->initWithSpriteFrameName("dog_ability.png");
  addChild(ability_sprite_, 1);
  ability_sprite_->setAnchorPoint(ccp(0,0));
  ability_sprite_->setPosition(ccp(-96,96));
  ability_sprite_->setVisible(ability_status_);
  return true;
}

CCRect DogSprite::rect() {
  CCSize s = this->getTexture()->getContentSize();
  return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}

bool DogSprite::containsTouchLocation(CCTouch* touch) {
  return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

void DogSprite::onEnter() {
  CCDirector* pDirector = CCDirector::sharedDirector();
  pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
  CCSprite::onEnter();
}

bool DogSprite::ccTouchBegan(CCTouch* touch, CCEvent* event) {
  if (!containsTouchLocation(touch))
    return false;
  last_xy_ = touch->getLocation();
  start_xy_ = touch->getLocation();
  return true;
}

void DogSprite::ccTouchEnded(CCTouch* touch, CCEvent* event) {
  CCPoint cur_xy = touch->getLocation();
  if(start_xy_.fuzzyEquals(cur_xy, 2.0f)) {
    ability_status_ = !ability_status_;
    ability_sprite_->setVisible(ability_status_);
    EventMgr::Instance().Response(1);
  }
}

void DogSprite::ccTouchMoved(CCTouch* touch, CCEvent* event) {
  CCPoint loc = touch->getLocation();
  float x, y;
  x = loc.x - last_xy_.x;
  y = loc.y - last_xy_.y;

  CCPoint pos = this->getPosition();
  this->setPosition(ccp(pos.x + x, pos.y + y));
  last_xy_ = loc;
}

void DogSprite::touchDelegateRetain() {
  this->retain();
}

void DogSprite::touchDelegateRelease() {
  this->release();
}

void DogSprite::onExit() {
  CCDirector* pDirector = CCDirector::sharedDirector();
  pDirector->getTouchDispatcher()->removeDelegate(this);
  CCSprite::onExit();
} 

bool HeartBarSprite::init() {
  heart_mid_ = CCSprite::create();
  heart_mid_->initWithSpriteFrameName("like_mid.png");
  heart_mid_->setAnchorPoint(ccp(0,0));
  heart_mid_->setPosition(ccp(10, 2));
  heart_mid_->setScaleX(float(4/4));
  addChild(heart_mid_, 1);

  CCSprite* heart_right = CCSprite::create();
  heart_right->initWithSpriteFrameName("like_right.png");
  heart_right->setAnchorPoint(ccp(0,0));
  heart_right->setPosition(ccp(14, 2));
  return 0;
}

void HeartBarSprite::SetHeartBar(int cur_num, int max_num) {
  if(max_num > 0) {
    max_num_ = max_num;
  }

  cur_num_ = cur_num;



}


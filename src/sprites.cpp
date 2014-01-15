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

void HeartProgressBar::SetMaxNum(int max_num) {
  max_num_ = max_num;
}

void HeartProgressBar::CreateSprite(CCNode* parent) {
  heart_left_ = CCSprite::create();
  heart_left_->initWithSpriteFrameName("like_left.png");
  heart_left_->setAnchorPoint(ccp(0,0));
  heart_left_->setPosition(ccp(2, 2));
  parent->addChild(heart_left_, 1);

  int heart_left_width = heart_left_->getTextureRect().size.width;
  heart_mid_ = CCSprite::create();
  //heart_mid_->initWithFile("like_mid.png");
  heart_mid_->initWithSpriteFrameName("like_mid.png");
  heart_mid_->setAnchorPoint(ccp(0,0));
  heart_mid_->setPosition(ccp(heart_left_width +2, 2));
  heart_mid_->setVisible(false);
  //heart_mid_->setScaleX(float(4/4));
  ccTexParams params = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  heart_mid_->getTexture()->setTexParameters(&params);
  parent->addChild(heart_mid_, 1);

  heart_right_ = CCSprite::create();
  heart_right_->initWithSpriteFrameName("like_right.png");
  heart_right_->setAnchorPoint(ccp(0,0));
  heart_right_->setVisible(false);
  parent->addChild(heart_right_, 1);
}

void HeartProgressBar::SetHeartProgressBar(float cur_num) {
  float scalex = ((cur_num*(104/max_num_)))/4;
  heart_mid_->setScaleX(scalex);
  heart_mid_->setVisible(true);
  int heart_right_width = heart_right_->getTextureRect().size.width;
  if(cur_num > heart_right_width) {
    heart_right_->setVisible(true);
    int mid_real_width = heart_mid_->getContentSize().width * scalex;
    int heart_left_width = heart_left_->getTextureRect().size.width;
    heart_right_->setPosition(ccp(mid_real_width + heart_left_width, 2));
    //heart_right_->setPosition(ccp(122, 2));
  }

  //float mid_real_width = cur_num*(104/max_num_);
  //CCRect rect(0, 0, mid_real_width, 36);
  //heart_mid_->setVisible(true);
  //heart_mid_->setTextureRect(rect);
  //int heart_right_width = heart_right_->getTextureRect().size.width;
  //if(cur_num > heart_right_width) {
  //  int heart_left_width = heart_left_->getTextureRect().size.width;
  //  heart_right_->setVisible(true);
  //  heart_right_->setPosition(ccp(mid_real_width + heart_left_width+2, 2));
  //}

}


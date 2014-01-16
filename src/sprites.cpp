#include "sprites.h"
#include "dog.h"
#include "event_mgr.h"

bool DogAttrPanelSprite::init() {
  if (!CCSprite::init())
    return false;

  this->initWithSpriteFrameName("dog_ability.png");
  dog_ = User::current()->dogs(0);

  char dog_name[32] = {0};
  snprintf(dog_name,sizeof(dog_name),"%s", dog_->attr().name().c_str());
  label_dog_name_ = CCLabelTTF::create( dog_name, "Arial", 20);
  label_dog_name_->setAnchorPoint(ccp(0, 0));
  label_dog_name_->setPosition(ccp(98, 139));
  addChild(label_dog_name_, 1);

  char dog_character[32] = {0};
  snprintf(dog_character,sizeof(dog_character),"%s", "A等级");
  CCLabelTTF* label_dog_character = CCLabelTTF::create( dog_character, "Arial", 20);
  label_dog_character->setAnchorPoint(ccp(0, 0));
  label_dog_character->setPosition(ccp(98, 111));
  addChild(label_dog_character, 1);

  char dog_lv[32] = {0};
  snprintf(dog_lv,sizeof(dog_lv),"%s  %d", "Lv", dog_->attr().lv());
  label_dog_lv_ = CCLabelTTF::create( dog_lv, "Arial", 20);
  label_dog_lv_->setAnchorPoint(ccp(0, 0));
  label_dog_lv_->setPosition(ccp(30, 80));
  addChild(label_dog_lv_, 1);

  char dog_strong[32] = {0};
  snprintf(dog_strong,sizeof(dog_strong),"%d", dog_->attr().str());
  label_dog_strong_ = CCLabelTTF::create( dog_strong, "Arial", 20);
  label_dog_strong_->setAnchorPoint(ccp(0, 0));
  label_dog_strong_->setPosition(ccp(30, 24));
  addChild(label_dog_strong_, 1);

  char dog_speed[32] = {0};
  snprintf(dog_speed,sizeof(dog_speed),"%d", dog_->attr().speed());
  label_dog_speed_ = CCLabelTTF::create( dog_speed, "Arial", 20);
  label_dog_speed_->setAnchorPoint(ccp(0, 0));
  label_dog_speed_->setPosition(ccp(110, 24));
  addChild(label_dog_speed_, 1);

  char dog_intimacy[32] = {0};
  snprintf(dog_intimacy,sizeof(dog_intimacy),"%d", dog_->attr().intimacy());
  label_dog_intimacy_ = CCLabelTTF::create( dog_intimacy, "Arial", 20);
  label_dog_intimacy_->setAnchorPoint(ccp(0, 0));
  label_dog_intimacy_->setPosition(ccp(185, 24));
  addChild(label_dog_intimacy_, 1);

  return true;
}

void DogAttrPanelSprite::UpdateAttr() {
  char dog_name[32] = {0};
  snprintf(dog_name,sizeof(dog_name),"%s", dog_->attr().name().c_str());
  label_dog_name_->setString(dog_name);

  char dog_lv[32] = {0};
  snprintf(dog_lv,sizeof(dog_lv),"%s  %d", "Lv", dog_->attr().lv());
  label_dog_lv_->setString(dog_lv);

  char dog_strong[32] = {0};
  snprintf(dog_strong,sizeof(dog_strong),"%d", dog_->attr().str());
  label_dog_strong_->setString(dog_strong);

  char dog_speed[32] = {0};
  snprintf(dog_speed,sizeof(dog_speed),"%d", dog_->attr().speed());
  label_dog_speed_->setString(dog_speed);

  char dog_intimacy[32] = {0};
  snprintf(dog_intimacy,sizeof(dog_intimacy),"%d", dog_->attr().intimacy());
  label_dog_intimacy_->setString(dog_intimacy);
}

void DogSprite::DogAttrChangeCallBack(CCObject* sender) {
  dog_attr_sprite_->UpdateAttr();
}

bool DogSprite::init() {
  if (!CCSprite::init())
    return false;

  dog_attr_status_ = false;
  this->initWithSpriteFrameName("dog.png");
  dog_ = User::current()->dogs(0);

  dog_attr_sprite_ = DogAttrPanelSprite::create();
  dog_attr_sprite_->setAnchorPoint(ccp(0,0));
  dog_attr_sprite_->setPosition(ccp(-96,96));
  dog_attr_sprite_->setVisible(dog_attr_status_);
  addChild(dog_attr_sprite_, 1);

  EventMgr::Instance().Register(kEventDogAttrChange,
    this, callfuncO_selector(DogSprite::DogAttrChangeCallBack));
  //ability_sprite_ = CCSprite::create();
  //ability_sprite_->initWithSpriteFrameName("dog_ability.png");
  //addChild(ability_sprite_, 1);
  //ability_sprite_->setAnchorPoint(ccp(0,0));
  //ability_sprite_->setPosition(ccp(-96,96));
  //ability_sprite_->setVisible(ability_status_);
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
    dog_attr_status_ = !dog_attr_status_;
    dog_attr_sprite_->setVisible(dog_attr_status_);
    EventMgr::Instance().Response(kEventClickDogMenu);
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

  char num[32] = {0};
  snprintf(num,sizeof(num),"%d", 1024);
  heart_num_ = 
    CCLabelTTF::create( num, "Arial", 24);
  parent->addChild(heart_num_, 3);
  heart_num_->setPosition(ccp(70, 20));
}

void HeartProgressBar::SetHeartProgressBar(float cur_num) {
  char num[32] = {0};
  snprintf(num,sizeof(num),"%d", (int)cur_num);
  heart_num_->setString(num);
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


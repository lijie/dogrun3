#include "layers.h"



bool DogLayer::init()
{
  if (!CCLayer::init())
    return false;

  bg_ = CCSprite::create("background.png");
  bg_->setPosition(ccp(400, 240));
  this->addChild(bg_);

  dog_ = DogSprite::create();
  dog_->setPosition(ccp(400, 240));
  this->addChild(dog_);
  return true;
}

bool UserLayer::init()
{
  if (!CCLayer::init())
    return false;

  bg_ = CCSprite::create("plank.png");
  bg_->setPosition(ccp(400, 480 - 61));
  this->addChild(bg_, 1);
  return true;
}

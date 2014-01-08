#include "layers.h"

void DogLayer::MenuClickCallback(CCObject* pSender)
{
  int a = 0;
  a++;
}

bool DogLayer::init() {
  if (!CCLayer::init())
    return false;

  bg_ = CCSprite::create("background.png");
  bg_->setPosition(ccp(400, 240));
  this->addChild(bg_);

  dog_ = DogSprite::create();
  dog_->setPosition(ccp(400, 240));
  this->addChild(dog_);

  InitMenuItem();
  /*CCSprite* mail_sprite = CCSprite::create();
  mail_sprite->initWithSpriteFrameName("mail.png");*/

  /*CCMenuItemSprite* mail_item = CCMenuItemSprite::create(
  mail_sprite, mail_sprite, mail_sprite, this, menu_selector(DogLayer::MenuClickCallback));*/
  return true;
}

void DogLayer::InitMenuItem() {
  CCSprite* friend_sprite = CCSprite::create();
  friend_sprite->initWithSpriteFrameName("friend.png");

  CCSprite* step_sprite = CCSprite::create();
  step_sprite->initWithSpriteFrameName("step.png");

  CCSprite* warehouse_sprite = CCSprite::create();
  warehouse_sprite->initWithSpriteFrameName("warehouse.png");

  CCSprite* gold_sprite = CCSprite::create();
  gold_sprite->initWithSpriteFrameName("chest.png");

  CCSprite* shop_sprite = CCSprite::create();
  shop_sprite->initWithSpriteFrameName("shop.png");

  CCSprite* reward_sprite = CCSprite::create();
  reward_sprite->initWithSpriteFrameName("reward.png");

  CCMenuItemSprite* friend_item = CCMenuItemSprite::create(
    friend_sprite, friend_sprite, friend_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  
  CCMenuItemSprite* step_item = CCMenuItemSprite::create(
    step_sprite, step_sprite, step_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* warehouse_item = CCMenuItemSprite::create(
    warehouse_sprite, warehouse_sprite, warehouse_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* gold_item = CCMenuItemSprite::create(
    gold_sprite, gold_sprite, gold_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* shop_item = CCMenuItemSprite::create(
    shop_sprite, shop_sprite, shop_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* reward_item = CCMenuItemSprite::create(
    reward_sprite, reward_sprite, reward_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  main_menu_ = CCMenu::create( friend_item, step_item, warehouse_item,
    gold_item, shop_item, reward_item, NULL);
  main_menu_->setPosition(ccp(0, 0));
  CCPoint base_Position = main_menu_->getPosition();
  int base_x = 350; int base_y = 40; int delt = 80;

  friend_item->setPosition   ( ccp(base_Position.x + 50,   base_Position.y + base_y));
  step_item->setPosition     ( ccp(base_Position.x + base_x + delt*1,  base_Position.y + base_y));
  warehouse_item->setPosition( ccp(base_Position.x + base_x + delt*2,  base_Position.y + base_y));
  gold_item->setPosition     ( ccp(base_Position.x + base_x + delt*3,  base_Position.y + base_y));
  shop_item->setPosition     ( ccp(base_Position.x + base_x + delt*4,  base_Position.y + base_y));
  reward_item->setPosition   ( ccp(base_Position.x + base_x + delt*5,  base_Position.y + base_y));
  //main_menu_->alignItemsVertically();

  addChild(main_menu_);
}

bool UserLayer::init() {
  if (!CCLayer::init())
    return false;

  bg_ = CCSprite::create("plank.png");
  bg_->setPosition(ccp(400, 480 - 61));
  this->addChild(bg_, 1);
  return true;
}

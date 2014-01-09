#include "layers.h"

void DogLayer::MenuClickCallback(CCObject* sender) {
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
  return true;
}

void UserLayer::MenuClickCallback(CCObject* sender) {
  int a = 0;
  a++;
}

bool UserLayer::init() {
  if (!CCLayer::init())
    return false;

  plank_ = CCSprite::create("plank.png");
  plank_->setPosition(ccp(400, 480 - 61));
  this->addChild(plank_, 1);

  CCSprite* mail_sprite = CCSprite::create();
  mail_sprite->initWithSpriteFrameName("mail.png");

  CCMenuItemSprite* mail_item = CCMenuItemSprite::create(
  mail_sprite, mail_sprite, mail_sprite, this, menu_selector(UserLayer::MenuClickCallback));

  mail_menu_ = CCMenu::create( mail_item, NULL);
  mail_menu_->setPosition(ccp(0, 0));
  CCPoint base_Position = mail_menu_->getPosition();
  int base_x = 50; int base_y = 300;

  mail_item->setPosition( ccp(base_Position.x + base_x, base_Position.y + base_y));

  addChild(mail_menu_);
  return true;
}

void MainMenuLayer::MenuClickCallback(CCObject* sender) {

}

bool MainMenuLayer::init() {
  if (!CCLayer::init())
    return false;

  InitMenuItem();

  return true;
}

void MainMenuLayer::InitMenuItem() {
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
    friend_sprite, friend_sprite, friend_sprite, this, menu_selector(MainMenuLayer::MenuClickCallback));
  
  CCMenuItemSprite* step_item = CCMenuItemSprite::create(
    step_sprite, step_sprite, step_sprite, this, menu_selector(MainMenuLayer::MenuClickCallback));

  CCMenuItemSprite* warehouse_item = CCMenuItemSprite::create(
    warehouse_sprite, warehouse_sprite, warehouse_sprite, this, menu_selector(MainMenuLayer::MenuClickCallback));

  CCMenuItemSprite* gold_item = CCMenuItemSprite::create(
    gold_sprite, gold_sprite, gold_sprite, this, menu_selector(MainMenuLayer::MenuClickCallback));

  CCMenuItemSprite* shop_item = CCMenuItemSprite::create(
    shop_sprite, shop_sprite, shop_sprite, this, menu_selector(MainMenuLayer::MenuClickCallback));

  CCMenuItemSprite* reward_item = CCMenuItemSprite::create(
    reward_sprite, reward_sprite, reward_sprite, this, menu_selector(MainMenuLayer::MenuClickCallback));

  menu_ = CCMenu::create( friend_item, step_item, warehouse_item,
    gold_item, shop_item, reward_item, NULL);
  menu_->setPosition(ccp(0, 0));
  CCPoint base_Position = menu_->getPosition();
  int base_x = 350; int base_y = 40; int delt = 80;

  friend_item->setPosition   ( ccp(base_Position.x + 50,   base_Position.y + base_y));
  step_item->setPosition     ( ccp(base_Position.x + base_x + delt*1,  base_Position.y + base_y));
  warehouse_item->setPosition( ccp(base_Position.x + base_x + delt*2,  base_Position.y + base_y));
  gold_item->setPosition     ( ccp(base_Position.x + base_x + delt*3,  base_Position.y + base_y));
  shop_item->setPosition     ( ccp(base_Position.x + base_x + delt*4,  base_Position.y + base_y));
  reward_item->setPosition   ( ccp(base_Position.x + base_x + delt*5,  base_Position.y + base_y));
  //main_menu_->alignItemsVertically();

  addChild(menu_);
}

void DogMenuLayer::MenuClickCallback(CCObject* sender) {
}

bool DogMenuLayer::init() {
  if (!CCLayer::init())
    return false;

  InitMenuItem();
  return true;
}

void DogMenuLayer::InitMenuItem() {
  CCSprite* food_sprite = CCSprite::create();
  food_sprite->initWithSpriteFrameName("food.png");

  CCSprite* train_sprite = CCSprite::create();
  train_sprite->initWithSpriteFrameName("train.png");

  CCSprite* play_sprite = CCSprite::create();
  play_sprite->initWithSpriteFrameName("play.png");

  CCSprite* game_sprite = CCSprite::create();
  game_sprite->initWithSpriteFrameName("game.png");

  CCMenuItemSprite* food_item = CCMenuItemSprite::create(
    food_sprite, food_sprite, food_sprite, this, menu_selector(DogLayer::MenuClickCallback));
  
  CCMenuItemSprite* train_item = CCMenuItemSprite::create(
    train_sprite, train_sprite, train_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* play_item = CCMenuItemSprite::create(
    play_sprite, play_sprite, play_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  CCMenuItemSprite* game_item = CCMenuItemSprite::create(
    game_sprite, game_sprite, game_sprite, this, menu_selector(DogLayer::MenuClickCallback));

  menu_ = CCMenu::create(food_item, train_item, play_item, game_item, NULL);
  menu_->setPosition(ccp(0, 0));
  CCPoint base_Position = menu_->getPosition();
  int base_x = 100; int base_y = 50; int delt = 200;

  food_item->setPosition ( ccp(base_Position.x + base_x,   base_Position.y + base_y));
  train_item->setPosition( ccp(base_Position.x + base_x + delt*1,  base_Position.y + base_y));
  play_item->setPosition ( ccp(base_Position.x + base_x + delt*2,  base_Position.y + base_y));
  game_item->setPosition ( ccp(base_Position.x + base_x + delt*3,  base_Position.y + base_y));

  addChild(menu_);
}

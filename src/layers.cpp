#include "layers.h"
#include "event_mgr.h"
#include "protocol/uiconfig.pb.h"

void DogLayer::MenuClickCallback(CCObject* sender) {
}

bool DogLayer::init() {
  if (!CCLayer::init())
    return false;

  bg_ = CCSprite::create("background.png");
  bg_->setAnchorPoint(ccp(0,0));
  bg_->setPosition(ccp(0, 0));
  this->addChild(bg_);

  dog_ = DogSprite::create();
  dog_->setAnchorPoint(ccp(0,0));
  dog_->setPosition(ccp(400, 240));
  this->addChild(dog_);
  return true;
}

void UserLayer::MailClickCallback(CCObject* sender) {

}

void UserLayer::GoldBarClickCallback(CCObject* sender) {

}

void UserLayer::NameClickCallback(CCObject* sender) {

}

bool UserLayer::init() {
  if (!CCLayer::init())
    return false;

  CCSprite* plank_sprite = CCSprite::create("plank.png");
  plank_sprite->setAnchorPoint(ccp(0,0));
  plank_sprite->setPosition(ccp((800-769)/2, 480-122));
  addChild(plank_sprite);

  CCSprite* gold_bar_sprite = CCSprite::create();
  gold_bar_sprite->initWithSpriteFrameName("gold_bar.png");
  CCMenuItemSprite* gold_bar_item = CCMenuItemSprite::create(
    gold_bar_sprite, gold_bar_sprite, gold_bar_sprite, this, menu_selector(UserLayer::GoldBarClickCallback));
  gold_bar_item->setAnchorPoint(ccp(0,0));
  gold_bar_item->setPosition(ccp(335,67));

  char num[32] = {0};
  snprintf(num,sizeof(num),"%d", 10241024);
  gold_num_ = CCLabelTTF::create( num, "Arial", 24);
  CCSize size = gold_num_->getContentSize();
  //gold_num_->setAnchorPoint(ccp(size.width, 0));
  gold_num_->setAnchorPoint(ccp(0, 0));
  gold_num_->setPosition(ccp(90, 4));
  gold_bar_item->addChild(gold_num_, 3);

  CCSprite* achievement_sprite = CCSprite::create();
  achievement_sprite->initWithSpriteFrameName("down.png");
  CCMenuItemSprite* achievement_item = CCMenuItemSprite::create(
    achievement_sprite, achievement_sprite, achievement_sprite, 
    this, menu_selector(UserLayer::GoldBarClickCallback));
  achievement_item->setAnchorPoint(ccp(0,0));
  achievement_item->setPosition(ccp(287,62));

  char achievement_str[32] = {0};
  snprintf(achievement_str,sizeof(achievement_str),"%s", "吉娃娃饲养家");
  CCLabelTTF* achievement_desc = CCLabelTTF::create( achievement_str, "Arial", 20);
  achievement_desc->setAnchorPoint(ccp(0, 0));
  achievement_desc->setPosition(ccp(150, 62));
  plank_sprite->addChild(achievement_desc, 3);

  char name_str[32] = {0};
  snprintf(name_str,sizeof(name_str),"%s", "clowl");
  CCLabelTTF* name_desc = CCLabelTTF::create( name_str, "Arial", 20);
  name_desc->setAnchorPoint(ccp(0, 0));
  name_desc->setPosition(ccp(150, 92));
  plank_sprite->addChild(name_desc, 3);

  CCSprite* heart_bar = CCSprite::create();
  heart_bar->initWithSpriteFrameName("like_bar.png");
  heart_bar->setAnchorPoint(ccp(0,0));
  heart_bar->setPosition(ccp(610, 67));
  plank_sprite->addChild(heart_bar, 2);

  CCSprite* heart = CCSprite::create();
  heart->initWithSpriteFrameName("like.png");
  heart->setAnchorPoint(ccp(0,0));
  heart->setPosition(ccp(-15, 0));
  heart_bar->addChild(heart, 2);

  heart_progress_bar_.SetMaxNum(2000);
  heart_progress_bar_.CreateSprite(heart_bar);
  heart_progress_bar_.SetHeartProgressBar(1000);

  CCSprite* mail_sprite = CCSprite::create();
  mail_sprite->initWithSpriteFrameName("mail.png");

  CCMenuItemSprite* mail_item = CCMenuItemSprite::create(
  mail_sprite, mail_sprite, mail_sprite, this, menu_selector(UserLayer::MailClickCallback));
  mail_item->setAnchorPoint(ccp(0,0));
  mail_item->setPosition(ccp(0, -80));

  menu_ = CCMenu::create(mail_item, gold_bar_item, achievement_item, NULL);
  menu_->setAnchorPoint(ccp(0, 0));
  menu_->setPosition(ccp(0, 0));
  plank_sprite->addChild(menu_, 1);
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
  // CCPoint base_Position = menu_->getPosition();
  int base_x = 350; int base_y = 40; int delt = 80;

  friend_item->setPosition   ( ccp(50,   base_y));
  step_item->setPosition     ( ccp(base_x + delt*1,  base_y));
  warehouse_item->setPosition( ccp(base_x + delt*2,  base_y));
  gold_item->setPosition     ( ccp(base_x + delt*3,  base_y));
  shop_item->setPosition     ( ccp(base_x + delt*4,  base_y));
  reward_item->setPosition   ( ccp(base_x + delt*5,  base_y));
  //main_menu_->alignItemsVertically();

  addChild(menu_);
}

void DogMenuLayer::FoodItemClickCallback(CCObject* sender) {
}

void DogMenuLayer::TrainItemClickCallback(CCObject* sender) {
  EventMgr::Instance().Response(2);
}

void DogMenuLayer::PlayItemClickCallback(CCObject* sender) {
  EventMgr::Instance().Response(3);
}

void DogMenuLayer::GameItemClickCallback(CCObject* sender) {
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
    food_sprite, food_sprite, food_sprite, this, menu_selector(DogMenuLayer::FoodItemClickCallback));
  
  CCMenuItemSprite* train_item = CCMenuItemSprite::create(
    train_sprite, train_sprite, train_sprite, this, menu_selector(DogMenuLayer::TrainItemClickCallback));

  CCMenuItemSprite* play_item = CCMenuItemSprite::create(
    play_sprite, play_sprite, play_sprite, this, menu_selector(DogMenuLayer::PlayItemClickCallback));

  CCMenuItemSprite* game_item = CCMenuItemSprite::create(
    game_sprite, game_sprite, game_sprite, this, menu_selector(DogMenuLayer::GameItemClickCallback));

  menu_ = CCMenu::create(food_item, train_item, play_item, game_item, NULL);
  menu_->setAnchorPoint(ccp(0, 0));
  menu_->setPosition(ccp(0, 0));

  int base_x = 8; int base_y = 10; int delt = 18; int last_item_x = 0;

  food_item->setAnchorPoint(ccp(0, 0));
  food_item->setPosition ( ccp(base_x, base_y));

  last_item_x = (int)food_item->getContentSize().width + delt;
  train_item->setAnchorPoint(ccp(0, 0));
  train_item->setPosition( ccp(base_x + last_item_x, base_y));

  last_item_x += (int)train_item->getContentSize().width + delt;
  play_item->setAnchorPoint(ccp(0, 0));
  play_item->setPosition ( ccp(base_x + last_item_x, base_y));

  last_item_x += (int)play_item->getContentSize().width + delt;
  game_item->setAnchorPoint(ccp(0, 0));
  game_item->setPosition ( ccp(base_x + last_item_x, base_y));

  addChild(menu_);
}

void TrainMenuLayer::BackItemClickCallback(CCObject* sender) {
  EventMgr::Instance().Response(4);
}

void TrainMenuLayer::Train1ItemClickCallback(CCObject* sender) {
}

void TrainMenuLayer::Train2ItemClickCallback(CCObject* sender) {
}

void TrainMenuLayer::Train3ItemClickCallback(CCObject* sender) {
}

void TrainMenuLayer::Train4ItemClickCallback(CCObject* sender) {
}

bool TrainMenuLayer::init() {
  if (!CCLayer::init())
    return false;

  InitMenuItem();
  return true;
}

void TrainMenuLayer::InitMenuItem() {
  
  CCSprite* back_sprite = CCSprite::create();
  back_sprite->initWithSpriteFrameName("back.png");

  CCSprite* train1_sprite = CCSprite::create();
  train1_sprite->initWithSpriteFrameName("white.png");

  CCSprite* train2_sprite = CCSprite::create();
  train2_sprite->initWithSpriteFrameName("white.png");

  CCSprite* train3_sprite = CCSprite::create();
  train3_sprite->initWithSpriteFrameName("white.png");

  CCSprite* train4_sprite = CCSprite::create();
  train4_sprite->initWithSpriteFrameName("white.png");

  CCMenuItemSprite* back_item = CCMenuItemSprite::create(
    back_sprite, back_sprite, back_sprite, this, menu_selector(TrainMenuLayer::BackItemClickCallback));
  
  FSMenuItem* train1_item = FSMenuItem::create(
    train1_sprite, train1_sprite, train1_sprite, this, menu_selector(TrainMenuLayer::Train1ItemClickCallback));
  train1_item->InitData(dogrun2::kItemTrain, 0);

  FSMenuItem* train2_item = FSMenuItem::create(
    train2_sprite, train2_sprite, train2_sprite, this, menu_selector(TrainMenuLayer::Train2ItemClickCallback));
  train2_item->InitData(dogrun2::kItemTrain, 1);

  FSMenuItem* train3_item = FSMenuItem::create(
    train3_sprite, train3_sprite, train3_sprite, this, menu_selector(TrainMenuLayer::Train3ItemClickCallback));
  train3_item->InitData(dogrun2::kItemTrain, 2);

  FSMenuItem* train4_item = FSMenuItem::create(
    train4_sprite, train4_sprite, train4_sprite, this, menu_selector(TrainMenuLayer::Train4ItemClickCallback));
  train4_item->InitData(dogrun2::kItemTrain, 3);

  menu_ = CCMenu::create(back_item, train1_item, train2_item, train3_item, train4_item, NULL);
  menu_->setAnchorPoint(ccp(0, 0));
  menu_->setPosition(ccp(0, 0));

  int base_x = 15; int base_y = 10; int delt = 35; int last_item_x = 0;

  back_item->setAnchorPoint(ccp(0, 0));
  back_item->setPosition(ccp(base_x, base_y));

  last_item_x += (int)back_item->getContentSize().width + delt;
  train1_item->setAnchorPoint(ccp(0, 0));
  train1_item->setPosition(ccp(base_x + last_item_x, base_y));

  last_item_x += (int)train1_item->getContentSize().width + delt;
  train2_item->setAnchorPoint(ccp(0, 0));
  train2_item->setPosition(ccp(base_x + last_item_x, base_y));

  last_item_x += (int)train2_item->getContentSize().width + delt;
  train3_item->setAnchorPoint(ccp(0, 0));
  train3_item->setPosition(ccp(base_x + last_item_x, base_y));

  last_item_x += (int)train3_item->getContentSize().width + delt;
  train4_item->setAnchorPoint(ccp(0, 0));
  train4_item->setPosition(ccp(base_x + last_item_x, base_y));

  addChild(menu_);
}

void PlayMenuLayer::BackItemClickCallback(CCObject* sender) {
  EventMgr::Instance().Response(4);
}

void PlayMenuLayer::WalkItemClickCallback(CCObject* sender) {
}

void PlayMenuLayer::TouchItemClickCallback(CCObject* sender) {
}

void PlayMenuLayer::BallItemClickCallback(CCObject* sender) {
}

void PlayMenuLayer::FrisbeeItemClickCallback(CCObject* sender) {
}

bool PlayMenuLayer::init() {
  if (!CCLayer::init())
    return false;

  InitMenuItem();
  return true;
}

void PlayMenuLayer::InitMenuItem() {
  
  CCSprite* back_sprite = CCSprite::create();
  back_sprite->initWithSpriteFrameName("back.png");

  CCSprite* walk_sprite = CCSprite::create();
  walk_sprite->initWithSpriteFrameName("white.png");

  CCSprite* touch_sprite = CCSprite::create();
  touch_sprite->initWithSpriteFrameName("white.png");

  CCSprite* ball_sprite = CCSprite::create();
  ball_sprite->initWithSpriteFrameName("white.png");

  CCSprite* frisbee_sprite = CCSprite::create();
  frisbee_sprite->initWithSpriteFrameName("white.png");

  CCMenuItemSprite* back_item = CCMenuItemSprite::create(
    back_sprite, back_sprite, back_sprite, this, menu_selector(PlayMenuLayer::BackItemClickCallback));
  
  FSMenuItem* walk_item = FSMenuItem::create(
    walk_sprite, walk_sprite, walk_sprite, this, menu_selector(PlayMenuLayer::WalkItemClickCallback));
  walk_item->InitData(dogrun2::kItemPlay, 0);

  FSMenuItem* touch_item = FSMenuItem::create(
    touch_sprite, touch_sprite, touch_sprite, this, menu_selector(PlayMenuLayer::TouchItemClickCallback));
  touch_item->InitData(dogrun2::kItemPlay, 1);
  
  FSMenuItem* ball_item = FSMenuItem::create(
    ball_sprite, ball_sprite, ball_sprite, this, menu_selector(PlayMenuLayer::BallItemClickCallback));
  ball_item->InitData(dogrun2::kItemPlay, 2);

  FSMenuItem* frisbee_item = FSMenuItem::create(
    frisbee_sprite, frisbee_sprite, frisbee_sprite, this, menu_selector(PlayMenuLayer::FrisbeeItemClickCallback));
  frisbee_item->InitData(dogrun2::kItemPlay, 3);

  menu_ = CCMenu::create(back_item, walk_item, touch_item, ball_item, frisbee_item, NULL);
  menu_->setAnchorPoint(ccp(0, 0));
  menu_->setPosition(ccp(0, 0));

  int base_x = 15; int base_y = 10; int delt = 35; int last_item_x = 0;

  back_item->setAnchorPoint(ccp(0, 0));
  back_item->setPosition(ccp(base_x, base_y));

  last_item_x += (int)back_item->getContentSize().width + delt;
  walk_item->setAnchorPoint(ccp(0, 0));
  walk_item->setPosition(ccp(base_x + last_item_x, base_y));

  last_item_x += (int)walk_item->getContentSize().width + delt;
  touch_item->setAnchorPoint(ccp(0, 0));
  touch_item->setPosition(ccp(base_x + last_item_x, base_y));

  last_item_x += (int)touch_item->getContentSize().width + delt;
  ball_item->setAnchorPoint(ccp(0, 0));
  ball_item->setPosition(ccp(base_x + last_item_x, base_y));

  last_item_x += (int)ball_item->getContentSize().width + delt;
  frisbee_item->setAnchorPoint(ccp(0, 0));
  frisbee_item->setPosition(ccp(base_x + last_item_x, base_y));

  addChild(menu_);
}

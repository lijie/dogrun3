#pragma once
#include "cocos2d.h"
#include "sprites.h"
#include "menu_items.h"

USING_NS_CC;

class DogLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(DogLayer);

  void MenuClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCSprite *bg_;
  DogSprite *dog_;
};

class DogMenuLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(DogMenuLayer);

  void FoodItemClickCallback(CCObject* sender);
  void TrainItemClickCallback(CCObject* sender);
  void PlayItemClickCallback(CCObject* sender);
  void GameItemClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCMenu *menu_;
};

class MainMenuLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(MainMenuLayer);

  void MenuClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCMenu *menu_;
};

class TrainMenuLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(TrainMenuLayer);

  void BackItemClickCallback(CCObject* sender);
  void Train1ItemClickCallback(CCObject* sender);
  void Train2ItemClickCallback(CCObject* sender);
  void Train3ItemClickCallback(CCObject* sender);
  void Train4ItemClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCMenu *menu_;
};

class PlayMenuLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(PlayMenuLayer);

  void BackItemClickCallback(CCObject* sender);
  void WalkItemClickCallback(CCObject* sender);
  void TouchItemClickCallback(CCObject* sender);
  void BallItemClickCallback(CCObject* sender);
  void FrisbeeItemClickCallback(CCObject* sender);

protected:
  void InitMenuItem();

protected:
  CCMenu *menu_;
};

class UserLayer : public CCLayer {
public:
  virtual bool init();
  CREATE_FUNC(UserLayer);
  void MailClickCallback(CCObject* sender);
protected:
  CCSprite *plank_;
  CCMenu *mail_menu_;
};


#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"
#include "Hero.h"
#include "MonsterController.h"
USING_NS_CC;

class GameScene : public Layer
{
public:
	GameScene();
	~GameScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	virtual void update(float delta);
	void callback_jump(Node *sender);
	bool onTouchBegan(Touch *touch, Event *event);
private:
	
	Sprite *bg1, *bg2, *bg3, *bg4, *bg5, *bg6;
	void moveBG(Sprite *background1, Sprite *background2, float speed, float delta);
	void initBG();
	Hero *hero;
	Sprite *heroShip;
	MonsterController *monsterController;
};
#endif
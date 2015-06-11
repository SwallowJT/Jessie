#ifndef _STARTSCENE_H_
#define _STARTSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class StartScene : public CCLayer
{
public:
	StartScene();
	~StartScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StartScene);

	virtual void update(float delta);
	void menuCallback(Ref *sender);//Options
	void menuCallback2(Ref *sender);//More
	void menuCallback3(Ref *sender);//EjectButton
private:
	Sprite *bg1, *bg2, *bg3, *bg4, *bg5, *bg6;
	void moveBG(Sprite *background1, Sprite *background2, float speed,float delta);
	void initBG();

};

#endif
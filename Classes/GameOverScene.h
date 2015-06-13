#ifndef _GAMEOVER_SCENE_H_
#define _GAMEOVER_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class GameOverScene : public Layer
{
public:
	static Scene*  createScene();
	virtual bool init();
	CREATE_FUNC(GameOverScene);
	void initBG();
	bool reStart(Touch *touch, Event *event);
private:
	Sprite *bg1, *bg2, *bg3, *bg4, *bg5, *bg6;
};
#endif
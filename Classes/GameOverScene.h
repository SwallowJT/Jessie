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
};
#endif
#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "cocos2d.h"
#include "Entity.h"
#include "Hero.h"
USING_NS_CC;

class Monster : public Entity
{
public:
	virtual bool init();
	CREATE_FUNC(Monster);
	bool isShow;
	bool isCollideWithHero(Hero *hero);
};
#endif
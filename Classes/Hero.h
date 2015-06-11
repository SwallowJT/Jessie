#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Hero : public Entity
{
public:
	Hero();
	~Hero();
	virtual bool init();
	CREATE_FUNC(Hero);
	bool getIsTouch();
	void setIsTouch(bool aa);
	bool getisAlive();
	void setIsAlive(bool bb);
private:
	bool isAlive;
	bool isTouch;
};

#endif
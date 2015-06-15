#ifndef _GATE_H_
#define _GATE_H_

#include "cocos2d.h"
#include "Entity.h"
#include "Hero.h"

USING_NS_CC;

class Gate : public Entity
{
public:
	Gate();
	~Gate();
	virtual bool init();
	CREATE_FUNC(Gate);
	bool isCollideWithHero(Hero *hero);
	bool isShow;
	void laser1();//������˸����
	void laser2();//������ʧ����
	bool isValid;
};

#endif
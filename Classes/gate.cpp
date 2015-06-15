#include "gate.h"

Gate::Gate()
{

}

Gate::~Gate()
{

}

bool Gate::init()
{
	//不在init里创建精灵然后赋值给成员变量，而是使用父类的bindSprite方法，
	//因为它封装了为Node添加Contentsize的方法，使得我们可以使用Gate对象
	//进行碰撞检测
	if (!Entity::init())
	{
		return false;
	}
	isValid = true;
	
	return true;
}

void Gate::laser1()
{
	Animation *animation = Animation::create();
	for (int i = 1; i < 5; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "gate-static%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	animation->setDelayPerUnit(1.5);
	animation->setRestoreOriginalFrame(true);
	Animate *action = Animate::create(animation);
	getSprite()->runAction(RepeatForever::create(action));

}

void Gate::laser2()
{
	Animation *animation = Animation::create();
	for (int i = 1; i < 4; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "gate-boom%d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	animation->setDelayPerUnit(1.5);
	animation->setRestoreOriginalFrame(true);
	Animate *action = Animate::create(animation);
	getSprite()->runAction(action);
	
}

bool Gate::isCollideWithHero(Hero *hero)
{
	Rect rect = this->getBoundingBox();
	Vec2 point = hero->getPosition();
	if (rect.containsPoint(point) && this->isValid)
	{
		return true;
	}
	return false;
}



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
	return true;
}

void Gate::laser1()
{
	Animation *animation = Animation::create();
	for (int i = 2; i < 4; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "spike%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->spriteFrameByName(szName));
	}
	animation->setDelayPerUnit(0.5);
	animation->setRestoreOriginalFrame(true);
	Animate *action = Animate::create(animation);
	getSprite()->runAction(RepeatForever::create(action));
}

void Gate::laser2()
{

}

bool Gate::isCollideWithHero(Hero *hero)
{
	Rect rect = hero->getBoundingBox();
	Vec2 point = getSprite()->getPosition();
	if (rect.containsPoint(point))
	{
		return false;
	}
	return true;
}



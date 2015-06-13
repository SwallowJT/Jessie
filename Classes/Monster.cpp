#include "Monster.h"

bool Monster::init()
{
	return true;
}

bool Monster::isCollideWithHero(Hero *hero)
{
	if (hero->getisAlive())
	{
		Rect rect = hero->getBoundingBox();
		Vec2 point = Vec2(this->getBoundingBox().getMidX(),this->getBoundingBox().getMidY());//得到的是障碍物的左下角，因为锚点在左下角（Node）this->getPosition();
		if (rect.containsPoint(point))
		{
			return true;
		}
	}
	return false;
}

void Monster::blink()
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
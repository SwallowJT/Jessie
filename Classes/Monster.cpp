#include "Monster.h"

bool Monster::init()
{
	isShow = false;

	return true;
}

bool Monster::isCollideWithHero(Hero *hero)
{
	if (hero->getisAlive())
	{
		Rect rect = hero->getBoundingBox();
		Vec2 point = this->getPosition();
		if (rect.containsPoint(point))
		{
			return true;
		}
	}
	return false;
}
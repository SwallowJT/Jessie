#include "Entity.h"

Sprite* Entity::getSprite()
{
	return sprite;
}

void Entity::bindSprite(Sprite *sp)
{
	sprite = sp;
	this->addChild(sp);
	Size contentsize = sp->getContentSize();
	sp->setPosition(Vec2(contentsize.width / 2, contentsize.height / 2));
	this->setContentSize(contentsize);
}
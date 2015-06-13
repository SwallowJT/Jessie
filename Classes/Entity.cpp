#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

bool Entity::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}

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
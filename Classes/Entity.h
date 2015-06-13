#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "cocos2d.h"
USING_NS_CC;

class Entity : public Node
{
public:
	Entity();
	~Entity();
	virtual bool init();
	CREATE_FUNC(Entity);
	Sprite* getSprite();
	void bindSprite(Sprite *sp);
private:
	Sprite *sprite;
};

#endif
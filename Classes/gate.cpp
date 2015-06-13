#include "gate.h"

Gate::Gate()
{

}

Gate::~Gate()
{

}

bool Gate::init()
{
	//����init�ﴴ������Ȼ��ֵ����Ա����������ʹ�ø����bindSprite������
	//��Ϊ����װ��ΪNode���Contentsize�ķ�����ʹ�����ǿ���ʹ��Gate����
	//������ײ���
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



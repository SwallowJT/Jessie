#include "MonsterController.h"
#include "GameOverLayer.h"

#define MAX_MONSTER 5

bool MonsterController::init()
{
	createMonsters();
	this->scheduleUpdate();
	return true;
}

void MonsterController::createMonsters()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Monster *monster = NULL;
	for (int i = 0; i < MAX_MONSTER;i++)
	{
		monster = Monster::create();
		monster->bindSprite(Sprite::createWithSpriteFrameName("spike.png"));
		monster->setPosition(Vec2(visibleSize.width + CCRANDOM_0_1() * 2000, visibleSize.height * CCRANDOM_0_1()));
		this->addChild(monster,1);
		m_monster.pushBack(monster);
	}
}

void MonsterController::update(float delta)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (Monster *monster : m_monster)
	{
		if (monster->isShow)
		{
			monster->setPositionX(monster->getPositionX() - delta * 300);
			if (monster->getPositionX() < 0)
			{
				monster->setPosition(Vec2(visibleSize.width + CCRANDOM_0_1() * 2000, visibleSize.height * CCRANDOM_0_1()));
				monster->isShow = false;
			}

			if (m_hero->getisAlive())
			{
				if (monster->isCollideWithHero(m_hero))
				{
					m_hero->stopAllActions();
					m_hero->setVisible(false);
					m_hero->setIsAlive(false);
				}
			}
		}
		else
		{
			monster->isShow = true;
		}
	}
}

void MonsterController::bindHero(Hero *hero)
{
	m_hero = hero;
}
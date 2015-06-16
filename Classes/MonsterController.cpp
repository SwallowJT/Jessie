#include "MonsterController.h"
#include "GameOverScene.h"

#define MAX_MONSTER 3

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
		monster->blink();
		
		monster->setPosition(Vec2(visibleSize.width + CCRANDOM_0_1() * visibleSize.width, visibleSize.height * CCRANDOM_0_1()));
		this->addChild(monster,1);
		m_monster.pushBack(monster);
	}
}

void MonsterController::update(float delta)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (Monster *monster : m_monster)
	{
		monster->setPositionX(monster->getPositionX() - delta * 300);
		if (monster->getPositionX() < 0)
		{
			monster->setPosition(Vec2(visibleSize.width + CCRANDOM_0_1() * 2000, visibleSize.height * CCRANDOM_0_1()));
		}

		if (m_hero->getisAlive())
		{
			if (monster->isCollideWithHero(m_hero))
			{
				this->unscheduleUpdate();
 				m_hero->stopAllActions();
 				m_hero->setVisible(false);
 				monster->setVisible(false);
				auto baozha = Sprite::create("Explosion1.png");
				this->addChild(baozha, 1);
				baozha->setPosition(Vec2(monster->getBoundingBox().getMidX(), monster->getBoundingBox().getMidY()));
				Director::getInstance()->replaceScene(TransitionFlipAngular::create(2, GameOverScene::createScene(), TransitionScene::Orientation::LEFT_OVER));
			}
		}
	}
}


void MonsterController::bindHero(Hero *hero)
{
	m_hero = hero;
}
#include "MonsterController.h"
#include "GameOverScene.h"

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
		monster->blink();
		//将blink的代码放在这里不行

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
					monster->setVisible(false);
					auto baozha = Sprite::create("Explosion1.png");
					this->addChild(baozha, 1);
					baozha->setPosition(Vec2(monster->getBoundingBox().getMidX(), monster->getBoundingBox().getMidY()));
					auto action1 = Blink::create(0.5, 1);
					auto action = Sequence::create(action1, CallFuncN::create(CC_CALLBACK_1(MonsterController::replace_scene, this)), nullptr);
					baozha->runAction(action);
					
				}
			}
		}
		else
		{
			monster->isShow = true;
		}
	}
}

void MonsterController::replace_scene(Node *node)
{
	Director::getInstance()->replaceScene(GameOverScene::createScene());
}

void MonsterController::bindHero(Hero *hero)
{
	m_hero = hero;
}
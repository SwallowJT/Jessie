#include "GateController.h"

#define  max_gate 3



GateController::GateController()
{
	score = 0;
}

GateController::~GateController()
{

}

bool GateController::init()
{
	if (!Node::init())
	{
		return false;
	}
	createGates();

	this->scheduleUpdate();

	

	return true;
}

void GateController::bindHero(Hero *hero)
{
	m_hero = hero;
}


void GateController::createGates()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
   	Gate *gate = NULL;
 	for (int i = 0; i < max_gate; i++)
 	{
 		gate = Gate::create();
 		gate->bindSprite(Sprite::create("gate-static1.png"));
 		gate->laser1();
 		this->addChild(gate,1);
 		gate->setPosition(Vec2(CCRANDOM_0_1() * visibleSize.width ,CCRANDOM_0_1() * visibleSize.height));
 		m_gates.pushBack(gate);
 	}
}

void GateController::update(float delta)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (Gate *gate : m_gates)
	{
		gate->setPositionX(gate->getPositionX() - delta * 200);
		if (gate->isCollideWithHero(m_hero) && gate->isValid)
		{
			//执行动画的精灵需要纹理，但是动画已经包含了很多纹理，当我停止所有动画，显示在屏幕上的是精灵的纹理，还是某一帧动画
			gate->getSprite()->stopAllActions();
			//gate->getSprite()->setVisible(false);
			gate->isValid = false;
			score++;
			gate->laser2();
		}
		if (gate->getPosition().x < 0 )
		{
			//+run action mentioned upon
			gate->setPosition(Vec2(CCRANDOM_0_1() * visibleSize.width + visibleSize.width,CCRANDOM_0_1() * visibleSize.height));
			if (gate->isValid == false)
			{
				gate->isValid = true;
			}
			gate->getSprite()->stopAllActions();
			gate->laser1();
		}
	}
}

int GateController::getScore()
{
	return score;
}
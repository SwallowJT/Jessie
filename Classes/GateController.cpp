#include "GateController.h"

#define  max_gate 3



GateController::GateController()
{

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
		gate->bindSprite(Sprite::create("gate.png"));
		gate->laser1();
		gate->setPosition(Vec2(visibleSize.width + CCRANDOM_0_1() * visibleSize.width, visibleSize.height * CCRANDOM_0_1()));
		this->addChild(gate,1);
		m_gates.pushBack(gate);
	}
}

void GateController::update(float delta)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (auto gate : m_gates)
	{
		gate->setPositionX(gate->getPositionX() - delta * 200);
		if (gate->isCollideWithHero(m_hero))
		{
 			
 			gate->laser2();
		}
		if (gate->getPosition().x < 0 )
		{
			//+run action mentioned upon
			gate->setPosition(Vec2(visibleSize.width + CCRANDOM_0_1() * visibleSize.width, visibleSize.height * CCRANDOM_0_1()));
 			gate->setVisible(true);
			gate->laser1();
		}
	}
}
#include "GateController.h"
#include "GameScene.h"

#define  max_gate 3

int GateController::score = 0;

GateController::GateController()
{
	//score = 0;
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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto blockSize = Size(visibleSize.width / 2, 200);
	scoreLabel = Label::createWithSystemFont("Score : 0", "Abduction.ttf", 25, blockSize,
		TextHAlignment::CENTER, TextVAlignment::CENTER);
	scoreLabel->setAnchorPoint(Vec2(0, 0.5));
	scoreLabel->setPosition(Vec2(blockSize.width, visibleSize.height * 2 / 3));
	this->addChild(scoreLabel, 3);

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
			//ִ�ж����ľ�����Ҫ�������Ƕ����Ѿ������˺ܶ���������ֹͣ���ж�������ʾ����Ļ�ϵ��Ǿ������������ĳһ֡����
			gate->getSprite()->stopAllActions();
			gate->isValid = false;
			score++;
			this->updateScore(score);
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

void GateController::updateScore(int score)
{
	char scoreNum[100] = { 0 };
	sprintf(scoreNum, "score : %d", score);
	scoreLabel->setString(std::string(scoreNum));
}
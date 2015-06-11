#include "GameOverLayer.h"



bool GameOverLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto size = Director::getInstance()->getVisibleSize();
	auto blockSize = Size(size.width / 3, 200);
	auto gameOver = Label::createWithSystemFont("GAME OVER", "Abduction.ttf", 50, blockSize,
		TextHAlignment::CENTER, TextVAlignment::CENTER);
	gameOver->setAnchorPoint(Vec2(0, 0.5));
	gameOver->setPosition(blockSize.width, size.height / 2);

	this->addChild(gameOver);

	return true;
}


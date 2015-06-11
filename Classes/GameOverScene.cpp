#include "GameOverScene.h"

Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameOverScene::init()
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
	gameOver->setPosition(Vec2(blockSize.width, size.height / 2));
	this->addChild(gameOver);

	return true;
}


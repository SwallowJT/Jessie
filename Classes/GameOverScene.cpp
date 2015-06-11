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
	this->addChild(gameOver,3);

	initBG();

	return true;
}

void GameOverScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//as sky without stars
	auto layerBlack = LayerColor::create(Color4B(0, 0, 0, 255));
	layerBlack->setPosition(Vec2(0, 0));
	this->addChild(layerBlack, 0);

	//background1(2) use "mars-bg1.png"
	bg1 = Sprite::create("mars-bg1.png");
	bg2 = Sprite::create("mars-bg1.png");
	Size bgSize = bg1->getContentSize();
	bg1->setScale(visibleSize.width / bgSize.width, visibleSize.height / bgSize.height);
	bg2->setScale(visibleSize.width / bgSize.width, visibleSize.height / bgSize.height);
	bg1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	bg2->setPosition(Vec2(visibleSize.width * 3 / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg1, 3);
	this->addChild(bg2, 3);

	//background3(4) use "mars-bg2.png"
	bg3 = Sprite::create("mars-bg2.png");
	bg4 = Sprite::create("mars-bg2.png");
	Size bg3Size = bg3->getContentSize();
	bg3->setScale(visibleSize.width / bg3Size.width, visibleSize.height / bg3Size.height);
	bg4->setScale(visibleSize.width / bg3Size.width, visibleSize.height / bg3Size.height);
	bg3->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	bg4->setPosition(Vec2(visibleSize.width * 3 / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg3, 2);
	this->addChild(bg4, 2);

	//background3(4) use "Stars.png"
	bg5 = Sprite::create("Stars-hd.png");
	bg6 = Sprite::create("Stars-hd.png");
	Size bg5Size = bg5->getContentSize();
	bg5->setScale(visibleSize.width / bg5Size.width, visibleSize.height / bg5Size.height);
	bg6->setScale(visibleSize.width / bg5Size.width, visibleSize.height / bg5Size.height);
	bg5->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	bg6->setPosition(Vec2(visibleSize.width * 3 / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg5, 1);
	this->addChild(bg6, 1);
}



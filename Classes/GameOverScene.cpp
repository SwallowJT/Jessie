#include "GameOverScene.h"
#include "GameScene.h"
#include "GateController.h"

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

	int score = GateController::score;
	log("score = %d", score);

	auto size = Director::getInstance()->getVisibleSize();
	auto blockSize = Size(size.width / 3, 200);
	auto gameOver = Label::createWithSystemFont("GAME OVER", "Abduction.ttf", 35, blockSize,
		TextHAlignment::CENTER, TextVAlignment::CENTER);
	gameOver->setAnchorPoint(Vec2(0, 0.5));
	gameOver->setPosition(Vec2(blockSize.width, size.height * 2 / 3));
	this->addChild(gameOver,3);

	char szName[100];
	sprintf(szName, "your score : %d", score);
	auto m_score = Label::createWithSystemFont(szName, "Abduction.ttf", 15, blockSize,
		TextHAlignment::CENTER, TextVAlignment::CENTER);
	m_score->setAnchorPoint(Vec2(0, 0.5));
	m_score->setPosition(Vec2(blockSize.width, size.height * 5 / 12));
	this->addChild(m_score, 3);

	int highestScore = UserDefault::getInstance()->getIntegerForKey("highestScore");
	if (score > highestScore)
	{
		UserDefault::getInstance()->setIntegerForKey("highestScore", score);
		UserDefault::getInstance()->flush();//一定不要忘了，否则数据修改不会写入xml中
		highestScore = score;
	}

	char szName2[100];
	sprintf(szName2, "highest score : %d", highestScore);
	auto highest_score = Label::createWithSystemFont(szName2, "Abduction.ttf", 15, blockSize,
		TextHAlignment::CENTER, TextVAlignment::CENTER);
	highest_score->setAnchorPoint(Vec2(0, 0.5));
	highest_score->setPosition(Vec2(blockSize.width, size.height / 4));
	this->addChild(highest_score, 3);

	//重置分数
	GateController::score = 0;

	initBG();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameOverScene::reStart, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

bool GameOverScene::reStart(Touch *touch, Event *event)
{
	Director::getInstance()->replaceScene(TransitionFadeTR::create(1.2,GameScene::createScene()));
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



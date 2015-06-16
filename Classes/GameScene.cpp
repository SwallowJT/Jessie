#include "GameScene.h"
#include "GameOverScene.h"

#define bg1Speed 500
#define bg3Speed 400
#define bg5Speed 300

GameScene::GameScene()
{
	light_score = 0;
	boom_score = 0;
}

GameScene::~GameScene()
{

}

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	//创建场景中其他层（UI）应该是使用这种方式吧
	// 	auto gameoverLayer = GameOverLayer::create();
	// 	scene->addChild(gameoverLayer, 0);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}


	this->scheduleUpdate();

	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("MainSpriteSheet.plist", "MainSpriteSheet.png");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//background
	initBG();

	//ship falldown and hero jump forever
	heroShip = Sprite::create("Ship1.png");
	this->addChild(heroShip);
	heroShip->setPosition(Vec2(100, visibleSize.height / 2));
	auto fallDown = MoveTo::create(1, Vec2(100, 50));
	auto action = Sequence::create(fallDown, CallFuncN::create(CC_CALLBACK_1(GameScene::callback_jump, this)), nullptr);
	heroShip->runAction(action);

	
	//hero
	hero = Hero::create();
	hero->bindSprite(Sprite::createWithSpriteFrameName("jet4.png"));
	hero->setScale(2);
	hero->setPosition(Vec2(100, 50));
	this->addChild(hero, 3);
	hero->setVisible(false);

	//monsters added in monstercontroller
	monsterController = MonsterController::create();
	this->addChild(monsterController, 2);
	monsterController->bindHero(hero);

	//gates added in gatecontroller
	gateController = GateController::create();
	this->addChild(gateController, 2);
	gateController->bindHero(hero);

	//add score  交给gatecontroller处理
	/*
	auto blockSize = Size(visibleSize.width /2, 200);
	scoreLabel= Label::createWithSystemFont("Score : 0", "Abduction.ttf", 25, blockSize,
		TextHAlignment::CENTER, TextVAlignment::CENTER);
	scoreLabel->setAnchorPoint(Vec2(0, 0.5));
	scoreLabel->setPosition(Vec2(blockSize.width, visibleSize.height * 2 / 3));
	this->addChild(scoreLabel, 3);
	*/

	//touch event
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void GameScene::callback_jump(Node *sender)
{
	if (hero->getIsTouch())
	{
		hero->setIsTouch(false);
	}
	heroShip->setVisible(false);
	hero->setVisible(true);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	auto move = MoveBy::create(0.5, Vec2(0, visibleSize.height  - 150));
	auto move_ease_in = EaseOut::create(move, 2.0);
	auto move_ease_in_back = move_ease_in->reverse();
	auto jump = Sequence::create(move_ease_in, move_ease_in_back, nullptr);
	auto repeat = RepeatForever::create(jump);
	hero->runAction(repeat);
}

void GameScene::initBG()
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

void GameScene::update(float delta)
{
	moveBG(bg1, bg2, bg1Speed, delta);
	moveBG(bg3, bg4, bg3Speed, delta);
	moveBG(bg5, bg6, bg5Speed, delta);

	//这种方法效率太低，每帧都要检测。在碰撞检测中，如果碰撞了再改，更好，在gatecontroller中实现
	//CCString* strScore = CCString::createWithFormat("%d", score);//格式化为字符串  
	//scoreItem->setString(strScore->m_sString.c_str());//从CCString中获得char*,更新分数  
	//char scoreNum[100] = { 0 };
	//sprintf(scoreNum, "score : %d", gateController->getScore());
	//scoreLabel->setString(std::string(scoreNum));
}


void GameScene::moveBG(Sprite *background1, Sprite *background2, float speed, float delta)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float bgPosX1 = background1->getPositionX();
	float bgPosX2 = background2->getPositionX();
	background1->setPositionX(bgPosX1 - delta * speed);
	background2->setPositionX(bgPosX2 - delta * speed);
	if (bgPosX1 <= -visibleSize.width / 2)
	{
		float offset = background1->getPositionX() + visibleSize.width / 2;
		background1->setPositionX(visibleSize.width * 3 / 2 + offset);
	}
	if (bgPosX2 <= -visibleSize.width / 2)
	{
		float offset = background2->getPositionX() + visibleSize.width / 2;
		background2->setPositionX(visibleSize.width * 3 / 2 + offset);
	}
}

bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
	if (hero->getisAlive() == true)
	{
		if (hero->getIsTouch() == false)
		{
			hero->stopAllActions();
			auto action = Sequence::create(MoveTo::create(0.1, Vec2(100, 50)), CallFuncN::create(CC_CALLBACK_1(GameScene::callback_jump, this)), nullptr);
			hero->runAction(action);
			hero->setIsTouch(true);
		}
	}
	return true;
}




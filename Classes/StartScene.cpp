#include "StartScene.h"
#include "GameScene.h"

USING_NS_CC;

#define bg1Speed 500
#define bg3Speed 400
#define bg5Speed 300

StartScene::StartScene()
{

}

StartScene::~StartScene()
{

}

Scene* StartScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);
	
	

	return scene;
}

bool StartScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	if (!UserDefault::getInstance()->isXMLFileExist())
	{
		UserDefault::getInstance()->setIntegerForKey("highestScore", 0);
	}

	this->scheduleUpdate();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
 	initBG();

	//hero
	auto hero = Sprite::create("Ship1.png");
	hero->setPosition(Vec2(80, visibleSize.height / 2));
	this->addChild(hero,3);
	auto action1 = MoveBy::create(0.3, Vec2(0,30));
	auto action2 = MoveBy::create(0.3, Vec2(0, -30));
	auto action12 = Sequence::create(action1, action2, nullptr);
	auto action3 = MoveBy::create(0.1, Vec2(5, 0));
	auto action4 = MoveBy::create(0.1, Vec2(-5, 0));
	auto action34 = Sequence::create(action3, action4, nullptr);
	auto repeat = RepeatForever::create(Spawn::create(action12, action34, nullptr));
	hero->runAction(repeat);
	
	//Title
	auto titleLogo = Sprite::create("TitleLogo.png");
	titleLogo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(titleLogo, 3);
	
	//Menu
	auto itemOptions = MenuItemImage::create("TitleOptions.png", "TitleOptions.png", "TitleOptions.png", 
		CC_CALLBACK_1(StartScene::menuCallback, this));
	auto itemMore = MenuItemImage::create("TitleMore.png", "TitleMore.png", "TitleMore.png",
		CC_CALLBACK_1(StartScene::menuCallback2, this));
	auto itemEjectButton = MenuItemImage::create("EjectButton.png", "EjectButton.png", "EjectButton.png",
		CC_CALLBACK_1(StartScene::menuCallback3, this));
	auto menu = Menu::create(itemOptions, itemMore, itemEjectButton, nullptr);
	menu->alignItemsHorizontally();
	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));
	this->addChild(menu, 3);


	return true;
}

void StartScene::initBG()
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

void StartScene::update(float delta)
{
	moveBG(bg1, bg2, bg1Speed, delta);
	moveBG(bg3, bg4, bg3Speed, delta);
	moveBG(bg5, bg6, bg5Speed, delta);

}

void StartScene::moveBG(Sprite *background1, Sprite *background2, float speed,float delta)
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


void StartScene::menuCallback(Ref *sender)
{

}

void StartScene::menuCallback2(Ref *sender)
{

}

void StartScene::menuCallback3(Ref *sender)
{
	Director::getInstance()->replaceScene(TransitionFadeTR::create(1.2,GameScene::createScene()));
}
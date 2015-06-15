#include "HelloWorldScene.h"
#include "Hero.h"
#include "Monster.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("MainSpriteSheet.plist", "MainSpriteSheet.png");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("gate-static1.png");
	
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	Animation *animation = Animation::create();
	for (int i = 2; i < 4;i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "spike%d.png", i);
		animation->addSpriteFrame(frameCache->spriteFrameByName(szName));
	}

	animation->setDelayPerUnit(0.5);
	animation->setRestoreOriginalFrame(true);
	Animate *action = Animate::create(animation);

	sprite->runAction(RepeatForever::create(action));
	
	auto hero = Hero::create();
	hero->bindSprite(Sprite::createWithSpriteFrameName("jet4.png"));
	this->addChild(hero, 1);
	hero->setPosition(Vec2(0,0));

	auto monster = Monster::create();
	monster->bindSprite(Sprite::create("gate-static1.png"));
	this->addChild(monster, 1);
	monster->setPosition(Vec2(300, 100));

// 	DrawPrimitives::setDrawColor4B(255, 255, 0, 255);
// 	glLineWidth(10);
// 	Vec2 vertices[] = { Vec2(0, 0), Vec2(50, 50), Vec2(100, 50), Vec2(100, 100), Vec2(50, 100) };
// 	DrawPrimitives::drawPoly(vertices, 5, false);

	auto s = Director::getInstance()->getWinSize();

	auto draw = DrawNode::create();
	addChild(draw, 10);


	// draw 4 small points
	Vec2 position[] = { Vec2(60, 60), Vec2(70, 70), Vec2(60, 70), Vec2(70, 60) };
	draw->drawPoints(position, 4, 5, Color4F(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 1));

	//draw->drawRect(Vec2(monster->getBoundingBox.getMinX(), monster->getBoundingBox.getMinY()),Vec2(monster->getBoundingBox.getMaxX(), monster->getBoundingBox.getMaxY()),Color4F(1, 0, 1, 1));
	Vec2 monster_x = Vec2(monster->getBoundingBox().getMinX(), monster->getBoundingBox().getMinY());
	Vec2 monster_yy = Vec2(monster->getBoundingBox().getMaxX(), monster->getBoundingBox().getMaxY());
	draw->drawRect(monster_x, monster_yy, Color4F(1, 1, 0, 1));

	Vec2 hero_x = Vec2(hero->getBoundingBox().getMinX(), hero->getBoundingBox().getMinY());
	Vec2 hero_yy = Vec2(hero->getBoundingBox().getMaxX(), hero->getBoundingBox().getMaxY());
	draw->drawRect(hero_x, hero_yy, Color4F(1, 1, 0, 1));
	draw->drawPoint(monster->getPosition(), 10, Color4F(1, 1, 0, 1));

    return true;
}



#include "HelloWorldScene.h"
#include "Particle3D/PU/CCPUParticleSystem3D.h"

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
    auto sprite = Sprite::createWithSpriteFrameName("jet4.png");

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
	

	//
    
    return true;
}



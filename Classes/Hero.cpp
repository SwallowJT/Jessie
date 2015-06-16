#include "Hero.h"

Hero::Hero()
{
	isAlive = true;
	isTouch = false;
}

Hero::~Hero()
{

}

bool Hero::init()
{
	auto fire = ParticleFireworks::create();
	fire->setTexture(Director::getInstance()->getTextureCache()->addImage("jetpack2-hd.png"));
	fire->setPosition(Vec2(10,10));
	fire->setScale(2);
	fire->setLife(0.3);
	fire->setEndSize(-1);
	fire->setSpeed(100);
	fire->setRadialAccel(10);
	fire->setEmitterMode(ParticleSystem::Mode::GRAVITY);
	fire->setGravity(Vec2(-2000, -1000));
	this->addChild(fire, 10);

	return true;
}

bool Hero::getIsTouch()
{
	return isTouch;
}

void Hero::setIsTouch(bool aa)
{
	isTouch = aa;
}

bool Hero::getisAlive()
{
	return isAlive;
}

void Hero::setIsAlive(bool bb)
{
	isAlive = bb;
}
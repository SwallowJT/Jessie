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
	auto fire = ParticleMeteor::create();
	fire->setTexture(Director::getInstance()->getTextureCache()->addImage("fire.png"));
	fire->setPosition(Vec2(10,10));
	fire->setScale(0.5);
	fire->setLife(0.5);
	fire->setEndSize(1);
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
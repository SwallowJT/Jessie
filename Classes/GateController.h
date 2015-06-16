#ifndef _GATECONTROLLER_H_
#define _GATECONTROLLER_H_

#include "cocos2d.h"
#include "Hero.h"
#include "gate.h"

USING_NS_CC;

class GateController : public Node
{
public:
	GateController();
	~GateController();
	virtual bool init();
	CREATE_FUNC(GateController);
	void bindHero(Hero *hero);
	void update(float delta);
	void updateScore(int score);
	static int score;  //����ʹ��UserDefault��ֵ��ʵ�����ݵĹ���
private:
	void createGates();
	Vector<Gate*> m_gates;
	Hero *m_hero;
	//int score;
	Label  *scoreLabel;
};
#endif
#include "cocos2d.h"
#include "Monster.h"
#include "Hero.h"
USING_NS_CC;

class MonsterController : public Node
{
public:
	virtual bool init();
	CREATE_FUNC(MonsterController);
	virtual void update(float delta);
	void bindHero(Hero *hero);
private:
	void createMonsters();
	Vector<Monster*> m_monster;
	Hero *m_hero;
};
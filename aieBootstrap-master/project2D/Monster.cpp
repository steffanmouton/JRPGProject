#include "Monster.h"



Monster::Monster()
{

}

Monster::Monster(int hp, int max, int min)
{
	m_Hp = hp;
	m_MaxDmg = max;
	m_MinDmg = min;
}

Monster::Monster(int hp, int max, int min, Entity * targ)
{
	m_Hp = hp;
	m_MaxDmg = max;
	m_MinDmg = min;
	m_Target = targ;

}


Monster::~Monster()
{
}

void Monster::pUpdate(float dt)
{
}

void Monster::pDraw(aie::Renderer2D * renderer)
{
}



#include "Monster.h"



Monster::Monster() = default;

Monster::Monster(int hp, int maxHp, int max, int min, vector2 pos, const char* name, int endReward)
{
	m_Hp = hp;
	m_maxHp = maxHp;
	m_MaxDmg = max;
	m_MinDmg = min;
	screenPosition.x = pos.x;
	screenPosition.y = pos.y;
	m_Name = name;
	reward = endReward;
}


Monster::~Monster()
{

}

void Monster::eUpdate(float dt)
{
	m_AliveTimer += dt;

	//checking for alive
	if (!isAlive())
	{
		eState = Dead;
	}

	//if Monster turn and is alive, state set to attack
	if ( turn && isAlive())
		eState = Attacking;

	//FSM for drawing Monster Animations
	switch (eState)
	{
	case Entity::EntityState::Idle:
	{
		this->m_CurTexture = textures.at(0);
		this->m_CurUV = uvRects.at(0);
		AnimationStart = m_AliveTimer;
		AnimationDraw = m_AliveTimer;
		break;
	}
	case Entity::EntityState::Attacking:
	{

		this->m_CurTexture = textures.at(1);
		this->m_CurUV = uvRects.at(1);
		AnimationDraw = m_AliveTimer - AnimationStart;

		if (AnimationDraw >= 2.f)
		{
			AnimationDraw = 0;
			Attack();
			eState = Idle;
			turnDone = true;
		}
		break;
	}
	case Entity::EntityState::Dead:
	{
		this->m_CurTexture = textures.at(2);
		this->m_CurUV = uvRects.at(2);
		AnimationDraw = m_AliveTimer - AnimationStart;

		if (AnimationDraw >= 2.f)
		{
			this->m_CurTexture = textures.at(3);
			this->m_CurUV = uvRects.at(3);
		}
		break;
	}
	}
}

//override for healing
void Monster::Heal(int amt)
{
	m_Hp += amt;
}



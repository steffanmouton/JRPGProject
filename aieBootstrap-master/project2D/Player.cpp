#include "Player.h"

Player::Player()
{
}

Player::Player(int hp, int max, int min)
{
	m_Hp = hp;
	m_MaxDmg = max;
	m_MinDmg = min;
}


Player::~Player()
{
}

void Player::pUpdate(float dt)
{
	if (!Attacking)
	{
		AnimationStart += dt;
	}
	else
	{
		
		this->m_CurPlayerAnimation = textures.at(0);
		AnimationDraw += (m_timer - AnimationStart);

		if (AnimationDraw >= 5.f)
		{
			//m_CurPlayerAnimation = m_HunterSakuraIdle;
			AnimationStart = 0;
			AnimationDraw = 0;
			Attacking = false;
		}

	}
}

void Player::pDraw(aie::Renderer2D* renderer)
{
	renderer->setUVRect(int(m_timer * 8) % 27 / 27.0f, 150, 1.f / 27, 1.f);
}

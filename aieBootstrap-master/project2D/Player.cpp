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
	m_timer += dt;

	if (!isAlive())
	{
		eState = Dead;
	}

	switch (eState)
	{
	case Entity::EntityState::Idle:
	{
		this->m_CurTexture = textures.at(0);
		this->m_CurUV = uvRects.at(0);
		AnimationStart += dt;
		break;
	}
	case Entity::EntityState::Attacking:
	{
		this->m_CurTexture = textures.at(1);
		this->m_CurUV = uvRects.at(1);
		AnimationDraw += (m_timer - AnimationStart);

		if (AnimationDraw >= 5.f)
		{
			AnimationStart = 0;
			AnimationDraw = 0;
			eState = Idle;
		}
		break;
	}
	case Entity::EntityState::Dead:
	{
		this->m_CurTexture = textures.at(2);
		this->m_CurUV = uvRects.at(2);
		AnimationDraw += (m_timer - AnimationStart);

		if (AnimationDraw >= 5.f)
		{
			AnimationStart = 0;
			AnimationDraw = 0;
			eState = Idle;
		}
		break;
	}
	}
}
//
//void Player::pDraw(aie::Renderer2D* renderer)
//{
//	renderer->setUVRect(int(m_timer * 8) % 27 / 27.0f, 150, 1.f / 27, 1.f);
//}

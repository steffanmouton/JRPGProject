#include "Player.h"

Player::Player()
{
}

Player::Player(int hp, int max, int min, Vector2 pos)
{
	m_Hp = hp;
	m_MaxDmg = max;
	m_MinDmg = min;
	screenPosition.x = pos.x;
	screenPosition.y = pos.y;
}


Player::~Player()
{
}

void Player::eUpdate(float dt)
{
	m_AliveTimer += dt;

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
		AnimationStart = m_AliveTimer;
		AnimationDraw = m_AliveTimer;
		break;
	}
	case Entity::EntityState::Attacking:
	{
	
		this->m_CurTexture = textures.at(1);
		this->m_CurUV = uvRects.at(1);
		AnimationDraw = m_AliveTimer - AnimationStart;

		if (AnimationDraw >= 4.f)
		{
			AnimationDraw = 0;
			eState = Idle;
			Attack();
			break;
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
//
//void Player::pDraw(aie::Renderer2D* renderer)
//{
//	renderer->setUVRect(int(m_timer * 8) % 27 / 27.0f, 150, 1.f / 27, 1.f);
//}

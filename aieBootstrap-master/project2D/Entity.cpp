#include "Entity.h"
#include <stdlib.h>


Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::TakeDmg(int Dmg)
{
	this->m_Hp -= Dmg;
}

int Entity::DealDmg()
{
	return rand() % m_MaxDmg + m_MinDmg;
}

int Entity::getHp()
{
	return m_Hp;
}

void Entity::Attack()
{
	this->m_Target->TakeDmg(DealDmg());
}

void Entity::SetTarget(Entity * targ)
{
	m_Target = targ;
}

bool Entity::isAlive()
{
	return this->m_Hp >= 0 ? true : false;
}

void Entity::eDraw(aie::Renderer2D * renderer, Rect * UVRect)
{
	renderer->setUVRect(int(m_timer * UVRect->UVspeed) % UVRect->cycles / UVRect->cycles, 
		UVRect->y, 1.f / UVRect->cycles, 1.f);
	renderer->drawSprite(m_CurTexture, 600, 400, 0, 0, 0, 1, 0, 0);
}

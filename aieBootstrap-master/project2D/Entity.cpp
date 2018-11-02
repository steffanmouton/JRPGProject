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
	return rand() % (m_MaxDmg-10) + m_MinDmg;
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

void Entity::eDraw(aie::Renderer2D * renderer)
{
	renderer->setUVRect(int(AnimationDraw * m_CurUV->UVspeed) % m_CurUV->cycles / float(m_CurUV->cycles), 
		m_CurUV->y, 1.f / float(m_CurUV->cycles), 1.f);
	renderer->drawSprite(m_CurTexture, screenPosition.x, screenPosition.y, m_CurUV->maxWidth, 
		m_CurUV->maxHeight, 0, 1, 0, 0);
}

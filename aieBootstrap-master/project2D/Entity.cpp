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

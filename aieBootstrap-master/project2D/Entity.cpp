#include "Entity.h"
#include <cstdlib>


Entity::Entity()
{
}



Entity::~Entity() = default;

//Decrease HP
void Entity::TakeDmg(int Dmg)
{
	this->m_Hp -= Dmg;
}

//Create a Damage value
int Entity::DealDmg()
{
	return rand() % (m_MaxDmg-m_MinDmg) + m_MinDmg;
}

//Return current hp
int Entity::getHp()
{
	return m_Hp;
}

//return max hp
int Entity::getMaxHp()
{
	return m_maxHp;
}


//cause enemy to take damage
void Entity::Attack()
{
	this->m_Target->TakeDmg(DealDmg());
}

//Set Entity's Target
void Entity::SetTarget(Entity * targ)
{
	m_Target = targ;
}

//Bool check if alive
bool Entity::isAlive()
{
	return this->m_Hp > 0;
}

//Increase HP
void Entity::Heal(int amt)
{
	m_Hp = +amt;
}

//set HP to an amount
void Entity::setHp(int amt)
{
	m_Hp = amt;
}

//return Entity Name
const char* Entity::getName()
{
	return m_Name;
}

//Draw entity to screen
void Entity::eDraw(aie::Renderer2D * renderer)
{
	renderer->setUVRect(int(AnimationDraw * m_CurUV->UVspeed) % m_CurUV->cycles / float(m_CurUV->cycles), 
		m_CurUV->y, 1.f / float(m_CurUV->cycles), 1.f);
	renderer->drawSprite(m_CurTexture, screenPosition.x, screenPosition.y, m_CurUV->maxWidth, 
		m_CurUV->maxHeight, 0, 1, 0, 0);
}

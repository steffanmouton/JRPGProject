#include "HealingPotion.h"



HealingPotion::HealingPotion()
{
}

HealingPotion::HealingPotion(int val)
{
	m_hpValue = val;
}


HealingPotion::~HealingPotion() = default;

int HealingPotion::HealPlayer()
{
	return m_hpValue;
}

void HealingPotion::Use(Entity* targ)
{
	targ->Heal(HealPlayer());
}
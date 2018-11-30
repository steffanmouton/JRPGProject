#include "HealingPotion.h"



HealingPotion::HealingPotion()
{
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
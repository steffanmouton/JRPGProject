#include "HealingPotion.h"



HealingPotion::HealingPotion()
{
}


HealingPotion::~HealingPotion()
{
}

int HealingPotion::HealPlayer()
{
	return m_hpValue;
}

void HealingPotion::Use(Player* targ)
{
	/*targ->Heal(HealPlayer());*/
}


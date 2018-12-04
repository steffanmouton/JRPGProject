#pragma once
#include "Potion.h"
class HealingPotion :
	public Potion
{
private:
	int m_hpValue;
public:
	HealingPotion();
	HealingPotion(int val);
	~HealingPotion();

	int HealPlayer();

	void Use(Entity* targ) override;
};


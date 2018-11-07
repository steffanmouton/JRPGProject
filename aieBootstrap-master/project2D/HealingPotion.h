#pragma once
#include "Potion.h"
class HealingPotion :
	public Potion
{
public:
	HealingPotion();
	~HealingPotion();

	void Drink() override;
};


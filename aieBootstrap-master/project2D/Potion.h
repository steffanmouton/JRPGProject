#pragma once
#include "Item.h"
class Potion :
	public Item
{
public:
	Potion();
	~Potion();

	virtual void Drink() = 0;
};


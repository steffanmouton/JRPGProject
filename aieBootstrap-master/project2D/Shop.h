#pragma once
#include <UnorderedLinkedList.h>
#include "Item.h"
#include "Player.h"

class Shop
{
public:
	Shop();
	~Shop();

	void sellToPlayer(Player p);

	UnorderedLinkedList<Item> *sInv;

protected:

	
};


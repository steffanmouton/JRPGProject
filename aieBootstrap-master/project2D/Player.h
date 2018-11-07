#pragma once
#include "Entity.h"
#include "Item.h"
#include "Shop.h"
#include <UnorderedLinkedList.h>

class Renderer2D;
class Player :
	public Entity
{
public:
	Player();
	Player(int hp, int max, int min, Vector2 pos, const char* name);
	~Player();

	void buyFromShop(Item i);

	UnorderedLinkedList<Item> *pInv;


	void eUpdate(float dt) override;

protected:
	int zenny;
};


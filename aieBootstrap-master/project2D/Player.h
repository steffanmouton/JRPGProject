#pragma once
#include "Entity.h"
#include "Item.h"
#include <UnorderedLinkedList.h>

class Renderer2D;
class Player :
	public Entity
{
public:
	Player();
	Player(int hp, int maxHp, int max, int min, vector2 pos, const char* name);
	~Player();

	void buyFromShop(Item i);

	UnorderedLinkedList<Item> *pInv;


	void eUpdate(float dt) override;
	void Heal(int amt) override;

	void changeZenny(int amt);
	int currentZenny();

	int smallPotionCount;
	int mediumPotionCount;
	int largePotionCount;

protected:
	
	int zenny;
};


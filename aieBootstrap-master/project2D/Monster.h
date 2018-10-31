#pragma once
#include "Player.h"
#include "Entity.h"

class Monster :
	public Entity
{
public:
	Monster();
	Monster(int hp, int max, int min);
	Monster(int hp, int max, int min, Entity* targ);
	~Monster();

};


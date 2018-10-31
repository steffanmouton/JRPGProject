#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player();
	Player(int hp, int max, int min);
	~Player();
};


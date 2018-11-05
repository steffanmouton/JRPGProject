#pragma once
#include "Entity.h"

class Renderer2D;
class Player :
	public Entity
{
public:
	Player();
	Player(int hp, int max, int min, Vector2 pos, const char* name);
	~Player();

	void eUpdate(float dt) override;
};


#pragma once
#include "Entity.h"

class Monster :
	public Entity
{
public:
	Monster();
	Monster(int hp, int max, int min);
	Monster(int hp, int max, int min, Entity* targ);
	~Monster();


	// Inherited via Entity
	virtual void pUpdate(float dt) override;

	/*virtual void pDraw(aie::Renderer2D * renderer) override;*/

};


#pragma once
#include "Entity.h"

class Monster :
	public Entity
{
public:
	
	Monster();
	Monster(int hp, int max, int min, Vector2 pos, const char* name);
	~Monster();

	void eUpdate(float dt) override;

	/*virtual void pDraw(aie::Renderer2D * renderer) override;*/

};


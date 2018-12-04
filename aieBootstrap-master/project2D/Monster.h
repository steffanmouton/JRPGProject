#pragma once
#include "Entity.h"

class Monster :
	public Entity
{
public:
	
	Monster();
	Monster(int hp, int maxHp, int max, int min, vector2 pos, const char* name, int endReward);
	~Monster();

	void eUpdate(float dt) override;
	void Heal(int amt) override;

	int reward;

	/*virtual void pDraw(aie::Renderer2D * renderer) override;*/

};


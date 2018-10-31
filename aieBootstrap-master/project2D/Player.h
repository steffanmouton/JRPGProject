#pragma once
#include "Entity.h"
#include <vector>

class Renderer2D;
class Player :
	public Entity
{
public:
	Player();
	Player(int hp, int max, int min);
	~Player();

	float m_timer;
	
	float AnimationStart = 0;
	float AnimationDraw = 0;
	
	void pUpdate(float dt) override;
	void pDraw(aie::Renderer2D* renderer);
	aie::Texture* m_CurPlayerAnimation;
	
};


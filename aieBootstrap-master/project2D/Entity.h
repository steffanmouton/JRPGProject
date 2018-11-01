#pragma once
#include "Renderer2D.h"
#include <vector>
#include "Rect.h"

class Entity
{
protected:
	int m_Hp;
	int m_MaxDmg;
	int m_MinDmg;
	
	

public:
	Entity();
	~Entity();

	float m_timer;
	
	
	void TakeDmg(int Dmg);
	int DealDmg();
	int getHp();
	void Attack();
	void SetTarget(Entity* targ);
	bool isAlive();
	virtual void pUpdate(float dt) = 0;
	/*virtual void pDraw(aie::Renderer2D* renderer) = 0;*/
	enum EntityState { Idle, Attacking, Dead };
	EntityState eState = Idle;
	std::vector<aie::Texture*> textures;
	std::vector<Rect*> uvRects;
	aie::Texture* m_CurTexture;
	Rect* m_CurUV;

	void eDraw(aie::Renderer2D* renderer, Rect * UVRect);

	Entity* m_Target;
};


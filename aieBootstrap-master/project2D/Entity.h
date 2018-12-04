#pragma once
#include "Renderer2D.h"
#include <vector>
#include "Rect.h"
#include "vector2.h"

class Entity
{
protected:
	int m_Hp;
	int m_MaxDmg;
	int m_MinDmg;
	float m_AliveTimer = 0;
	int m_maxHp;

	const char* m_Name;
	
	Entity* m_Target;

public:
	Entity();
	~Entity();
	
	void TakeDmg(int Dmg);
	int DealDmg();
	int getHp();
	int getMaxHp();
	void Attack();
	void SetTarget(Entity* targ);
	bool isAlive();
	virtual void Heal(int amt);
	void setHp(int amt);

	bool turn = false;
	bool turnDone = false;

	const char* getName();

	

	virtual void eUpdate(float dt) = 0;
	
	enum EntityState { Idle, Attacking, Dead };
	EntityState eState = Idle;

	std::vector<aie::Texture*> textures;
	aie::Texture* m_CurTexture;

	std::vector<Rect*> uvRects;
	Rect* m_CurUV;

	vector2 screenPosition;

	float AnimationStart = 0;
	float AnimationDraw = 0;
	
	
	void eDraw(aie::Renderer2D* renderer);

	
};


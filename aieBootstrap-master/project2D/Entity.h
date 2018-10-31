#pragma once
#include "Renderer2D.h"
#include <vector>
class Entity
{
protected:
	int m_Hp;
	int m_MaxDmg;
	int m_MinDmg;
	
	

public:
	Entity();
	~Entity();

	bool Attacking = false;
	
	void TakeDmg(int Dmg);
	int DealDmg();
	int getHp();
	void Attack();
	void SetTarget(Entity* targ);
	bool isAlive();
	virtual void pUpdate(float dt) = 0;
	virtual void pDraw(aie::Renderer2D* renderer) = 0;
	enum AnimState { eIdle, eAttack, eDead } eAn = eIdle;
	std::vector<aie::Texture*> textures;

	Entity* m_Target;
};


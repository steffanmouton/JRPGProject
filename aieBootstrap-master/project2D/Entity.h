#pragma once
class Entity
{
protected:
	int m_Hp;
	int m_MaxDmg;
	int m_MinDmg;
	

public:
	Entity();
	~Entity();
	
	void TakeDmg(int Dmg);
	int DealDmg();
	int getHp();
	void Attack();
	void SetTarget(Entity* targ);
	bool isAlive();

	Entity* m_Target;
};


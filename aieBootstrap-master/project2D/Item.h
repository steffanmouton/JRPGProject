#pragma once

class Entity;
class Player;

class Item
{
public:
	Item();
	~Item();
	int cost;
	virtual void Use(Player* targ);
	bool operator==(const Item rhs);

	Entity* m_target;

protected:

	const char* name;

	
	int sellValue;

	
	
};


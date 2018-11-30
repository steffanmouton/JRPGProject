#pragma once
#include "Entity.h"

class Item
{
public:
	Item();
	Item(int c, Entity* targ);
	~Item();
	int cost;
	virtual void Use(Entity* targ);
	bool operator==(const Item rhs);

	Entity* m_target;

protected:

	const char* name;

	
	int sellValue;

	
	
};


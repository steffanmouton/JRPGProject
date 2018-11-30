#include "Item.h"
#include "Entity.h"

Item::Item()
{
	cost = 0;
	m_target = nullptr;
}

Item::Item(int c, Entity * targ)
{
	cost = c;
	m_target = targ;
}


Item::~Item() = default;

void Item::Use(Entity* targ)
{
}

bool Item::operator==(const Item rhs)
{
	return this->name == rhs.name;
}

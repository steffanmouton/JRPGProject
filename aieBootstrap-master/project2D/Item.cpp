#include "Item.h"
#include "Entity.h"


Item::Item()
{
	cost = 0;
}


Item::~Item()
{
}

void Item::Use(Player* targ)
{
}

bool Item::operator==(const Item rhs)
{
	if (this->name == rhs.name)
	{
		return true;
	}
	else
		return false;
}

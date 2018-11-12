#include "Item.h"



Item::Item()
{
	cost = 0;
}


Item::~Item()
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

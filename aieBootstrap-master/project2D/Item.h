#pragma once
class Item
{
public:
	Item();
	~Item();
	int cost;

	bool operator==(const Item rhs);

protected:

	const char* name;

	
	int sellValue;

	
	
};


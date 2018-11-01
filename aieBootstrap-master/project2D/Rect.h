#pragma once
#include "Vector2.h"

class Rect
{
public:
	Rect();
	~Rect();

	Rect zero();

	Vector2 center;
	float height;
	Vector2 max;
	Vector2 min;
	Vector2 position;
	Vector2 size;
	float width;
	float x;
	float xMax;
	float xMin;
	float y;
	float yMax;
	float yMin;
};


#include "Rect.h"



Rect::Rect()
{
	height = width = x = xMax = xMin = y = yMax = yMin = 0;
	center = max = min = position = size = { 0 , 0 };
}


Rect::~Rect()
{
}

Rect Rect::zero()
{
	height = width = x = xMax = xMin = y = yMax = yMin = 0;
	center = max = min = position = size = { 0 , 0 };
}

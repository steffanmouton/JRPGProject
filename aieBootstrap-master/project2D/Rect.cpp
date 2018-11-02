#include "Rect.h"



Rect::Rect()
{
}


Rect::~Rect()
{
}

Rect::Rect(int c, float Y, float speed, float w, float h)
{
	cycles = c;
	y = Y;
	UVspeed = speed;
	maxHeight = h;
	maxWidth = w;
}

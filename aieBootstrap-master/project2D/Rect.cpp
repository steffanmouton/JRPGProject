#include "Rect.h"



Rect::Rect()
{
}


Rect::~Rect() = default;

//setting parameters for a UV rectangle
Rect::Rect(int c, float Y, float speed, float w, float h)
{
	cycles = c;
	y = Y;
	UVspeed = speed;
	maxHeight = h;
	maxWidth = w;
}

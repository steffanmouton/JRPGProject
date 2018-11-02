#pragma once
struct Rect
{
public:
	Rect();
	~Rect();
	Rect(int c, float y, float speed, float w, float h);

	float x;
	float y;
	float maxHeight;
	float maxWidth;
	float UVspeed;
	int cycles;

};
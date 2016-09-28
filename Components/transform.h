#pragma once
#include "vec2.h"

class Transform
{
public:
	vec2 position;
	vec2 scale;
	float facing;
	signed int color;
	vec2 dirEnd;

	Transform();
	Transform(float x, float y);

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();


};
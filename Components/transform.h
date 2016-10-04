#pragma once
#include "vec2.h"

class Transform
{
public:
	vec2 position;
	vec2 scale;
	vec2 velocity;
	vec2 accel;
	float facing;
	signed int color;
	//vec2 dirEnd;

	Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0);

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();
};
#pragma once


#include "Transform.h"

class ShipRenderer
{
public:
	ShipRenderer(unsigned a_color = 0xffffffff, float a_size = 5.f);

	unsigned int color;	// color of ship
	float size;			// length of planet

	void draw(Transform &Trans, const mat3 &T);
};
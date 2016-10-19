#pragma once


#include "Transform.h"

class PlanetaryRenderer
{
public:
	PlanetaryRenderer(unsigned a_color = 0xffffffff, float a_size = 20.f);

	unsigned int color;	// color of planet
	float size;			// radius of planet

	void draw(Transform &planetTrans, const mat3 &T);
};
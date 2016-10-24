#include "PlanetaryRenderer.h"

#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(Transform &planetTrans, const mat3 &T)
{
	mat3 glob = T * planetTrans.getGlobalTransform();
	vec2 pos = glob.c[2].xy;

	// right (x direction, up(y direction), position
	// magnitude of the radius transformed as a vector
	float xRad = magnitude(glob * vec3{ size, 0, 0 });
	float yRad = magnitude(glob * vec3{ 0, size, 0 });

	float rad = xRad > yRad ? xRad : yRad;
	

	sfw::drawCircle(pos.x, pos.y, rad, 12U, color);
}
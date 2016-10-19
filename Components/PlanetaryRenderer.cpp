#include "PlanetaryRenderer.h"

#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(Transform &planetTrans, const mat3 &T)
{
	//mat3 glob = planetTrans.getGlobalTransform();
	mat3 L = T * planetTrans.getGlobalTransform();

	//vec2 pos = glob.c[2].xy;
	vec3 pos = L.c[2];

	sfw::drawCircle(pos.x, pos.y, size, 12U, color);
}
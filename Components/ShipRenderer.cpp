#include "ShipRenderer.h"
#include "sfwdraw.h"

ShipRenderer::ShipRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void ShipRenderer::draw(Transform & Trans, const mat3 & T)
{
	mat3 ship = T * Trans.getGlobalTransform();

	vec3 p1 = T * ship * vec3{ 0, 2, 1 };
	vec3 p2 = T * ship * vec3{ -1, 0, 1 };
	vec3 p3 = T * ship * vec3{ 1,0,1 };
	vec3 p4 = T * ship * vec3{ 0,-1,1 };

	sfw::drawLine(p1.x, p1.y, p2.x, p2.y, RED);
	sfw::drawLine(p2.x, p2.y, p4.x, p4.y, color);
	sfw::drawLine(p4.x, p4.y, p3.x, p3.y, color);
	sfw::drawLine(p3.x, p3.y, p1.x, p1.y, RED);
}

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

	vec3 F = ship * vec3{ 0, 2, 1 };
	vec3 L = ship * vec3{ -1,-1, 1 };
	vec3 R = ship * vec3{ 1,-1, 1 };
	vec3 B = ship * vec3{ 0, -2, 1 };

	sfw::drawLine(L.x, L.y, F.x, F.y, color);
	sfw::drawLine(F.x, F.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, B.x, B.y, color);
	sfw::drawLine(B.x, B.y, L.x, L.y, color);

	vec3 F1 = ship * vec3{ -1,-2,1 };
	vec3 L1 = ship * vec3{ -1, 2, 1 };
	vec3 R1 = ship * vec3{ 1, -2, 1 };		
	vec3 B1 = ship * vec3{ 1, 2,1 };

	sfw::drawLine(L1.x, L1.y, F1.x, F1.y, BLUE);
	sfw::drawLine(F1.x, F1.y, R1.x, R1.y, BLUE);
	sfw::drawLine(R1.x, R1.y, B1.x, B1.y, BLUE);
	sfw::drawLine(B1.x, B1.y, L1.x, L1.y, BLUE);
}

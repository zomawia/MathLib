#include "shapedraw.h"
#include "sfwdraw.h"

void drawCircle(const Circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.radius, c.radius , color);
}

void drawAABB(const AABB & b, unsigned color)
{
	//LEFT
	sfw::drawLine(b.min().x, b.min().y, b.min().x, b.max().y, color);
	//RIGHT
	sfw::drawLine(b.max().x, b.min().y, b.max().x, b.max().y, color);
	//TOP
	sfw::drawLine(b.min().x, b.max().y, b.max().x, b.max().y, color);
	//BOT
	sfw::drawLine(b.min().x, b.min().y, b.max().x, b.min().y, color);


}

void drawPlane(const Plane & P, unsigned color)
{
	vec2 a = perp(P.dir);
	vec2 b = -perp(P.dir);

	sfw::drawCircle(P.pos.x, P.pos.y, 12, 12, color);
	sfw::drawLine(
		P.pos.x, P.pos.y, 
		P.pos.x + P.dir.x * 10, P.pos.y + P.dir.y * 10, color);

	sfw::drawLine(
		P.pos.x, P.pos.y,
		P.pos.x + a.x * 80, P.pos.y + a.y * 80, color);

	sfw::drawLine(
		P.pos.x, P.pos.y,
		P.pos.x + b.x * 80, P.pos.y + b.y * 80, color);


}

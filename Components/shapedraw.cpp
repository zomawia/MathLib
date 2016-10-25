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

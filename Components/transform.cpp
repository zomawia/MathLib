#include "transform.h"
#include "sfwdraw.h"
#include <cmath>

Transform::Transform() : facing(0), position({ 400,300 }), scale({20,8})
{
}

Transform::Transform(float x, float y)
{
	position.x = x;
	position.y = y;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	dirEnd = position + getDirection() * scale.x * 4;
	//vec2 upEnd = position - perp(getDirection()) * scale.y * 4;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, color);
	//sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, color);
}

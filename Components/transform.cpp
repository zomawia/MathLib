#include "transform.h"
#include "sfwdraw.h"
#include <cmath>

Transform::Transform(float x, float y, float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;

	facing = a;
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
	sfw::drawCircle(position.x,
		position.y, scale.x, scale.y, 0x888888FF);

	vec2 dirEnd = position + getDirection() * scale.x;
	vec2 upEnd = position - perp(getDirection()) * scale.x;

	sfw::drawLine(position.x, position.y,
		dirEnd.x, dirEnd.y, RED);

	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y, GREEN);
}

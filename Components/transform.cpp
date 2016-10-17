#include "transform.h"
#include "sfwdraw.h"
#include <cmath>

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 & dir)
{
	m_facing = angle(dir);
}

mat3 Transform::getLocalTransform() const
{
	mat3 retval;
	retval = translate(m_position)*scale(m_scale)*rotation(m_facing);
	return retval;
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getLocalTransform();

	vec3 pos = L.c[2];

	vec3 right  = L * vec3{ 10,0,1 };
	vec3 up		= L * vec3{ 0,10,1 };

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y,	up.x, up.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, 24, 4, 0x888888FF);


	//vec2 dirEnd = m_position + getDirection() * m_scale.x * 2;
	//vec2 upEnd = m_position - perp(getDirection() * 2) * m_scale.x * 2;

	//sfw::drawLine(m_position.x, m_position.y,
	//	dirEnd.x, dirEnd.y, GREEN);

	//sfw::drawLine(m_position.x, m_position.y,
	//	upEnd.x, upEnd.y, BLUE);
}

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

	m_parent = nullptr;
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

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr) return getLocalTransform();
	else return m_parent->getGlobalTransform() * getLocalTransform();
}

mat3 Transform::getLocalTransform() const
{
	mat3 T = translate(m_position);
	mat3 S = scale(m_scale);
	mat3 R = rotation(m_facing);

	return T * R * S;
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getGlobalTransform();

	vec3 pos = L.c[2];	

	vec3 right  = L * vec3{ 10,0,1 };
	vec3 up		= L * vec3{ 0,10,1 };

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y,	up.x, up.y, GREEN);
	
	vec3 sgp = m_parent ? m_parent->getGlobalTransform().c[2] : pos;
	sfw::drawLine(sgp.x, sgp.y, pos.x, pos.y, BLUE);

	sfw::drawCircle(pos.x, pos.y, 12, 12, 0x888888FF);
}

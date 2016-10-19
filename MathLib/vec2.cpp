#include "vec2.h"
#include <cmath>
#include "flops.h"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x - rhs.x, lhs.y - rhs.y};
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{lhs.x * rhs, lhs.y * rhs};
}

vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{lhs.x / rhs, lhs.y / rhs};
}

vec2 operator-(const vec2 & v)
{
	return vec2{-v.x, -v.y};
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator/=(vec2 & lhs, const float &rhs)
{
	return lhs = lhs / rhs;
}

vec2 & operator*=(vec2 & lhs, const float &rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator/=(const float & rhs, vec2 & lhs)
{
	return lhs = lhs / rhs;
}

vec2 & operator*=(const float & rhs, vec2 & lhs)
{
	return lhs = lhs * rhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return !fequals(lhs.x, rhs.x) || !fequals(lhs.y, rhs.y);
}

float distance(const vec2 & lhs, const vec2 & rhs)
{
	return sqrt((rhs.x - lhs.x)*(rhs.x - lhs.x) + (rhs.y - lhs.y)*(rhs.y - lhs.y));
}

float magnitude(const vec2 & v)
{
	return sqrt((v.x)*(v.x) + (v.y)*(v.y));
}

vec2 normal(const vec2 & v)
{
	return v/magnitude(v);
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
	return (rhs.x * lhs.x) + (rhs.y * lhs.y);
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}

vec2 perp(const vec2 & v)
{
	return vec2{ v.y, -v.x };
}

// toa = tan(a) = Opposite / Adjacent
// tan(a) = y / x
// atan(tan(a)) = atan(y/x)
// a = atan(y/x)
float angle(const vec2 & v)
{	
	//return angleBetween(v, vec2{ 1,0 });
	return atan2f(v.y, v.x); // while avoiding div by zero
}

vec2 fromAngle(float a)
{
	return vec2{cos(a), sin(a)};
}

vec2 lerp(const vec2 & start, const vec2 & end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);
	return retval;	
}

vec2 quadBezier(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha)
{
	vec2 retval;
	retval.x = lerp(lerp(start.x, mid.x, alpha), lerp(mid.x, end.x, alpha), alpha);
	retval.y = lerp(lerp(start.y, mid.y, alpha), lerp(mid.y, end.y, alpha), alpha);
	return retval;
}

vec2 hermiteSpline(const vec2 & start, const vec2 & s_tan, const vec2 & end, const vec2 & e_tan, float alpha)
{
	vec2 retval;

	float asq = alpha * alpha;
	float acub = asq * alpha;

	float h00 = 2 * acub - 3 * asq + 1;
	float h01 = -2 * acub + 3 * asq;
	float h10 = acub - 2 * asq + alpha;
	float h11 = acub - asq;

	retval.x = h00 * start.x + h10 * s_tan.x + h01 * end.x + h11 * e_tan.x;
	retval.y = h00 * start.y + h10 * s_tan.y + h01 * end.y + h11 * e_tan.y;

	return retval;

}

vec2 cardinalSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float tight, float alpha)
{
	vec2 tangent0 = (mid - start) * tight;
	vec2 tangent1 = (end - mid) * tight;
	
	return hermiteSpline(start, tangent0, end, tangent1, alpha);
}

vec2 catRomSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}

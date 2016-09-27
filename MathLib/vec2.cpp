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

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x != rhs.x || lhs.y != rhs.x;
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
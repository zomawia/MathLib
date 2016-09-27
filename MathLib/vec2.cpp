#include "vec2.h"
#include <cmath>

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
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x != rhs.x || lhs.y != rhs.x;
}

float magnitude(const vec2 & v)
{
	return sqrt((v.x)*(v.x) + (v.y)*(v.y));
}

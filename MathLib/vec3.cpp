#include "vec3.h"
#include "flops.h"
#include <cmath>

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

vec3 operator-(const vec3 & v)
{
	return vec3{ -v.x, -v.y, -v.z };
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

vec3 & operator/=(vec3 & lhs, const float &rhs)
{
	return lhs = lhs / rhs;
}

vec3 & operator*=(vec3 & lhs, const float &rhs)
{
	return lhs = lhs * rhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return fequals(lhs.x,rhs.x) && fequals(lhs.y, rhs.y) && fequals(lhs.z, rhs.z);
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x != rhs.x || lhs.y != rhs.x || lhs.z != rhs.z;
}

float magnitude(const vec3 & v)
{
	return sqrt((v.x)*(v.x) + (v.y)*(v.y));
}

vec3 normal(const vec3 & v)
{
	return v / magnitude(v);
}

float dot(const vec3 & rhs, const vec3 & lhs)
{
	return (rhs.x * lhs.x) + (rhs.y * lhs.y);
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}

// toa = tan(a) = Opposite / Adjacent
// tan(a) = y / x
// atan(tan(a)) = atan(y/x)
// a = atan(y/x)

vec3 cross(const vec3 & rhs, const vec3 & lhs)
{
	return vec3{	rhs.y*lhs.z - rhs.z*lhs.y,
					rhs.z*lhs.x - rhs.x*lhs.z,
					rhs.x*lhs.y - rhs.y*lhs.x};
}

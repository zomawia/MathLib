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

vec3 & operator/=(const float & rhs, vec3 & lhs)
{
	return lhs = lhs / rhs;
}

vec3 & operator*=(const float & rhs, vec3 & lhs)
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
	return (rhs.x * lhs.x) + (rhs.y * lhs.y) + (rhs.z * lhs.z);
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}

vec3 cross(const vec3 & rhs, const vec3 & lhs)
{
	return vec3{	rhs.y*lhs.z - rhs.z*lhs.y,
					rhs.z*lhs.x - rhs.x*lhs.z,
					rhs.x*lhs.y - rhs.y*lhs.x};
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

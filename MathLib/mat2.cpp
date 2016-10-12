#include "mat2.h"
#include "flops.h"

float mat2::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat2::operator[](unsigned idx)
{
	return m[idx];
}

mat2 mat2Identity()
{
	return mat2{1,0,0,1};
}

bool operator==(const mat2 & lhs, const mat2 & rhs)
{
	return fequals(lhs[0], rhs[0]) && fequals(lhs[1], rhs[1]) &&
			fequals(lhs[2], rhs[2]) && fequals(lhs[3], rhs[3]);
}

bool operator!=(const mat2 & lhs, const mat2 & rhs)
{
	return !fequals(lhs[0], rhs[0]) || !fequals(lhs[1], rhs[1]) ||
		!fequals(lhs[2], rhs[2]) || !fequals(lhs[3], rhs[3]);
}

mat2 operator+(const mat2 & lhs, const mat2 & rhs)
{
	return mat2{lhs[0] + rhs[0], lhs[1] + rhs[1],
				lhs[2] + rhs[2], lhs[3] + rhs[3] };
}

mat2 operator-(const mat2 & lhs, const mat2 & rhs)
{
	return mat2{lhs[0] - rhs[0], lhs[1] - rhs[1],
				lhs[2] - rhs[2], lhs[3] - rhs[3] };
}

mat2 operator-(const mat2 & m)
{
	return mat2{-m[0], -m[1], -m[2], -m[3]};
}

mat2 operator*(const mat2 & lhs, const mat2 & rhs)
{
	return mat2{
		lhs[0] * rhs[0] + lhs[1] * rhs[2], 
		lhs[0] * rhs[1] + lhs[1] * rhs[3], 
		lhs[2] * rhs[0] + lhs[3] * rhs[2], 
		lhs[2] * rhs[1] + lhs[3] * rhs[3] };
}

vec2 operator*(const mat2 & lhs, const vec2 & rhs)
{
	return vec2{lhs[0] * rhs[0] + lhs[1] * rhs[1], 
				lhs[2] * rhs[0] + lhs[3] * rhs[1]};
}

mat2 operator*(const mat2 & lhs, float rhs)
{
	return mat2{lhs[0] * rhs,
				lhs[1] * rhs,
				lhs[2] * rhs,
				lhs[3] * rhs};
}

mat2 operator*(float rhs, const mat2 & lhs)
{
	return mat2{lhs[0] * rhs,
				lhs[1] * rhs,
				lhs[2] * rhs,
				lhs[3] * rhs };
}

float determinant(const mat2 & lhs)
{
	return lhs[0] * lhs[3] - lhs[1]*lhs[2];
}

mat2 inverse(const mat2 & lhs)
{
	return (1 / determinant(lhs)) * mat2 { lhs[3], -lhs[1], -lhs[2], lhs[0] };
}

mat2 transpose(const mat2 & m)
{
	// copy the diagonal
	mat2 retval = m;

	retval[2] = m[1];
	retval[1] = m[2];

	return retval;
}

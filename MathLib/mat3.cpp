#include "mat3.h"
#include "flops.h"

float mat3::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat3::operator[](unsigned idx)
{
	return m[idx];
}

mat3 mat3Identity()
{
	return mat3{1,0,0,
				0,1,0,
				0,0,1};
}

bool operator==(const mat3 & lhs, const mat3 & rhs)
{
	return	fequals(lhs[0], rhs[0]) && fequals(lhs[1], rhs[1]) &&
			fequals(lhs[2], rhs[2]) && fequals(lhs[3], rhs[3]) &&
			fequals(lhs[4], rhs[4]) && fequals(lhs[5], rhs[5]) && 
			fequals(lhs[6], rhs[6]) && fequals(lhs[7], rhs[7]) && 
			fequals(lhs[8], rhs[8]) && fequals(lhs[9], rhs[9]) ;
}

bool operator!=(const mat3 & lhs, const mat3 & rhs)
{
	return	!fequals(lhs[0], rhs[0]) || !fequals(lhs[1], rhs[1]) ||
			!fequals(lhs[2], rhs[2]) || !fequals(lhs[3], rhs[3]) ||
			!fequals(lhs[4], rhs[4]) || !fequals(lhs[5], rhs[5]) ||
			!fequals(lhs[6], rhs[6]) || !fequals(lhs[7], rhs[7]) ||
			!fequals(lhs[8], rhs[8]);
}

mat3 operator+(const mat3 & lhs, const mat3 & rhs)
{
	return mat3{ lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2],
					lhs[3] + rhs[3], lhs[4] + rhs[4], lhs[5] + rhs[5],
					lhs[6] + rhs[6], lhs[7] + rhs[7], lhs[8] + rhs[8] };				
}

mat3 operator-(const mat3 & lhs, const mat3 & rhs)
{
	return mat3{	lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2],
					lhs[3] - rhs[3], lhs[4] - rhs[4], lhs[5] - rhs[5],
					lhs[6] - rhs[6], lhs[7] - rhs[7], lhs[8] - rhs[8] };
}

mat3 operator-(const mat3 & m)
{
	return mat3{	-m[0], -m[1], -m[2],
					-m[3], -m[4], -m[5],
					-m[6], -m[7], -m[8] };
}

mat3 operator*(const mat3 & lhs, const mat3 & rhs)
{
	return mat3{	lhs[0] * rhs[0] + lhs[1] * rhs[3] + lhs[2] * rhs[6],
					lhs[0] * rhs[1] + lhs[1] * rhs[4] + lhs[2] * rhs[7],
					lhs[0] * rhs[2] + lhs[1] * rhs[5] + lhs[2] * rhs[8],

					lhs[3] * rhs[0] + lhs[4] * rhs[3] + lhs[5] * rhs[6],
					lhs[3] * rhs[1] + lhs[4] * rhs[4] + lhs[5] * rhs[7],
					lhs[3] * rhs[2] + lhs[4] * rhs[5] + lhs[5] * rhs[8],

					lhs[6] * rhs[0] + lhs[7] * rhs[3] + lhs[8] * rhs[6],
					lhs[6] * rhs[1] + lhs[7] * rhs[4] + lhs[8] * rhs[7],
					lhs[6] * rhs[2] + lhs[7] * rhs[5] + lhs[8] * rhs[8],
				};
}

vec3 operator*(const mat3 & lhs, const vec3 & rhs)
{
	return vec3{	lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2],
					lhs[3] * rhs[0] + lhs[4] * rhs[1] + lhs[5] * rhs[2],
					lhs[6] * rhs[0] + lhs[7] * rhs[1] + lhs[8] * rhs[2] };
}

mat3 operator*(const mat3 & lhs, float rhs)
{
	return mat3{lhs[0] * rhs,
				lhs[1] * rhs,
				lhs[2] * rhs,
				lhs[3] * rhs,
				lhs[4] * rhs,
				lhs[5] * rhs,
				lhs[6] * rhs,
				lhs[7] * rhs,
				lhs[8] * rhs };
	
}

mat3 operator*(float rhs, const mat3 & lhs)
{
	return mat3{ lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs,
		lhs[4] * rhs,
		lhs[5] * rhs,
		lhs[6] * rhs,
		lhs[7] * rhs,
		lhs[8] * rhs };
}

float determinant(const mat3 & lhs)
{
	return	lhs[0] * (lhs[4] * lhs[8] - lhs[5]*lhs[7]) - 
			lhs[1] * (lhs[3] * lhs[8] - lhs[5] * lhs[6]) +
			lhs[2] * (lhs[3] * lhs[7] - lhs[4] * lhs[6]);
}

mat3 minor(const mat3 & lhs)
{
	return mat3 {
		lhs[4] * lhs[8] - lhs[5] * lhs[7],
		lhs[3] * lhs[8] - lhs[5] * lhs[6],
		lhs[3] * lhs[7] - lhs[4] * lhs[6],

		lhs[1] * lhs[8] - lhs[2] * lhs[7],
		lhs[0] * lhs[8] - lhs[2] * lhs[6],
		lhs[0] * lhs[7] - lhs[1] * lhs[6],

		lhs[1] * lhs[5] - lhs[2] * lhs[4],
		lhs[0] * lhs[5] - lhs[2] * lhs[3],
		lhs[0] * lhs[4] - lhs[1] * lhs[3] };
}

mat3 cofactor(const mat3 & lhs)
{
	return mat3{
		lhs[0], -lhs[1], lhs[2],
		-lhs[3], lhs[4], -lhs[5], 
		lhs[6], -lhs[7], lhs[8]};
}

mat3 inverse(const mat3 & lhs)
{
	return ((1/determinant(lhs)) * transpose(cofactor(minor(lhs))));		
}

mat3 transpose(const mat3 & m)
{
	// copy the diagonal
	mat3 retval = m;
	
	retval[1] = m[3];
	retval[2] = m[6];
	retval[3] = m[1];	
	retval[5] = m[7];
	retval[6] = m[2];
	retval[7] = m[5];

	return retval;
}

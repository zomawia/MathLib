#include "mat3.h"
#include "flops.h"
#include <cmath>

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
			fequals(lhs[8], rhs[8]) ;
}

bool operator!=(const mat3 & lhs, const mat3 & rhs)
{
	return	!(lhs == rhs);
}

mat3 operator+(const mat3 & lhs, const mat3 & rhs)
{
	mat3 retval;

	for (int i = 0; i < 9; ++i)
	{
		retval[i] = lhs[i] + rhs[i];
	}
	
	return retval;
}

mat3 operator-(const mat3 & lhs, const mat3 & rhs)
{
	return mat3{	lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2],
					lhs[3] - rhs[3], lhs[4] - rhs[4], lhs[5] - rhs[5],
					lhs[6] - rhs[6], lhs[7] - rhs[7], lhs[8] - rhs[8] };
}

mat3 operator-(const mat3 & m)
{
	mat3 retval;
	for (int i = 0; i < 9; ++i)
	{
		retval[i] = m[i] * -1;
	}
	return retval;
}

mat3 operator*(const mat3 &rhs , const mat3 & lhs)
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

	//mat3 retval;
	//mat3 At = transpose(lhs);
	//for (int i = 0; i < 3; ++i)
	//	for (int j = 0; j < 3; ++j)
	//		retval[i][j] = dot(At.c[j], B.c[i]);
	//return retval;

}

vec3 operator*(const mat3 & lhs, const vec3 & rhs)
{
	// 0 3 6
	// 1 4 7
	// 2 5 8
	
	return vec3{	lhs[0] * rhs[0] + lhs[3] * rhs[1] + lhs[6] * rhs[2],
					lhs[1] * rhs[0] + lhs[4] * rhs[1] + lhs[7] * rhs[2],
					lhs[2] * rhs[0] + lhs[5] * rhs[1] + lhs[8] * rhs[2] };
}

mat3 operator*(const mat3 & lhs, float rhs)
{
	mat3 retval;
	for (int i = 0; i < 9; ++i)
	{
		retval[i] = lhs[i] * rhs;
	}

	return retval;
	
}

mat3 operator*(float rhs, const mat3 & lhs)
{
	mat3 retval;
	for (int i = 0; i < 9; ++i)
	{
		retval[i] = lhs[i] * rhs;
	}
	
	return retval;
}

float determinant(const mat3 & lhs)
{
	return	lhs[0] * (lhs[4] * lhs[8] - lhs[5] * lhs[7]) - 
			lhs[1] * (lhs[3] * lhs[8] - lhs[5] * lhs[6]) +
			lhs[2] * (lhs[3] * lhs[7] - lhs[4] * lhs[6]);

	// return dot(lhs.c[0], cross(lhs.c[1], lhs.c[2]));

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
		 lhs[0],  -lhs[1],  lhs[2],
		-lhs[3],   lhs[4], -lhs[5], 
		 lhs[6],  -lhs[7],  lhs[8]};
}

mat3 inverse(const mat3 & lhs)
{
	//return ((1/determinant(lhs)) * transpose(cofactor(minor(lhs))));

	mat3 retval;
	retval.c[0] = cross(lhs.c[1], lhs.c[2]);
	retval.c[1] = cross(lhs.c[2], lhs.c[0]);
	retval.c[2] = cross(lhs.c[0], lhs.c[1]);
	return 1 / determinant(lhs) * transpose(retval);
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

	//for (unsigned i = 0; i < 3; ++i)
	//	for (unsigned j = 0; j < 3; ++j)
	//		retval[i][j] = m[j][i];

	return retval;
}

mat3 scale(const vec2 & s)
{
	mat3 retval = mat3Identity();
	retval[0] = s.x;
	retval[4] = s.y;
	return retval;
}

mat3 translate(const vec2 & t)
{
	mat3 retval = mat3Identity();
	retval[6] = t.x;
	retval[7] = t.y;
	return retval;
}

mat3 rotation(float r)
{
	// 0,1,2 : column 1
	// 3,4,5 : column 2
	// 6,7,8 : column 3
	
	mat3 retval = mat3Identity();
	retval[0] = cos(r);
	retval[1] = sin(r);

	retval[3] = -sin(r);
	retval[4] = cos(r);

	return retval;
}

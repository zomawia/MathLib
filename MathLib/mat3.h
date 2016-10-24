#pragma once
#include "vec3.h"

union mat3
{
	float m[9];		// single dimensional array
	float mm[3][3]; // multidimensional array
	vec3 c[3];		// column vectors

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

mat3 mat3Identity();

// mat3 == mat3 :: equivalence
bool operator==(const mat3 &lhs, const mat3 & rhs);

//mat3 != mat3 :: non-equivalence
bool operator!=(const mat3 &lhs, const mat3 & rhs);

// mat3 + mat3 : matrix addition
mat3 operator+(const mat3 &lhs, const mat3 &rhs);
// mat3 - mat3 : matrix sub
mat3 operator-(const mat3 &lhs, const mat3 &rhs);
// -mat3	   
mat3 operator-(const mat3 &m);

// mat3 * mat3 : matric multiplied by matrix
mat3 operator*(const mat3 &lhs, const mat3 &rhs);

// mat3 * vec3 : matrix by vector3 
vec3 operator*(const mat3 &lhs, const vec3 &rhs);

// mat3 * float: matrix by scalar
mat3 operator*(const mat3 &lhs, float rhs);
// float * mat3: scalar by matrix
mat3 operator*(float rhs, const mat3 &lhs);

// determinant(mat3)
float determinant(const mat3 &lhs);

//affine multiplication
vec2 amul(const mat3 &A, const vec2 &V);

// matrix of minors
mat3 minor(const mat3 &lhs);

// matrix of cofactors
mat3 cofactor(const mat3 &lhs);

// inverse(mat3)
mat3 inverse(const mat3 &lhs);

mat3 transpose(const mat3 &m);

mat3 scale(const vec2 &s);
mat3 translate(const vec2 &t);
mat3 rotation(float degree);
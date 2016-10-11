#pragma once
#include "vec2.h"

union mat2
{
	float m[4];		// single dimensional array
	float mm[2][2]; // multidimensional array
	vec2 c[2];		// column vectors

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

mat2 mat2Identity();

// mat2 == mat2 :: equivalence
bool operator==(const mat2 &lhs, const mat2 & rhs);

// mat2 != mat2 :: equivalence
bool operator!=(const mat2 &lhs, const mat2 & rhs);

// mat2 + mat2 : matrix addition
mat2 operator+(const mat2 &lhs, const mat2 &rhs);
// mat2 - mat2 : matrix sub
mat2 operator-(const mat2 &lhs, const mat2 &rhs);
// -mat2	   
mat2 operator-(const mat2 &m);

// mat2 * mat2 : matric multiplied by matrix
mat2 operator*(const mat2 &lhs, const mat2 &rhs);
// mat2 * vec2 : matrix by vector 
vec2 operator*(const mat2 &lhs, const vec2 &rhs);
// mat2 * float: matrix by scalar
mat2 operator*(const mat2 &lhs, float rhs);
// float * mat2: scalar by matrix
mat2 operator*(float rhs, const mat2 &lhs);

// determinant(mat2)
float determinant(const mat2 &lhs);
// inverse(mat2)
mat2 inverse(const mat2 &lhs);

mat2 transpose(const mat2 &m);


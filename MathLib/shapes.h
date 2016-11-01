#pragma once

#include "mat3.h"

// Bounding Volumes
struct Circle {
	vec2 pos; //offset
	float radius;

};
// Treat radius as x-aligned vector and y-alighed vector
// multiple them by the matrix, get their magnitude.
// the largest magitude will be the new radius.
Circle	operator*(const mat3 &T, const Circle &C);
bool operator==(const Circle&A, const Circle &B);

struct AABB {
	vec2 pos, he; //half-extants
					// x = half-width
					// y = half-height
	vec2 min() const;
	vec2 max() const;
};
AABB operator*(const mat3 &T, const AABB &B);
bool operator==(const AABB &A, const AABB &B);


struct Plane {
	vec2 pos, dir;

};

Plane operator*(const mat3 &T, const Plane &P);
bool operator==(const Plane&A, const Plane &B);

struct Ray {
	
};

struct Hull {

};



AABB	operator*(const mat3 &T, const AABB   &B);
Plane	operator*(const mat3 &T, const Plane  &P);
Ray		operator*(const mat3 &T, const Ray    &R);
Hull    operator*(const mat3 &T, const Hull   &H);


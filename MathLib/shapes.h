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
Ray		operator*(const mat3 &T, const Ray    &R);


// ensure that it is convex
// able to calculate surface normals
struct Hull {
	//vec2 position;
	vec2 vertices[16];
	vec2 normals[16];
	size_t size;

	//assume Clockwise winding order, evaluate each normal.
	Hull(const vec2 *a_vertices, unsigned a_size);
	Hull();
};
// if the convex hulls are the same size, loop through and compare their normals and vertices
Hull operator*(const mat3 &T, const Hull   &H);

// multiply each vertex and normal by the matrix
bool operator==(const Hull &A, const Hull &B);


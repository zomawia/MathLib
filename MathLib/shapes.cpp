#include "shapes.h"
#include "flops.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval = C;	

	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;
	
	float xRad = magnitude(T * vec3{ C.radius, 0, 0 });
	float yRad = magnitude(T * vec3{ 0, C.radius, 0 });

	retval.radius = xRad > yRad ? xRad : yRad;
		
	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos==B.pos && fequals(A.radius,B.radius);
}

AABB operator*(const mat3 & T, const AABB & B)
{
	AABB retval = B;
	
	retval.pos = (T * vec3{ B.pos.x, B.pos.y, 1 }).xy;
	
	return retval;
}

bool operator==(const AABB & A, const AABB & B)
{
	return A==B;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

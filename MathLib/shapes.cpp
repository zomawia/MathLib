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
	vec2 boxA = (T * vec3{ B.min().x, B.max().y, 1 }).xy;
	vec2 boxB = (T * vec3{ B.max().x, B.max().y, 1 }).xy;
	vec2 boxC = (T * vec3{ B.max().x, B.min().y, 1 }).xy;
	vec2 boxD = (T * vec3{ B.min().x, B.min().y, 1 }).xy;

	float xPoints[4] = { boxA.x, boxB.x, boxC.x, boxD.x };
	float yPoints[4] = { boxA.y, boxB.y, boxC.y, boxD.y };

	float xMin = boxA.x;
	float xMax = boxA.x;
	float yMin = boxA.y;
	float yMax = boxA.y;

	for (int i = 1; i < 4; ++i)
	{
		if (xPoints[i] < xMin)
			xMin = xPoints[i];
		if (xPoints[i] > xMax)
			xMax = xPoints[i];

		if (yPoints[i] < yMin)
			yMin = yPoints[i];
		if (yPoints[i] > yMax)
			yMax = yPoints[i];
	}

	AABB retval = B;
	//retval.pos = (T * vec3{B.pos.x, B.pos.y,1}).xy;
	retval.pos.x = (xMax + xMin) / 2;
	retval.pos.y = (yMax + yMin) / 2;
	retval.he.x = (xMax - xMin) / 2;
	retval.he.y = (yMax - yMin) / 2;

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

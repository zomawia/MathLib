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
	return A.he==B.he && A.pos==A.pos;
}

Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;
	retval.pos =
		(T * vec3{ P.pos.x, P.pos.y, 1 }).xy;
	retval.dir =
		normal(T * vec3{ P.dir.x, P.dir.y, 0 }).xy;
	return retval;
}

bool operator==(const Plane & A, const Plane & B)
{
	return A.dir == B.dir || A.pos == B.pos;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

Hull operator*(const mat3 & T, const Hull & H)
{
	Hull retval;
	retval.size = H.size;
	for (int i = 0; i < H.size; ++i)	{
		retval.vertices[i] = (T * vec3{ H.vertices[i].x, H.vertices[i].y, 1 }).xy;
		retval.normals[i] =  (T * vec3{H.normals[i].x, H.normals[i].y, 0 }).xy;
	}

	return retval;
}

bool operator==(const Hull &A, const Hull &B){
	if (A.size != B.size) 
		return false;

	for (int i = 0; i < A.size; ++i) 
		if (A.normals[i] != B.normals[i] || A.vertices[i] != B.vertices[i]) 
			return false;	
}

Hull::Hull()
{
	size = 0;
	//default empty
}

Hull::Hull(const vec2 * a_vertices, unsigned a_size){	

	//size = a_size;
	//for (int i = 0; i < size && i < 16; ++i) {		
	//	vertices[i] = a_vertices[i];
	//	normals[i] = perp(normal(a_vertices[i] - a_vertices[i+1]));
	//}
	//normals[size - 1] = perp(normal(a_vertices[size - 1] - a_vertices[0]));

	size = a_size;

	for (int i = 0; i < size && i < 16; ++i)
	{
		vertices[i] = a_vertices[i];
		normals[i] = -perp(normal(a_vertices[(i + 1) % size] - a_vertices[i]));
	}
}

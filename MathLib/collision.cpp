#include "collision.h"
#include <cmath>

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;
	
	// eval penetration depth
	float pdr = Amax - Bmin;
	float pdl = Bmax - Amin;
	retval.penetrationDepth = pdr < pdl ? pdr : pdl;
	
	// calc collision normal
	//float pde = pdl - pdr;
	retval.collisionNormal = (pdl - pdr) > 0.f ? 1.f : -1.f;

	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel){
	SweptCollisionData1D retval;
	float tl = (Amin - Bmax) / (Bvel - Avel);
	float tr = (Bmin - Amax) / (Avel - Bvel);

	retval.entryTime = fmin(tl, tr);
	retval.exitTime = fmax(tl, tr);
	retval.collisionNormal = copysignf(1, tl - tr);
	return retval;
}

bool SweptCollisionData1D::result() const{	
	return entryTime>=0 && entryTime <= 1;
}

bool CollisionData::result() const{
	return penetrationDepth >= 0;
}

vec2 CollisionData::MTV() const{
	return penetrationDepth * collisionNormal;
}

CollisionData boxCollision(const AABB & A, const AABB & B){
	CollisionData retval;

	CollisionData1D pdx = collisionDetection1D(A.min().x, A.max().x, 
										B.min().x, B.max().x);
	CollisionData1D pdy = collisionDetection1D(A.min().y, A.max().y,
										B.min().y, B.max().y);

	if (pdx.penetrationDepth < pdy.penetrationDepth) {
		retval.penetrationDepth = pdx.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } *pdx.collisionNormal;
	}
	else {
		retval.penetrationDepth = pdy.penetrationDepth;
		retval.collisionNormal = vec2{ 0,1 } *pdy.collisionNormal;
	}

	return retval;
}

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB){
	CollisionDataSwept retval;
	
	CollisionData1D Xdis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Ydis = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);
	bool ySwept = (dA.y - dB.y != 0);
	bool xSwept = (dA.x - dB.x != 0);
	
	SweptCollisionData1D xvalue = 
		sweptDetection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max().x, dB.x);

	SweptCollisionData1D yvalue =
		sweptDetection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max().y, dB.y);

	//retval.entryTime = fmax(xvalue.entryTime, yvalue.entryTime);
	//retval.exitTime  = fmin(xvalue.exitTime, yvalue.exitTime);

	if (xvalue.entryTime > yvalue.entryTime || xSwept && !ySwept) {
		retval.collisionNormal = xvalue.collisionNormal * vec2{ 1,0 };
		retval.entryTime = xvalue.entryTime;
		retval.collides = ySwept || Ydis.result();
	}
	else if (ySwept) {
		retval.collisionNormal = yvalue.collisionNormal * vec2{ 0,1 };
		retval.entryTime = yvalue.entryTime;
		retval.collides = xSwept || Xdis.result();
	}

	if (yvalue.exitTime < xvalue.exitTime || isinf(xvalue.exitTime) ) 
		retval.exitTime = yvalue.exitTime;
	else retval.exitTime = xvalue.exitTime;

	//retval.exitTime = (yvalue.exitTime < xvalue.exitTime) ? yvalue.exitTime : xvalue.exitTime;	

	return retval;
}

CollisionData planeBoxCollision(const Plane & P, const AABB & B){
	CollisionData retval;

	float boxA = dot(P.dir, vec2{ B.min().x, B.max().y });
	float boxB = dot(P.dir, B.max());	
	float boxC = dot(P.dir, vec2{ B.max().x, B.min().y });	
	float boxD = dot(P.dir, B.min());
	
	float volumeMin = fminf(boxA, fminf(boxB, fminf(boxC, boxD)));
	//float volumeMax = fmaxf(boxA, fmaxf(boxB, fmaxf(boxC, boxD)));	//not needed

	float planeMax = dot(P.pos, P.dir);

	retval.penetrationDepth = planeMax - volumeMin;
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const vec2 &Pvel,
	const AABB & B, const vec2 & Bvel){
	CollisionDataSwept retval;
	
	float boxA = dot(P.dir, vec2{ B.min().x, B.max().y });
	float boxB = dot(P.dir, B.max());
	float boxC = dot(P.dir, vec2{ B.max().x, B.min().y });
	float boxD = dot(P.dir, B.min());

	float VelD = dot(P.dir, Bvel);
	float VelE = dot(P.dir, Pvel);
	VelE = 0.f;
	float planeMax = dot(P.dir, P.pos);

	float volumeMin = fminf(boxA, fminf(boxB, fminf(boxC, boxD)));
	float volumeMax = fmaxf(boxA, fmaxf(boxB, fmaxf(boxC, boxD)));

	retval.entryTime = (volumeMin - planeMax)/(VelE - VelD);
	retval.exitTime = (volumeMax - planeMax) / (VelE - VelD);
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionData HullCollision(const Hull & A, const Hull & B)
{


	// Combining all the axes into a single array
	// This isn't necessary, but prevents duplicating
	// the evaluation loop
	int size = 0;
	vec2 axes[32];

	for (int j = 0; j < A.size; ++j) axes[size++] = A.normals[j];
	for (int j = 0; j < B.size; ++j) axes[size++] = B.normals[j];


	// Set up the return value
	// Since we're looking for the smallest penetration depth
	// along each axis, we can assume an infinitely large
	// penetration depth and reduce it as we discover results.

	CollisionData retval;
	retval.penetrationDepth = INFINITY;



	// This is the actual test- it's broken into two steps.
	// Find the projected min/max of each volume.
	// Determine their penetration depth.

	// The smallest of all is the final result.

	for (int j = 0; j < size; ++j)
	{
		vec2 &axis = axes[j]; // cache the axis

							  /////////////////////
							  // Evaluate the extents
							  // Start with some obnoxious values and work our way in.
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;

		// Loop through A's vertices and project the points.
		for (int i = 0; i < A.size; ++i)
		{
			float proj = dot(axis, A.vertices[i]);
			amin = fminf(proj, amin);
			amax = fmaxf(proj, amax);
		}

		// Loop through B's vertices and project the points.
		for (int i = 0; i < B.size; ++i)
		{
			float proj = dot(axis, B.vertices[i]);
			bmin = fminf(proj, bmin);
			bmax = fmaxf(proj, bmax);
		}

		/////////////////////////
		// Evaluation
		// Determine the penetration depth
		float pDr, pDl, pD, H;
		pDr = amax - bmin;
		pDl = bmax - amin;

		pD = fminf(pDr, pDl);

		// The direction along the axis
		H = copysignf(1, pDl - pDr);

		// Pick the smallest one
		if (pD < retval.penetrationDepth)
		{
			retval.penetrationDepth = pD;
			retval.collisionNormal = axis * H;
		}
	}
	return retval;
}

bool CollisionDataSwept::result() const{
	return entryTime >= 0 && entryTime <= 1 && collides;
}


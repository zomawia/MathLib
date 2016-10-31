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
	retval.collisionNormal = (pdl - pdr) > 0 ? 1 : -1;

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

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;
	float tl = (Amin - Bmax) / (Bvel - Avel);
	float tr = (Bmin - Amax) / (Avel - Bvel);

	retval.entryTime = fmin(tl, tr);
	retval.exitTime = fmax(tl, tr);
	retval.collisionNormal = copysignf(1, tl - tr);
	return retval;
}

bool SweptCollisionData1D::result() const
{	
	return entryTime>=0 && entryTime <= 1;
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}

vec2 CollisionData::MTV() const
{
	return penetrationDepth * collisionNormal;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
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

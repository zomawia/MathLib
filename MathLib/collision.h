#pragma once

#include "shapes.h"
struct CollisionData1D {
	
	float penetrationDepth;	// how much overlap
	float collisionNormal;	// -1 or 1
	
	bool result() const;
	float MTV() const;				// penetrationDepth * collisionNormal
 };

CollisionData1D collisionDetection1D(float Amin, float Amax, 
									 float Bmin, float Bmax);

struct SweptCollisionData1D {

	float entryTime, exitTime;
	float collisionNormal;	// -1 or 1

	bool result() const;


};
// pos
// pos + vel * time
// displace = vel * delta
SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									  float Bmin, float Bmax, float Bvel);

struct CollisionData {
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A, const AABB &B);
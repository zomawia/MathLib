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

struct CollisionDataSwept {
	float entryTime, exitTime;
	vec2 collisionNormal;
	bool collides;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA, 
								const AABB &B, const vec2 &dB);

CollisionData planeBoxCollision(const Plane&P, const AABB &B);

CollisionDataSwept planeBoxCollisionSwept(const Plane&P, const vec2 &Pvel, const AABB &B, const vec2 &Bvel);
#pragma once
struct CollisionData1D {
	
	float penetrationDepth;	// how much overlap
	float collisionNormal;	// -1 or 1
	
	bool result() const;
	float MTV() const;				// penetrationDepth * collisionNormal
 };

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax);


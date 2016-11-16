#include "Collider.h"
#include "shapedraw.h"
#include "sfwdraw.h"
#include <cmath>

Collider::Collider()
{
}

Collider::Collider(const vec2 * verts, int size) : hull(verts,size){
	vec2 boxMin = { INFINITY,  INFINITY },
		boxMax = { -INFINITY, -INFINITY };

	for (int i = 0; i < size; ++i)
	{
		boxMin = min(boxMin, verts[i]);
		boxMax = max(boxMax, verts[i]);
	}

	box.pos = (boxMin + boxMax) / 2;
	box.he = (boxMax - boxMin) / 2;
}

void Collider::DebugDraw(const mat3 & T, const Transform & trans){

	//drawAABB(T * trans.getGlobalTransform() * box, BLUE);

	//draw convex hull
	//need draw function for hulls
	drawHull(T * trans.getGlobalTransform() * hull, BLUE);


}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData retval;
	
	retval = boxCollision(AT.getGlobalTransform() * AC.box, 
		BT.getGlobalTransform() * BC.box);

	if (retval.penetrationDepth >=0)
	retval = HullCollision(AT.getGlobalTransform() * AC.hull, 
		BT.getGlobalTransform() * BC.hull);

	return retval;
}

CollisionData StaticResolution(Transform & AT, RigidBody & AR, const Collider & AC, 
	const Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT,AC,BT,BC);

	if (results.penetrationDepth >= 0) {
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal);
	}

	return results;

}

CollisionData DynamicResolution(Transform & AT, RigidBody & AR, const Collider & AC, 
	Transform & BT, RigidBody & BR, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);

	if (results.penetrationDepth >= 0) {			
		// correction
		vec2 MTV = results.collisionNormal * results.penetrationDepth;		
		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;

		AT.m_position -= MTV * (1-am/cm);
		BT.m_position += MTV * (1-bm/cm);

		
		// Resolution
		vec2 A = AR.velocity; vec2 B = BR.velocity;
		float P = AR.mass; float Q = BR.mass;
		vec2 x, y; //final velocities
		float E = bounciness;

		x = (A*P + B*Q + -E*(A - B)*Q) / (Q + P);		
		
		y = E*(A - B) + x;

		AR.velocity = x;
		BR.velocity = y;
	}

	return results;
}

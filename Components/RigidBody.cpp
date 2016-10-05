#include "RigidBody.h"

RigidBody::RigidBody()
{
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAccel = 0.0f;
	accel = vec2{0,0};
}

void RigidBody::integrate(Transform & trans, float delta)
{
	velocity += accel * delta;
	angularVelocity = angularAccel * delta;
	angle = trans.facing;
	
	trans.position = trans.position + velocity * delta;
	trans.facing = trans.facing + angularVelocity * delta;
	
}

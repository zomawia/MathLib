#include "RigidBody.h"

RigidBody::RigidBody()
{
	mass = 1;
	torque = 0;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAccel = 0.0f;
	accel = vec2{0,0};
}

void RigidBody::addForce(const vec2 & a_force)
{
	force += a_force;
}

void RigidBody::addImpulse(const vec2 & imp)
{
	impulse += imp;
}

void RigidBody::addTorque(float a_torque)
{
	// force = MA
	// accel = force/mass
	torque += a_torque;

}

void RigidBody::integrate(Transform & trans, float delta)
{
	accel = force / mass;	
	velocity += accel * delta + impulse/mass;
	trans.position += velocity * delta;	
	force = impulse = { 0,0 };	
	
	angularAccel = torque / mass;
	angularVelocity += angularAccel * delta;
	trans.facing += angularVelocity * delta;
	torque = 0;
	
}

#include "RigidBody.h"
#include "sfwdraw.h"

RigidBody::RigidBody()
{
	mass = 1;
	drag = .25f;
	angularDrag = 2.0f;
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
	trans.m_position += velocity * delta;	
	force = impulse = { 0,0 };	
	
	// dampening force
	force = -velocity * drag;

	angularAccel = torque / mass;
	angularVelocity += angularAccel * delta;
	trans.m_facing += angularVelocity * delta;
	torque = 0;

	torque = angularDrag * -angularVelocity;
	
}

void RigidBody::debugDraw(const Transform & trans)
{
	vec2 p = trans.m_position;
	vec2 v = p + velocity;
	vec2 a = accel + p;

	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
	sfw::drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}

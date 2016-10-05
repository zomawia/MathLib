#pragma once
#include "transform.h"

class RigidBody
{

public:
	RigidBody();

	float mass;

	vec2 force, impulse;

	vec2 velocity;
	vec2 accel;
	float torque;
	float angularVelocity;
	float angularAccel;

	float angle;

	void addForce(const vec2 &a_force);
	void addImpulse(const vec2 &imp);
	void addTorque(float a_torque);
	
	void integrate(Transform &trans, float delta);
};
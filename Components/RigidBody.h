#pragma once
#include "transform.h"

class RigidBody
{

public:
	RigidBody();

	vec2 velocity;
	vec2 accel;
	float angularVelocity;
	float angularAccel;

	float angle;
	
	void integrate(Transform &trans, float delta);
};
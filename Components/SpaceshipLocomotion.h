#pragma once

#include "RigidBody.h"

class SpaceshipLocomotion
{	
	float vThrust;		//foward movement				(0-1 value)
	float hThrust;
	float stopAction;
	float brakePower;
	float turnSpeed;	//rate of change for our turn
	float speed;		//movementspeed
	float maxSpeed;

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);
	void doStop(float value);

	void update(const Transform &trans, RigidBody &r);

};

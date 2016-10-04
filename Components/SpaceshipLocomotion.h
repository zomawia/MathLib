#pragma once

#include "RigidBody.h"

class SpaceshipLocomotion
{
	SpaceshipLocomotion();
	
	float thrust;		//foward movement
	float maxThrust;	//max forward movement
	float thrustSpeed;	//rate of change for our thrust

	float turn;			//turn
	float maxTurn;		//max turn
	float turnSpeed;	//rate of change for our turn

	float speed;		//movementspeed
public:
	void doThrust(float delta);
	void doTurn(float delta);

	void integrate(RigidBody &r);

};

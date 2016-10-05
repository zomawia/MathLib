#pragma once

#include "RigidBody.h"

class SpaceshipLocomotion
{
	
	
	float vThrust;		//foward movement				(0-1 value)
	float hThrust;
						//float maxThrust;	//max forward movement
	//float thrustSpeed;	//rate of change for our thrust
		
	float turn;			//turn							(-1 - 1 value)
	float maxTurn;		//max turn
	float turnSpeed;	//rate of change for our turn

	float speed;		//movementspeed
	float maxSpeed;

	float dirVectX;
	float dirVectY;

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);

	void update(RigidBody &r, float delta);

};

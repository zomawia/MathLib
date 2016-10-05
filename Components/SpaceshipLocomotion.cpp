#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include <cmath>

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vThrust = 0.0f;
	hThrust = 0.0f;
	//maxThrust = 10.0f;
	//thrustSpeed = 1.0f;

	turn = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 100.0f;

	speed = 10.0f;
	maxSpeed = 50.0f;
}

void SpaceshipLocomotion::doThrust(float value)
{
	vThrust = value;
	
	//if (sfw::getKey('W')) vThrust += 1;
	//if (sfw::getKey('S')) vThrust -= 1;
}

void SpaceshipLocomotion::doTurn(float value)
{
	turn = value;
	
	//if (sfw::getKey('A')) turn += 1;
	//if (sfw::getKey('D')) turn -= 1;
}

void SpaceshipLocomotion::update(RigidBody &r, float delta)
{
	dirVectX = cos(r.angle);
	dirVectY = sin(r.angle);
	
	r.accel.x += vThrust * dirVectX;
	r.accel.y += vThrust * dirVectY;

	if (magnitude(r.velocity) > maxSpeed) {
		vec2 dir = normal(r.velocity);
		r.velocity = dir * maxSpeed;
	}

	r.angularAccel = turn * turnSpeed;
	
	//inertia
	r.velocity *= 0.99f;

	//zero out the thrust values
	vThrust = 0.0f;
	turn = 0.0f;
	

}

#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include <cmath>

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vThrust = 0.0f;
	hThrust = 0.0f;

	turnSpeed = 4.0f;

	speed = 450.0f;
	maxSpeed = 600.0f;

	stopAction = 0.0f;
	brakePower = 6.0f;
}

void SpaceshipLocomotion::doThrust(float value)
{
	vThrust += value;
	
	//if (sfw::getKey('W')) vThrust += 1;
	//if (sfw::getKey('S')) vThrust -= 1;
}

void SpaceshipLocomotion::doTurn(float value)
{
	hThrust += value;
	
	//if (sfw::getKey('A')) turn += 1;
	//if (sfw::getKey('D')) turn -= 1;
}

void SpaceshipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::update(const Transform &trans, RigidBody &r)
{
	r.addForce(trans.getUp() * speed * vThrust);
	r.addTorque(hThrust * turnSpeed);

	r.addForce(-r.velocity * brakePower * stopAction);
	r.addTorque(-r.angularVelocity * brakePower * stopAction);

	hThrust = vThrust = stopAction = 0;
}

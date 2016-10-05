#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include <cmath>

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vThrust = 0.0f;
	hThrust = 0.0f;

	turnSpeed = 15.0f;

	speed = 250.0f;
	maxSpeed = 500.0f;

	stopAction = 0.0f;
	brakePower = 4.0f;
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
	r.addForce(trans.getDirection() * speed * vThrust);
	r.addTorque(hThrust * turnSpeed);

	r.addForce(-r.velocity * brakePower * stopAction);
	r.addTorque(-r.angularVelocity * brakePower * stopAction);

	//r.velocity *= 0.99f;
	//r.angularVelocity *= 0.9f;

	hThrust = vThrust = stopAction = 0;
}

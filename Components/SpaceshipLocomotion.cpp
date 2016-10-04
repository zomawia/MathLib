#include "SpaceshipLocomotion.h"

SpaceshipLocomotion::SpaceshipLocomotion()
{
	thrust = 0.0f;
	maxThrust = 10.0f;
	thrustSpeed = 1.0f;

	turn = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 1.0f;

	speed = 10.0f;
}

void SpaceshipLocomotion::doThrust(float delta)
{

}

void SpaceshipLocomotion::doTurn(float delta)
{

}

void SpaceshipLocomotion::integrate(RigidBody & r)
{

}

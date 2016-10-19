#include "PlanetaryMotor.h"

void PlanetaryMotor::update(RigidBody & planetRbody)
{
	planetRbody.addTorque(m_rotationSpeed);
}

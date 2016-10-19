#pragma once
#include "RigidBody.h"

class PlanetaryMotor {
public:
	float m_rotationSpeed;

	void update(RigidBody &planetRbody);
};


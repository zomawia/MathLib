#pragma once

#include "RigidBody.h"
#include "Collider.h"
#include "PlanetaryRenderer.h"

class Asteroid {
public:
	RigidBody rigidbody;
	Collider collider;
	Transform transform;
	PlanetaryRenderer render;

	Asteroid();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);

};
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

	unsigned int ball = sfw::loadTextureMap("../dep/ball.png");

	Asteroid();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);

};
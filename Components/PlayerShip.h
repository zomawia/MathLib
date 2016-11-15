#pragma once
#include "transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"

class PlayerShip {
public:
	Transform			transform;
	Collider			collider;
	RigidBody			rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;

	PlayerShip();

	void update(class GameState &gs, float deltaTime);
	void draw(const mat3 &camera);
};

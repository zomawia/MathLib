#pragma once
#include "ShipRenderer.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"
#include "Bullet.h"

class PlayerShip {
public:
	Transform			transform;
	Collider			collider;
	RigidBody			rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;
	ShipRenderer		shiprender;
	Bullet				bullet;


	PlayerShip();

	void update(class GameState &gs, float deltaTime);
	void draw(const mat3 &camera);
};

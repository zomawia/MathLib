#pragma once

#include "RigidBody.h"
#include "Collider.h"
#include "ShipRenderer.h"

class Bullet {
public:
	RigidBody rigidbody;
	Collider collider;
	Transform transform;
	ShipRenderer render;

	float timer;
	bool isAlive;

	Bullet();
	void update(class GameState &gs, float deltaTime);
	void draw(const mat3 &camera);

};
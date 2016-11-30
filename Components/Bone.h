#pragma once
#include "ShipRenderer.h"
#include "Collider.h"
#include "RigidBody.h"

class Bone {
public:
	Transform	transform;
	Collider	collider;
	RigidBody	rigidbody;

	bool isAlive;

	Bone();

	void update(class GameState &gs, float deltaTime);
	void draw(const mat3 &camera);

};
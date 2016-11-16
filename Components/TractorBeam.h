#pragma once
#include "Collider.h"
#include "ShipRenderer.h"

class TractorBeam {
public:
	Transform transform;
	Collider collider;
	ShipRenderer render;

	bool isAlive;
	bool oneFrame;

	TractorBeam();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};

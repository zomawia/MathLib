#pragma once

#include "Bone.h"

class Donald {
public:
	Bone head, larm, rarm, lleg, rleg, body, ship;
	Bone brick[20];

	unsigned int img_head;
	unsigned int img_part;
	unsigned int img_ship;

	Donald();
	void update(class GameState &gs, float deltaTime);
	void debugDraw(const mat3&camera);
	void draw(const mat3 &camera);
};
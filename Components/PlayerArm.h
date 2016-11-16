#pragma once
#include "Bone.h"

class PlayerArm {
public:
	Bone shoulder, upper, lower, hand;

	PlayerArm();
	void update(class GameState &gs, float deltaTime);
	void debugDraw(const mat3&camera);
	void draw(const mat3 &camera);
};

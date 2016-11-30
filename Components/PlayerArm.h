#pragma once
#include "Bone.h"

class PlayerArm {
public:
	Bone shoulder, upper, lower, hand;

	bool isGrabbing;
	bool isReset;
	bool isAir;
	
	unsigned int img_shoulder, img_upper, img_lower, img_hand, img_body;

	PlayerArm();
	void reset();
	void update(class GameState &gs, float deltaTime);
	void debugDraw(const mat3&camera);
	void draw(const mat3 &camera);
};

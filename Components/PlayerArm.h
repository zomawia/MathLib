#pragma once
#include "Bone.h"

class PlayerArm {
public:
	Bone shoulder, upper, lower, hand;

	bool isGrabbing;
	bool isReset;
	
	unsigned int img_shoulder = sfw::loadTextureMap("../dep/shoulder.png");
	unsigned int img_upper = sfw::loadTextureMap("../dep/upper.png");
	unsigned int img_lower = sfw::loadTextureMap("../dep/lower.png");
	unsigned int img_hand = sfw::loadTextureMap("../dep/hand.png");

	PlayerArm();
	void update(class GameState &gs, float deltaTime);
	void debugDraw(const mat3&camera);
	void draw(const mat3 &camera);
};

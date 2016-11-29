#pragma once

#include "Bone.h"

class Hoop {
public:
	Bone BasketL, BasketR, Pole, Net;

	unsigned int img_pole, img_net;

	Hoop();
	void update(class GameState &gs, float deltaTime);
	void debugDraw(const mat3&camera);
	void draw(const mat3 &camera);
};

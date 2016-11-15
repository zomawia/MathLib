#pragma once
#include "transform.h"
#include "mat3.h"

class Camera {
public:
	Transform transform;
	mat3 projection;

	Camera();
	mat3 getCameraMatrix();
	void update(class GameState &gs, float deltaTime);
	void debugDraw(const mat3 &camera);
};

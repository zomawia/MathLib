#include "Camera.h"
#include "Gamestate.h"

Camera::Camera(){
	projection = translate(vec2{ 600, 600 }) * scale(vec2{ 2, 2 });
}

mat3 Camera::getCameraMatrix(){
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(GameState &gs, float deltaTime){
	transform.m_position = gs.player.transform.getGlobalPosition();
}

void Camera::debugDraw(const mat3 & camera){
}

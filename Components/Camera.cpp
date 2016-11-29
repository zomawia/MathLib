#include "Camera.h"
#include "Gamestate.h"

Camera::Camera(){
	projection = translate(vec2{ 800, 800 }) * scale(vec2{ 3, 3 });
	transform.m_position = vec2{ 0,0 };
}

mat3 Camera::getCameraMatrix(){
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(GameState &gs, float deltaTime){
	transform.m_position = 	lerp(transform.m_position,
		(gs.player.shoulder.transform.getGlobalPosition() + 
			gs.mousePos)/2,
		deltaTime * 10);
}

void Camera::debugDraw(const mat3 & camera){
}

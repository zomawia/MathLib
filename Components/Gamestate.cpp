#include "Gamestate.h"

void GameState::play(){
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

}

void GameState::update(float deltaTime){
	player.update(*this, deltaTime);
	camera.update(*this, deltaTime);
}

void GameState::draw(){
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
}

#include "Gamestate.h"
#include "ObjectCollision.h"

void GameState::play(){
	asteroid.transform.m_position = { 600,400 };
}

void GameState::update(float deltaTime){
	mousePos = { sfw::getMouseX(), sfw::getMouseY() };
	
	player.update(*this, deltaTime);
	camera.update(*this, deltaTime);
	asteroid.update(deltaTime, *this);

	TractorAsteroidCollision(tractor, asteroid);

}

void GameState::draw(){
	mat3 cam = camera.getCameraMatrix();

	player.debugDraw(cam);
	asteroid.draw(cam);
	tractor.draw(cam);
}

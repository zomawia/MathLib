#include "Gamestate.h"
#include "ObjectCollision.h"
#include <cstdio>

void GameState::play(){
	asteroid.transform.m_position = { 505,400 };
}

void GameState::update(float deltaTime){
	mousePos = { sfw::getMouseX(), sfw::getMouseY() };
	
	player.update(*this, deltaTime);
	camera.update(*this, deltaTime);
	asteroid.update(deltaTime, *this);
	hoop.update(*this, deltaTime);

	TractorAsteroidCollision(tractor, asteroid);
	HoopAsteroidColl(hoop.Pole, asteroid);
	HoopAsteroidColl(hoop.BasketL, asteroid);
	HoopAsteroidColl(hoop.BasketR, asteroid);

	if (asteroid.transform.getGlobalPosition().y <= 100 || asteroid.transform.getGlobalPosition().x <= 100 ||
		asteroid.transform.getGlobalPosition().x >= 1200 || asteroid.transform.getGlobalPosition().y >= 1200
		) {
		player.isGrabbing = false;
		player.isReset = false;
		asteroid.transform.m_position = { 475,350 };
		asteroid.rigidbody.velocity = { 0,0 };
	}
}

void GameState::draw(){
	mat3 cam = camera.getCameraMatrix();

	player.debugDraw(cam);
	player.draw(cam);
	asteroid.draw(cam);
	tractor.draw(cam);
	hoop.debugDraw(cam);

	//printf("ast.pos:%f, %f, ---- global:%f, %f\n, ",		
	//	asteroid.transform.m_position.x, asteroid.transform.m_position.y,
	//	asteroid.transform.getGlobalPosition().x, asteroid.transform.getGlobalPosition().y
	//	);
}

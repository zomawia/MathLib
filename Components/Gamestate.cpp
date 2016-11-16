#include "Gamestate.h"
#include "ObjectCollision.h"

void GameState::play(){
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	asteroid[0].transform.m_position = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulse(vec2{ 150,150 });
	asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -150,-150 });
	asteroid[1].rigidbody.addTorque(-24);

}

void GameState::update(float deltaTime){
	player.update(*this, deltaTime);
	camera.update(*this, deltaTime);

	for (int i = 0; i < 2; ++i) {
		asteroid[i].update(deltaTime, *this);
	}

	for (int i = 0; i < 2; ++i) {
		playerAsteroidColl(player, asteroid[i]);
	}

	for (int i = 0; i < 2; ++i)
		for (int j=i+1; j <2; ++j)
			asteroidColl(asteroid[i], asteroid[j]);
	
	for (int i = 0; i < 2; ++i)
		TractorAsteroidCollision(tractor, asteroid[i]);

}

void GameState::draw(){
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);

	for (int i = 0; i < 2; i++) {
		asteroid[i].draw(cam);
	}
	tractor.draw(cam);
}

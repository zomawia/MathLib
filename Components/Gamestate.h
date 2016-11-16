#pragma once
#include "Camera.h"
#include "PlayerShip.h"
#include "Asteroid.h"
#include "TractorBeam.h"

class GameState {
public:
	PlayerShip player;
	Camera camera;
	TractorBeam tractor;
	Asteroid asteroid[4];
	Bullet bullet;
	
	// init, play, term, step, draw
	
	void play();
	void update(float deltaTime); //equiv of draw
	void draw();
};
#pragma once
#include "Camera.h"
#include "PlayerShip.h"

class GameState {
public:
	PlayerShip player;
	Camera camera;
	
	// init, play, term, step, draw
	
	void play();
	void update(float deltaTime); //equiv of draw
	void draw();
};
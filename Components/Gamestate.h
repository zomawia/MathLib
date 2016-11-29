#pragma once
#include "Camera.h"
#include "PlayerArm.h"
#include "TractorBeam.h"
#include "Asteroid.h"
#include "Hoop.h"

class GameState {
public:
	Camera camera;
	PlayerArm player;
	Asteroid asteroid;
	TractorBeam tractor;
	Hoop hoop;

	vec2 mousePos;
	
	// init, play, term, step, draw
	
	void play();
	void update(float deltaTime); //equiv of draw
	void draw();
};
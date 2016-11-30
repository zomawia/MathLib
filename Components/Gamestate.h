#pragma once
#include "Camera.h"
#include "PlayerArm.h"
#include "TractorBeam.h"
#include "Asteroid.h"
#include "Hoop.h"
#include "Donald.h"

class GameState {
public:
	Camera camera;
	PlayerArm player;
	Asteroid asteroid;
	TractorBeam tractor;
	Hoop hoop;
	Donald donald;
	Transform background;

	vec2 mousePos;

	int score;
	float time;
	
	unsigned int afont;
	unsigned int img_background;

	// init, play, term, step, draw
	
	void play();
	void update(float deltaTime); //equiv of draw
	void draw();
};
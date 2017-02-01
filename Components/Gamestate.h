#pragma once
#include "Camera.h"
#include "PlayerArm.h"
#include "TractorBeam.h"
#include "Asteroid.h"
#include "Hoop.h"
#include "Donald.h"
#include "ParticleSpawner.h"

class GameState {
public:
	Camera camera;
	PlayerArm player;
	Asteroid asteroid;
	TractorBeam tractor;
	Hoop hoop;
	Donald donald;
	Transform background;

	ParticleSpawner factory;

	vec2 mousePos;
	vec2 start;
	vec2 gravity;

	int score, brickCount;
	float time;

	
	unsigned int afont;
	unsigned int img_background;
	unsigned int img_slam;

	// init, play, term, step, draw
	
	void play();
	void update(float deltaTime); //equiv of draw
	void draw();
};
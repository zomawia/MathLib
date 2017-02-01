// donald trump spawner
// by zomawia sailo
// <zomawia@gmail.com>

#include "sfwdraw.h"
#include "Particle.h"
#include "ParticleSpawner.h"
#include <iostream>
#include "Camera.h"
#include "Gamestate.h"

void main()
{
	float SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);	

	GameState gs;

	while (sfw::stepContext()) {
		float time = sfw::getDeltaTime();

		gs.update(time);
		gs.draw();
	}

	sfw::termContext();
}
// donald trump spawner
// by zomawia sailo
// <zomawia@gmail.com>

#include "sfwdraw.h"
#include "Particle.h"
#include "ParticleSpawner.h"
#include <iostream>
#include "Camera.h"

void main()
{
	float SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);	

	ParticleSpawner spwnd;
	Camera camera;

	mat3 cam = camera.getCameraMatrix();

	while (sfw::stepContext()) {
		float time = sfw::getDeltaTime();
		spwnd.update(time);
		spwnd.draw(cam);
	}

	sfw::termContext();
}
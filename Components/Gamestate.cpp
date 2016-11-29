#include "Gamestate.h"
#include "ObjectCollision.h"
#include <cstdio>

void GameState::play(){
	asteroid.transform.m_position = { 505,400 };
	afont = sfw::loadTextureMap("../dep/uglyfont.png", 16, 16);
	background.m_position = vec2{ 600,600 };
	background.m_scale = vec2{ 10,10 };
	img_background = sfw::loadTextureMap("../dep/background.png");
}

void GameState::update(float deltaTime){
	mousePos = { sfw::getMouseX(), sfw::getMouseY() };
	
	donald.update(*this, deltaTime);

	player.update(*this, deltaTime);
	camera.update(*this, deltaTime);
	asteroid.update(deltaTime, *this);
	hoop.update(*this, deltaTime);

	TractorAsteroidCollision(tractor, asteroid);
	HoopAsteroidColl(hoop.Pole, asteroid);
	HoopAsteroidColl(hoop.BasketL, asteroid);
	HoopAsteroidColl(hoop.BasketR, asteroid);

	DonaldAsteroidColl(donald.ship, asteroid);
	DonaldAsteroidColl(donald.body, asteroid);
	DonaldAsteroidColl(donald.head, asteroid);
	DonaldAsteroidColl(donald.larm, asteroid);
	DonaldAsteroidColl(donald.rarm, asteroid);

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

	mat3 backCam = cam * background.getGlobalTransform();

	//sfw::drawTextureMatrix3(img_background, 0, WHITE, (backCam * scale(vec2{ 75.0f ,50.0f })).m);

	sfw::drawString(afont, "sportsBall", 25, 1050, 32, 32, 0, 0, GREEN);
	sfw::drawString(afont, "use mouse to move camera", 30, 1000, 15, 15, 0, 0, WHITE);
	sfw::drawString(afont, "A and S to flex", 30, 980, 15, 15, 0, 0, WHITE);
	sfw::drawString(afont, "Q and W to rotate arm", 30, 960, 15, 15, 0, 0, WHITE);

	sfw::drawString(afont, "left click ->  pick up ball", 30, 930, 15, 15, 0, 0, WHITE);
	sfw::drawString(afont, "right click -> shoot", 30, 910, 16, 15, 0, 0, WHITE);

	

	//donald.debugDraw(cam);
	donald.draw(cam);

	player.debugDraw(cam);
	player.draw(cam);
	asteroid.draw(cam);
	tractor.draw(cam);
	hoop.debugDraw(cam);
	hoop.draw(cam);

	

	//printf("ast.pos:%f, %f, ---- global:%f, %f\n, ",		
	//	asteroid.transform.m_position.x, asteroid.transform.m_position.y,
	//	asteroid.transform.getGlobalPosition().x, asteroid.transform.getGlobalPosition().y
	//	);
}

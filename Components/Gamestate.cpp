#include "Gamestate.h"
#include "ObjectCollision.h"
#include <cstdio>
#include <string>

void GameState::play(){
	asteroid.transform.m_position = { 505,400 };
	afont = sfw::loadTextureMap("../dep/uglyfont.png", 16, 16);
	background.m_position = vec2{ 600,600 };
	background.m_scale = vec2{ 10,10 };
	img_background = sfw::loadTextureMap("../dep/background.png");

	score = 0;
	time = 0.0f;
}

void GameState::update(float deltaTime){
	mousePos = { sfw::getMouseX(), sfw::getMouseY() };
	
	time += deltaTime;

	if (score > 0) {
		donald.update(*this, deltaTime);
		DonaldAsteroidColl(donald.ship, asteroid);
		DonaldAsteroidColl(donald.body, asteroid);
		DonaldAsteroidColl(donald.head, asteroid);
		DonaldAsteroidColl(donald.larm, asteroid);
		DonaldAsteroidColl(donald.rarm, asteroid);
	}

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

	if (time > 10) hoop.hitDetector.isAlive = true;

	if (BoneAsteroidScoreHitDetectorCounterWhenCollisionHappens(hoop.hitDetector, asteroid) && hoop.hitDetector.isAlive){
		score++;
		time = 0.0f;
		hoop.hitDetector.isAlive = false;
		//function call display sprites

	}

}

void GameState::draw(){
	mat3 cam = camera.getCameraMatrix();

	mat3 backCam = cam * background.getGlobalTransform();

	sfw::drawTextureMatrix3(img_background, 0, WHITE, (backCam * scale(vec2{ 75.0f ,50.0f })).m);

	sfw::drawString(afont, "sportsBall", 25, 300, 32, 32, 0, 0, GREEN);
	sfw::drawString(afont, "use mouse to move camera", 30, 260, 15, 15, 0, 0, WHITE);
	sfw::drawString(afont, "A and S to flex", 30, 240, 15, 15, 0, 0, WHITE);
	sfw::drawString(afont, "Q and W to rotate arm", 30, 220, 15, 15, 0, 0, WHITE);

	sfw::drawString(afont, "left click ->  pick up ball", 30, 200, 15, 15, 0, 0, WHITE);
	sfw::drawString(afont, "right click -> shoot", 30, 180, 16, 15, 0, 0, WHITE);

	sfw::drawString(afont, "swisheds", 1750, 150, 18, 18, 0, 0, GREEN);
	sfw::drawString(afont, std::to_string(score).c_str(), 1760, 130, 28, 28, 0, 0, GREEN);

	//donald.debugDraw(cam);
	if (score > 0) donald.draw(cam);

	if (!hoop.hitDetector.isAlive && time < 10) sfw::drawString(afont, "sportsBall SLAMMAJAM!", 300, 600, 64, 64, 0, 0, YELLOW);
	

	//player.debugDraw(cam);
	player.draw(cam);
	asteroid.draw(cam);
	tractor.draw(cam);
	hoop.debugDraw(cam);
	hoop.draw(cam);

}

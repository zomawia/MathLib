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
	img_slam = sfw::loadTextureMap("../dep/slam.png");

	brickCount = 0;
	score = 0;
	time = 0.0f;
	start = { 400, 400 };
	gravity = { 0, -120.f };
}

void GameState::update(float deltaTime){
	
	mousePos = { sfw::getMouseX(), sfw::getMouseY() };
	
	time += deltaTime;

	if (score > 2) {		
		donald.update(*this, deltaTime);
		DonaldAsteroidColl(donald.ship, asteroid);
		DonaldAsteroidColl(donald.body, asteroid);
		DonaldAsteroidColl(donald.head, asteroid);
		DonaldAsteroidColl(donald.larm, asteroid);
		DonaldAsteroidColl(donald.rarm, asteroid);
		donald.brick[brickCount].isAlive = true;
	}

	player.update(*this, deltaTime);
	camera.update(*this, deltaTime);
	asteroid.update(deltaTime, *this);
	hoop.update(*this, deltaTime);

	TractorAsteroidCollision(tractor, asteroid);
	HoopAsteroidColl(hoop.Pole, asteroid);
	HoopAsteroidColl(hoop.BasketL, asteroid);
	HoopAsteroidColl(hoop.BasketR, asteroid);	

	// brick collision
	for (int i = 0; i < 20; ++i)
		for (int j = 0; i < 20; ++i)
			//if (donald.brick[i].isAlive && donald.brick[j].isAlive)
			BoneBoneCollisionUsedForDonaldTrumpDroppingDownTrumpWalls(donald.brick[i], donald.brick[j]);

	//brick drop
	if (donald.body.transform.getGlobalPosition().x == 700) {		
		donald.brick[brickCount].rigidbody.addForce(gravity);
		brickCount++;
	}

	if (brickCount > 19) brickCount = 19;


	if (asteroid.transform.getGlobalPosition().y <= 100 || asteroid.transform.getGlobalPosition().x <= 100 ||
		asteroid.transform.getGlobalPosition().x >= 1200 || asteroid.transform.getGlobalPosition().y >= 1000
		) {
		player.isGrabbing = false;
		player.isReset = false;
		asteroid.transform.m_position = { 475,350 };
		asteroid.rigidbody.velocity = { 0,0 };

		player.shoulder.transform.m_position = start;
		player.shoulder.rigidbody.velocity = { 0,0 };
	}
	
	if (time > 3) {
		hoop.hitDetector.isAlive = true;
		hoop.Pole.isAlive = true;
	}


	if (BoneAsteroidScoreHitDetectorCounterWhenCollisionHappens(hoop.hitDetector, asteroid) && hoop.hitDetector.isAlive){
		score++;
		time = 0.0f;
		hoop.hitDetector.isAlive = false;
	}

	if (BoneAsteroidScoreHitDetectorCounterWhenCollisionHappens(hoop.Pole, asteroid)) {
		time = 0.0f;
		hoop.Pole.isAlive = false;
	}

	factory.update(time, *this);

}

void GameState::draw(){
	mat3 cam = camera.getCameraMatrix();

	mat3 backCam = cam * background.getGlobalTransform();

	//sfw::drawTextureMatrix3(img_background, 0, WHITE, (backCam * scale(vec2{ 75.0f ,50.0f })).m);

	//sfw::drawString(afont, "sportsBall", 25, 300, 34, 34, 0, 0, GREEN);
	//sfw::drawString(afont, "use mouse to move camera", 30, 260, 18, 18, 0, 0, WHITE);	
	//sfw::drawString(afont, "Q and W to rotate shoulder arm", 30, 220, 18, 18, 0, 0, WHITE);
	//sfw::drawString(afont, "A and S to flex/unflex", 30, 240, 18, 18, 0, 0, WHITE);

	//sfw::drawString(afont, "left click ->  pick up ball", 30, 200, 18, 18, 0, 0, WHITE);	

	//sfw::drawString(afont, "line up your sportsball and then press right click", 30, 140, 15, 15, 0, 0, GREEN);

	//sfw::drawString(afont, "swishedses", 1730, 150, 20, 20, 0, 0, GREEN);
	//sfw::drawString(afont, std::to_string(score).c_str(), 1760, 130, 28, 28, 0, 0, GREEN);

	if (score > 2) donald.draw(cam);	

	player.draw(cam);
	asteroid.draw(cam);
	tractor.draw(cam);
	
	hoop.draw(cam);
	hoop.debugDraw(cam);


	if (!hoop.hitDetector.isAlive && time < 10) {
		sfw::drawTexture(img_slam, 240, 550, 128, 128);
		sfw::drawString(afont, "sportsBall SLAMMAJAM!", 300, 600, 64, 64, 0, 0, YELLOW);
		sfw::drawTexture(img_slam, 1690, 550, 128, 128);
	}

	factory.draw(cam);
}

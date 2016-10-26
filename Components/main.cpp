#include "sfwdraw.h"
#include "vec2.h"
#include "transform.h"
#include "flops.h"
#include <cmath>
#include <cstdio>
#include "RigidBody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "mat3.h"
#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"
#include "ShipRenderer.h"
#include "shapedraw.h"

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Transform playerTransform(300, 300);
	playerTransform.m_scale = vec2{ 10,10 };
	RigidBody playerRigidBody;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCtrl;
	ShipRenderer playerRenderer(WHITE);

	//Transform ST1(50, 0);
	//Transform ST2(50, 0);
	//Transform ST3(50, 0);
	//Transform ST4(50, 0);
	//Transform tank(12, -8);
	//vec2 WP1 = { 15,18 };
	//vec2 WP2 = { 5,8 };
	//vec2 WP3 = { -22, -5 };
	//vec2 WP4 = { 4, -2 };
	//vec2 WP5 = { -6,9 };
	//vec2 WP6 = { 18,88 };	
	//vec2 WP7 = { -22,-90 }; 
	//float dist = 0;
	//// 306
	//dist += distance(tank.m_position, WP1);
	//dist += distance(WP1, WP6);
	//dist += distance(WP6, WP2);
	//dist += distance(WP2, WP4);
	//dist += distance(WP4, WP7);
	//dist += distance(WP7, WP5);
	//dist += distance(WP5, WP3);
	//printf("%f\n", dist);
	//// 293
	//dist = 0;
	//dist += distance(tank.m_position, WP4);
	//dist += distance(WP4, WP2);
	//dist += distance(WP2, WP1);
	//dist += distance(WP1, WP6);
	//dist += distance(WP6, WP5);
	//dist += distance(WP5, WP3);
	//dist += distance(WP3, WP7);
	//printf("%f", dist);
	//mat3 RES = translate(vec2{ 12, -8 }) * rotation(deg2rad(80));
	//vec2 POI1 = { -4,-4 };
	//vec2 POI2 = { 21,45 };
	//vec2 POI3 = { 7, -2148 };
	//vec2 POI4 = { 0,0 };

	// Sun
	Transform sunTransform;
	sunTransform.m_position = vec2{ (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) };
	RigidBody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = .2;
	PlanetaryRenderer sunRenderer(YELLOW, 50);

	// Planet
	Transform plan1;
	plan1.m_position = vec2{ 120, 0 };
	plan1.m_parent = &sunTransform;
	RigidBody plan1RB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = 3;
	PlanetaryRenderer plan1renderer(GREEN, 7);

	// Moon
	Transform moon1;
	moon1.m_position = vec2{ 15, 0 };
	moon1.m_parent = &plan1;
	RigidBody moon1RB;
	PlanetaryMotor moon1motor;
	moon1motor.m_rotationSpeed = 15;
	PlanetaryRenderer moon1renderer(WHITE, 2);

	//ST1.m_parent = &playerTransform;
	//ST2.m_parent = &ST1;
	//ST3.m_parent = &ST2;
	//ST4.m_parent = &ST3;

	Transform cameraTransform;

	//float gravity = 9.8f;
	//signed int boneSelection = 0;
	vec2 cameraPosition = { 0,0 };

	while (sfw::stepContext())	{			
		float time = sfw::getDeltaTime();

		//// wrap
		//if (playerTransform.m_position.x > SCREEN_WIDTH) playerTransform.m_position.x = 0.0f;
		//else if (playerTransform.m_position.x < 0.0f) playerTransform.m_position.x = SCREEN_WIDTH;
		//if (playerTransform.m_position.y > SCREEN_HEIGHT) playerTransform.m_position.y = 0.0f;
		//else if (playerTransform.m_position.y < 0.0f) playerTransform.m_position.y = SCREEN_HEIGHT;		
		//boneSelection += sfw::getKey('E');
		//if (boneSelection > 4) boneSelection = 0;
		//boneSelection -= sfw::getKey('Q');
		//if (boneSelection < 0) boneSelection = 4;	
		//switch (boneSelection)
		//{
		//case 0:
		//	playerLoco.update(playerTransform, playerRigidBody);
		//	playerRigidBody.integrate(playerTransform, time);
		//	break;
		//case 1:
		//	playerLoco.update(ST1, playerRigidBody);
		//	playerRigidBody.integrate(ST1, time);
		//	break;
		//case 2:
		//	playerLoco.update(ST2, playerRigidBody);
		//	playerRigidBody.integrate(ST2, time);
		//	break;
		//case 3:
		//	playerLoco.update(ST3, playerRigidBody);
		//	playerRigidBody.integrate(ST3, time);
		//	break;
		//case 4:
		//	playerLoco.update(ST4, playerRigidBody);
		//	playerRigidBody.integrate(ST4, time);
		//	break;
		//default:
		//	playerLoco.update(playerTransform, playerRigidBody);
		//	playerRigidBody.integrate(playerTransform, time);
		//}

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidBody);
		playerRigidBody.integrate(playerTransform, time);

		// Draw the player

		// Update Logic
		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);

		
		moon1RB.integrate(moon1, time);
		plan1RB.integrate(plan1, time);
		sunRbody.integrate(sunTransform, time);

		vec2 gp = playerTransform.getGlobalPosition();
		
		// Use Lerp to chase the players ship
		cameraTransform.m_position
			= lerp(cameraTransform.m_position,
				(playerTransform.getGlobalPosition() + sunTransform.getGlobalPosition())/2,
				sfw::getDeltaTime() * 10);

		// translation is the position of the camera on the screen
		// the scale describes the zoom
		mat3 proj = translate(vec2{ 600, 600 }) * scale(vec2{ 2,2 });
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;


		// Render Drawing
		playerRenderer.draw(playerTransform, camera);
		sunRenderer.draw(sunTransform, camera);
		plan1renderer.draw(plan1, camera);
		moon1renderer.draw(moon1, camera);



		// Debug Drawing

		playerTransform.debugDraw(camera);
		//playerRigidBody.debugDraw(playerTransform, camera);
		//sunRbody.debugDraw(sunTransform, camera);
		//sunTransform.debugDraw(camera);		
		//plan1.debugDraw(camera);
		//moon1.debugDraw(camera);
		//cameraTransform.debugDraw(camera);
		
	}

	sfw::termContext();
}
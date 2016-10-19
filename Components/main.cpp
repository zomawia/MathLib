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

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	//Transform playerTransform(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	//Transform ST1(50, 0);
	//Transform ST2(50, 0);
	//Transform ST3(50, 0);
	//Transform ST4(50, 0);

	Transform tank(12, -8);

	vec2 WP1 = { 15,18 };
	vec2 WP2 = { 5,8 };
	vec2 WP3 = { -22, -5 };
	vec2 WP4 = { 4, -2 };
	vec2 WP5 = { -6,9 };
	vec2 WP6 = { 18,88 };	
	vec2 WP7 = { -22,-90 }; 

	float dist = 0;
	// 306
	dist += distance(tank.m_position, WP1);
	dist += distance(WP1, WP6);
	dist += distance(WP6, WP2);
	dist += distance(WP2, WP4);
	dist += distance(WP4, WP7);
	dist += distance(WP7, WP5);
	dist += distance(WP5, WP3);
	printf("%f\n", dist);

	// 293
	dist = 0;
	dist += distance(tank.m_position, WP4);
	dist += distance(WP4, WP2);
	dist += distance(WP2, WP1);
	dist += distance(WP1, WP6);
	dist += distance(WP6, WP5);
	dist += distance(WP5, WP3);
	dist += distance(WP3, WP7);
	printf("%f", dist);

	mat3 RES = translate(vec2{ 12, -8 }) * rotation(deg2rad(80));

	vec2 POI1 = { -4,-4 };
	vec2 POI2 = { 21,45 };
	vec2 POI3 = { 7, -2148 };
	vec2 POI4 = { 0,0 };

	//Transform sunTransform;
	//sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
	//RigidBody sunBody;
	//PlanetaryMotor sunMotor;
	//sunMotor.m_rotationSpeed = 5;

	//Transform plan1;
	//plan1.m_position = vec2{ 100,0 };
	//plan1.m_parent = &sunTransform;

	//Transform moon1;
	//moon1.m_position = vec2{ 20,0 };
	//moon1.m_parent = &plan1;

	//ST1.m_parent = &playerTransform;
	//ST2.m_parent = &ST1;
	//ST3.m_parent = &ST2;
	//ST4.m_parent = &ST3;

	//RigidBody playerRigidBody;
	//SpaceshipLocomotion playerLoco;
	//SpaceshipController playerCtrl;

	//playerRigidBody.velocity = vec2{ 0,0 };
	//float gravity = 9.8f;
	//signed int boneSelection = 0;

	sfw::initContext();
	

	while (sfw::stepContext())	{			
		float time = sfw::getDeltaTime();

		//// wrap
		//if (playerTransform.m_position.x > SCREEN_WIDTH) playerTransform.m_position.x = 0.0f;
		//else if (playerTransform.m_position.x < 0.0f) playerTransform.m_position.x = SCREEN_WIDTH;
		//if (playerTransform.m_position.y > SCREEN_HEIGHT) playerTransform.m_position.y = 0.0f;
		//else if (playerTransform.m_position.y < 0.0f) playerTransform.m_position.y = SCREEN_HEIGHT;
		//
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

		//playerCtrl.update(playerLoco);		
		//playerRigidBody.debugDraw(playerTransform);
		//
		//playerTransform.debugDraw();
		//ST1.debugDraw();
		//ST2.debugDraw();
		//ST3.debugDraw();
		//ST4.debugDraw();	
		
		//sunTransform.debugDraw();
		//sunBody.integrate(sunTransform, time);
		//sunMotor.update(sunBody);
		
	}

	sfw::termContext();
}
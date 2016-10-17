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

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Transform playerTransform(400,400,12,12);
	RigidBody playerRigidBody;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCtrl;

	playerRigidBody.velocity = vec2{ 0,0 };
	float gravity = 9.8f;

	sfw::initContext();
	
	while (sfw::stepContext())
	{			
		float time = sfw::getDeltaTime();

		// wrap
		if (playerTransform.m_position.x > SCREEN_WIDTH) playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f) playerTransform.m_position.x = SCREEN_WIDTH;
		if (playerTransform.m_position.y > SCREEN_HEIGHT) playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f) playerTransform.m_position.y = SCREEN_HEIGHT;

		playerLoco.update(playerTransform, playerRigidBody);
		playerRigidBody.integrate(playerTransform, time);
		playerCtrl.update(playerLoco);

		playerTransform.debugDraw();
		playerRigidBody.debugDraw(playerTransform);

		
	}

	sfw::termContext();
}
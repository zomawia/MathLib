#include "sfwdraw.h"
#include "vec2.h"
#include "transform.h"
#include "flops.h"
#include <cmath>
#include <cstdio>
#include "RigidBody.h"

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Transform playerTransform(400,400,12,12);
	RigidBody playerRigidBody;
	playerRigidBody.velocity = vec2{ 0,0 };
	float gravity = 9.8f;

	sfw::initContext();
	
	while (sfw::stepContext())
	{	
		float time = sfw::getDeltaTime();

		
		// change rigidbody velocity according to input
		if (sfw::getKey('W')) playerRigidBody.accel.y += 2.0f;
		if (sfw::getKey('S')) playerRigidBody.accel.y -= 2.0f;
		if (sfw::getKey('A')) playerRigidBody.accel.x -= 2.0f;
		if (sfw::getKey('D')) playerRigidBody.accel.x += 2.0f;

		if (sfw::getKey('Q')) playerRigidBody.angularAccel += 2.0f;
		if (sfw::getKey('E')) playerRigidBody.angularAccel -= 2.0f;

		if (sfw::getKey(KEY_UP)) playerTransform.scale.x += 1.0f;
		if (sfw::getKey(KEY_DOWN)) playerTransform.scale.x -= 1.0f;
		if (sfw::getKey(KEY_RIGHT)) playerTransform.scale.y += 1.0f;
		if (sfw::getKey(KEY_LEFT) && playerTransform.scale.y >= 4) playerTransform.scale.y -= 1.0f;

		// wrap
		if (playerTransform.position.x > SCREEN_WIDTH) playerTransform.position.x = 0.0f;
		else if (playerTransform.position.x < 0.0f) playerTransform.position.x = SCREEN_WIDTH;

		if (playerTransform.position.y > SCREEN_HEIGHT) playerTransform.position.y = 0.0f;
		else if (playerTransform.position.y < 0.0f) playerTransform.position.y = SCREEN_HEIGHT;


		// apply rigidbody forces
		playerRigidBody.integrate(playerTransform, time);

		// draw the player
		playerTransform.debugDraw();
		
		for (int i = 0; i < 100; ++i)
		{			
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;
			
			// example
			/*float y1 = linearHalf(x1);		
			float y2 = linearHalf(x2);*/

			//a
			/*float y1 = growFast(x1);
			float y2 = growFast(x2);*/

			//b
			/*float y1 = growSlow(x1);
			float y2 = growSlow(x2);*/

			//c
			/*float y1 = hardAngle(x1);
			float y2 = hardAngle(x2);*/

			//d
			/*float y1 = bounceFlip(x1);
			float y2 = bounceFlip(x2);*/

			//e
			/*float y1 = parabFlip(x1);
			float y2 = parabFlip(x2);*/


			/*float y1 = lerp(0, .5f, x1);
			float y2 = lerp(0, .5f, x2);*/
		
			/*float y1 = quadBezier(.25f, 0, 1, x1);
			float y2 = quadBezier(.25f, 0, 1, x2);*/

			/*float y1 = hermiteSpline(1, 1, 0, 1, x1);
			float y2 = hermiteSpline(1, 1, 0, 1, x2);*/

			//float y1 = cardinalSpline(.0f, .5f, 1, time, x1);
			//float y2 = cardinalSpline(.0f, .5f, 1, time, x2);

			//printf("%f \n", time);

			float y1 = catRomSpline(.25f, .75f, 1, x1);
			float y2 = catRomSpline(.25f, .75f, 1, x2);

			x1 *= 800;
			x2 *= 800;
			y1 *= 600;
			y2 *= 600;

			//sfw::drawLine(x1, y1, x2, y2, WHITE);
			//sfw::drawCircle(x2, y2, 12, 12, GREEN);
		}
	}

	sfw::termContext();
}
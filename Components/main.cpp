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
#include "Collider.h"

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Transform playerTransform(100, 100);
	playerTransform.m_scale = vec2{ 5,5 };
	RigidBody playerRigidBody;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCtrl;
	ShipRenderer playerRenderer(WHITE);
	
	//setup collider
	vec2 hullVerts[] = { {0,3}, {-2,-3}, {2,-3} };
	Collider playerCollider(hullVerts, 3);
	Transform occluderTransform(500,500);	
	occluderTransform.m_scale = vec2{ 8,8 };
	Collider occluderCollider(hullVerts, 3);
	RigidBody occluderRigidBody;


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

	Transform cameraTransform;
	
	vec2 cameraPosition = { 0,0 };

	while (sfw::stepContext())	{			
		float time = sfw::getDeltaTime();

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidBody);
		playerRigidBody.integrate(playerTransform, time);
		occluderRigidBody.integrate(occluderTransform, time);

		// Update Logic
		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);		
		moon1RB.integrate(moon1, time);
		plan1RB.integrate(plan1, time);
		sunRbody.integrate(sunTransform, time);

		vec2 gp = playerTransform.getGlobalPosition();
		
		// Use Lerp to chase the players ship
		//cameraTransform.m_position
		//	= lerp(cameraTransform.m_position,
		//		(playerTransform.getGlobalPosition() + sunTransform.getGlobalPosition())/2,
		//		sfw::getDeltaTime() * 10);

		cameraTransform.m_position = playerTransform.getGlobalPosition();

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
		playerCollider.DebugDraw(camera, playerTransform);		
		
		occluderTransform.debugDraw(camera);		
		occluderCollider.DebugDraw(camera, occluderTransform);
		
		//StaticResolution(playerTransform, playerRigidBody, playerCollider, 
		//				 occluderTransform, occluderCollider);
		DynamicResolution(playerTransform, playerRigidBody, playerCollider,
			occluderTransform, occluderRigidBody, occluderCollider);

		//printf("%f %f %f\n", results.penetrationDepth, results.collisionNormal.x, results.collisionNormal.y);
		
	}

	sfw::termContext();
}
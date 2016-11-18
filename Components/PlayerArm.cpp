#include "PlayerArm.h"
#include "Gamestate.h"
#include "sfwdraw.h"
#include "ObjectCollision.h"
#include <cstdio>

PlayerArm::PlayerArm()
{
	vec2 shoulderVerts[] = { { 1,1 },{ 1,-1 },{ -1,-1 },{-1,1}};
	vec2 upperVerts[] = { { -1,0 },{ 1,0 },{ .5f,-4 },{ -.5f,-4 } };
	vec2 lowerVerts[] = { { -.5f,0 },{ .5f,0 },{ .5f,-4 },{ -.5f,-4 } };
	vec2 handVerts[] = { { -.5f,0 },{ .5f,0 },{ .5f,-1 },{ -.5f,-1 } };
	
	//red
	shoulder.transform.m_facing = 0;
	shoulder.transform.m_position = vec2{ 400, 400 };
	shoulder.transform.m_scale = vec2{ 20,20 };
	shoulder.collider = Collider(shoulderVerts, 4);	

	//white
	upper.transform.m_parent = &shoulder.transform;
	upper.transform.m_position = vec2{0, 0 };
	upper.collider = Collider(upperVerts, 4);

	//blue
	lower.transform.m_parent = &upper.transform;
	lower.transform.m_position = vec2{ 0 , -4 };
	lower.collider = Collider(lowerVerts, 4);	
	
	//yellow	
	hand.transform.m_parent = &lower.transform;
	hand.transform.m_position = vec2{ 0,-4 };
	hand.collider = Collider(handVerts, 4);
}

void PlayerArm::update(GameState &gs, float deltaTime)
{
	gs.tractor.transform.m_parent = &hand.transform;

	shoulder.update(gs, deltaTime);
	upper.update(gs, deltaTime);
	lower.update(gs, deltaTime);
	hand.update(gs, deltaTime);

	playerAsteroidColl(hand, gs.asteroid);
	//playerAsteroidColl(shoulder, gs.asteroid);
	//playerAsteroidColl(upper, gs.asteroid);
	//playerAsteroidColl(lower, gs.asteroid);


	//if (shoulder.transform.m_facing <= -0.4f) shoulder.transform.m_facing = -0.4f;
	//if (shoulder.transform.m_facing >= 3.1f) shoulder.transform.m_facing = 3.1f;

	/* NEED TO MAKE A CONTROLLER */

	if (upper.transform.m_facing <= -0.4f) upper.transform.m_facing = -0.3f;
	if (upper.transform.m_facing >= 3.1f) upper.transform.m_facing = 3.1f;

	if (lower.transform.m_facing <= 0) lower.transform.m_facing = 0;
	if (lower.transform.m_facing >= 2.7f) lower.transform.m_facing = 2.7f;

	//if (sfw::getKey('Q')) shoulder.rigidbody.addTorque(5);
	//if (sfw::getKey('W')) shoulder.rigidbody.addTorque(-5);
	
	if (sfw::getKey('A')) upper.rigidbody.addTorque(5);
	if (sfw::getKey('S')) upper.rigidbody.addTorque(-5);

	if (sfw::getKey('Z')) lower.rigidbody.addTorque(5);
	if (sfw::getKey('X')) lower.rigidbody.addTorque(-5);

	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT)){
		gs.tractor.isAlive = true; // reset the beam
		gs.tractor.oneFrame = false;

		// have it look where we are looking
		
		//gs.tractor.transform.m_position = hand.transform.m_position;
		gs.tractor.transform.m_facing = hand.transform.m_facing;
	}
	else gs.tractor.isAlive = false;

}

void PlayerArm::debugDraw(const mat3 & camera)
{
	shoulder.rigidbody.debugDraw(camera, shoulder.transform);
	
	shoulder.transform.debugDraw(camera);

	shoulder.collider.DebugDraw(camera, shoulder.transform, RED);
	upper.collider.DebugDraw(camera, upper.transform, WHITE);
	lower.collider.DebugDraw(camera, lower.transform, BLUE);
	hand.collider.DebugDraw(camera, hand.transform, YELLOW);

	//printf("shoulder:%f, upper:%f, lower: %f\n",shoulder.transform.m_facing, upper.transform.m_facing, lower.transform.m_facing);
	
}

void PlayerArm::draw(const mat3 & camera)
{
}

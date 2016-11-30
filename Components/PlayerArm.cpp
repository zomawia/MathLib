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
	
	//shoulder red
	shoulder.transform.m_facing = 0;
	shoulder.transform.m_position = vec2{ 400, 400 };
	shoulder.transform.m_scale = vec2{ 10,10 };
	shoulder.collider = Collider(shoulderVerts, 4);	

	//upper arm white
	upper.transform.m_parent = &shoulder.transform;
	upper.transform.m_position = vec2{0, 0 };
	upper.collider = Collider(upperVerts, 4);

	//lower arm blue
	lower.transform.m_parent = &upper.transform;
	lower.transform.m_position = vec2{ 0 , -4 };
	lower.collider = Collider(lowerVerts, 4);	
	
	//hand yellow	
	hand.transform.m_parent = &lower.transform;
	hand.transform.m_position = vec2{ 0,-4 };
	hand.collider = Collider(handVerts, 4);

	isGrabbing = false;
	isReset = false;

	img_shoulder = sfw::loadTextureMap("../dep/shoulder.png");
	img_upper = sfw::loadTextureMap("../dep/upper.png");
	img_lower = sfw::loadTextureMap("../dep/lower.png");
	img_hand = sfw::loadTextureMap("../dep/hand.png");
	img_body = sfw::loadTextureMap("../dep/champ.png");

	
}

void PlayerArm::update(GameState &gs, float deltaTime)
{
	vec2 gravity = { 0, -120.f };

	gs.tractor.transform.m_parent = &hand.transform;	

	shoulder.update(gs, deltaTime);
	upper.update(gs, deltaTime);
	lower.update(gs, deltaTime);
	hand.update(gs, deltaTime);

	if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT)) {
		// remove arm-ball collision		
		isGrabbing = true;		

		//ball reset		
		
		
		if (isReset == false) {
			gs.asteroid.transform.m_position = gs.asteroid.transform.getGlobalPosition();
			gs.asteroid.transform.m_scale = vec2{ 10,10 };
			gs.asteroid.transform.m_parent = nullptr;

			//apply force of arm
			//vec2 dir = normal(hand.transform.getGlobalPosition() -
			//	gs.asteroid.transform.getGlobalPosition());
			vec2 dir = normal(hand.transform.getGlobalPosition());

			gs.asteroid.rigidbody.addImpulse(dir * lower.transform.m_facing * 100);
			gs.asteroid.rigidbody.addImpulse(dir * upper.transform.m_facing * 15);
			gs.asteroid.rigidbody.addTorque(hand.transform.m_facing * 15);

			isReset = true;
		}		

		//arm animations
		upper.rigidbody.addTorque(-16);
		lower.rigidbody.addTorque(-24);
		//hand.rigidbody.addTorque(-2);
	}

	if (isGrabbing) gs.asteroid.rigidbody.addForce(gravity);

	if (!isGrabbing) {

		playerAsteroidColl(hand, gs.asteroid);

		//swing limits
		if (upper.transform.m_facing <= -0.4f) upper.transform.m_facing = -0.35f;
		if (upper.transform.m_facing >= 3.1f) upper.transform.m_facing = 3.05f;

		if (lower.transform.m_facing <= 0) lower.transform.m_facing = 0.05f;
		if (lower.transform.m_facing >= 2.7f) lower.transform.m_facing = 2.68f;

		if (hand.transform.m_facing <= -0.4f) hand.transform.m_facing = -0.38f;
		if (hand.transform.m_facing >= 0.5f) hand.transform.m_facing = 0.48f;

		//swing torque / controls
		if (sfw::getKey('Q')) upper.rigidbody.addTorque(4);
		if (sfw::getKey('W')) upper.rigidbody.addTorque(-4);

		if (sfw::getKey('A')) lower.rigidbody.addTorque(4);
		if (sfw::getKey('S')) lower.rigidbody.addTorque(-4);

		if (sfw::getKey('Z')) hand.rigidbody.addTorque(4);
		if (sfw::getKey('X')) hand.rigidbody.addTorque(-4);


		//tractor control
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT)) {
			gs.tractor.isAlive = true; // reset the beam
			gs.tractor.oneFrame = false;

			// have it look where we are looking

			//gs.tractor.transform.m_position = hand.transform.m_position;
			gs.tractor.transform.m_facing = hand.transform.m_facing;
		}
		else gs.tractor.isAlive = false;
	}

}

void PlayerArm::debugDraw(const mat3 & camera)
{
	//shoulder.rigidbody.debugDraw(camera, shoulder.transform);
	
	//shoulder.transform.debugDraw(camera);

	//shoulder.collider.DebugDraw(camera, shoulder.transform, RED);
	//upper.collider.DebugDraw(camera, upper.transform, WHITE);
	//lower.collider.DebugDraw(camera, lower.transform, BLUE);
	//hand.collider.DebugDraw(camera, hand.transform, YELLOW);

	//printf("hand:%f, upper:%f, lower: %f\n",hand.transform.m_facing, upper.transform.m_facing, lower.transform.m_facing);
	//if (isGrabbing == true) printf("isgrabbing true\n");
	
}

void PlayerArm::draw(const mat3 & camera)
{
	mat3 S = camera * shoulder.transform.getGlobalTransform();
	mat3 U = camera * upper.transform.getGlobalTransform();
	mat3 L = camera * lower.transform.getGlobalTransform();
	mat3 H = camera * hand.transform.getGlobalTransform();

	sfw::drawTextureMatrix3(img_body, 0, WHITE, (S * translate(vec2{ 0,-2 }) * scale(vec2{ 4.5f ,16.0f })).m);
	
	sfw::drawTextureMatrix3(img_hand, 0, WHITE, (H * translate(vec2{ 0,0 }) * scale(vec2{ 2,2 })).m);

	sfw::drawTextureMatrix3(img_lower, 0, WHITE, (L * translate(vec2{ 0,-2 }) * scale(vec2{ 1.5f,4 })).m);
	
	sfw::drawTextureMatrix3(img_upper, 0, WHITE, (U * translate(vec2{ 0,-3 })* scale(vec2{ 1.75f,4 })).m);

	sfw::drawTextureMatrix3(img_shoulder, 0, WHITE, (U * scale(vec2{ 2.5f ,2.5f })).m);
}

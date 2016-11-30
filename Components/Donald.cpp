#include "Donald.h"

Donald::Donald()
{
	vec2 headVerts[] = { { 1,1 },{ 1,-1 },{ -1,-1 },{ -1,1 } };
	vec2 armVerts[] = { { -.5f,0 },{ .5f,0 },{ .25f,-2 },{ -.25f,-2 } };
	vec2 bodyVerts[] = { { 1,1 },{ 1,-1 },{ -1,-1 },{ -1,1 } };

	vec2 shipVerts[] = { { 4,1 },{ 4,-1 },{ -4,-1 },{ -4,1 } };
	vec2 brickVerts[] = { { 0,0 },{ 0,4 },{ 1,4 },{ 1,0 } };

	
	body.transform.m_facing = 0;
	body.transform.m_position = vec2{ 1200, 560 };
	body.transform.m_scale = vec2{ 10,10 };
	body.collider = Collider(bodyVerts, 4);

	larm.transform.m_parent = &body.transform;
	larm.transform.m_position = vec2{ -1, 1 };
	larm.transform.m_facing = -1;
	larm.collider = Collider(armVerts, 4);

	rarm.transform.m_parent = &body.transform;
	rarm.transform.m_position = vec2{ 1, 1 };
	rarm.transform.m_facing = -1;
	rarm.collider = Collider(armVerts, 4);

	ship.transform.m_parent = &body.transform;
	ship.transform.m_position = vec2{ 0, -1.25f };	
	ship.collider = Collider(shipVerts, 4);

	head.transform.m_parent = &body.transform;
	head.transform.m_position = vec2{ 0, 1.75f };
	head.collider = Collider(headVerts, 4);

	brick.collider = Collider(brickVerts, 4);
	brick.transform.m_parent = &body.transform;	
	
	img_head = sfw::loadTextureMap("../dep/donaldhead.png");
	img_part = sfw::loadTextureMap("../dep/donaldpart.png");
	img_ship = sfw::loadTextureMap("../dep/donaldplane.png");

}

void Donald::update(GameState & gs, float deltaTime)
{
	body.rigidbody.velocity.x = -15;
	if (body.transform.getGlobalPosition().x <= 0) body.transform.m_position.x = 1080;
	
	head.update(gs, deltaTime);
	body.update(gs, deltaTime);
	larm.update(gs, deltaTime);
	rarm.update(gs, deltaTime);
	ship.update(gs, deltaTime);

	// drop bricks


	// accept gravity on collision

}

void Donald::debugDraw(const mat3 & camera){
	//head.collider.DebugDraw(camera, head.transform, RED);
	//body.collider.DebugDraw(camera, body.transform, WHITE);
	//larm.collider.DebugDraw(camera, larm.transform, YELLOW);
	//rarm.collider.DebugDraw(camera, rarm.transform, YELLOW);
	//ship.collider.DebugDraw(camera, ship.transform, BLUE);

}

void Donald::draw(const mat3 & camera){
	mat3 headCam = camera * head.transform.getGlobalTransform();
	mat3 larmCam = camera * larm.transform.getGlobalTransform();
	mat3 rarmCam = camera * rarm.transform.getGlobalTransform();
	mat3 bodyCam = camera * body.transform.getGlobalTransform();
	mat3 shipCam = camera * ship.transform.getGlobalTransform();

		
	sfw::drawTextureMatrix3(img_part, 0, WHITE, (bodyCam * scale(vec2{ 2.0f ,2.0f })).m);

	sfw::drawTextureMatrix3(img_ship, 0, WHITE, (shipCam * translate(vec2{ 0,.75f }) * scale(vec2{ 10.0f ,3.0f })).m);

	sfw::drawTextureMatrix3(img_part, 0, WHITE, (larmCam * scale(vec2{ .75f ,3.0f })).m);
	sfw::drawTextureMatrix3(img_part, 0, WHITE, (rarmCam * translate(vec2{ 0,-.75f }) * scale(vec2{ .75f ,2.0f })).m);


	sfw::drawTextureMatrix3(img_head, 0, WHITE, (headCam * scale(vec2{ 2.5f ,2.5f })).m);
}

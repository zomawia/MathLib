#include "Hoop.h"
#include "Gamestate.h"
#include "sfwdraw.h"
#include "ObjectCollision.h"
#include <cstdio>

Hoop::Hoop(){
	vec2 PoleVerts[] = { { 0,0 },{ 0,22 },{ 1,22 },{ 1,0 } };
	vec2 BasketLVerts[] = { { 0,0 },{ 0,2 },{ .25f , 2 },{ .25f ,0 } };
	vec2 NetVerts[] = { {0,0},{0,2},{1,0},{1,2},{0,2},{0,0}};

	Pole.rigidbody.mass = 1000;
	BasketL.rigidbody.mass = 1000;
	BasketR.rigidbody.mass = 1000;

	Pole.transform.m_facing = 0;
	Pole.transform.m_position = vec2{ 805, 300 };
	Pole.transform.m_scale = vec2{ 10,10 };
	Pole.collider = Collider(PoleVerts, 4);
	

	BasketL.transform.m_parent = &Pole.transform;
	BasketR.transform.m_parent = &Pole.transform;

	BasketL.transform.m_position = vec2{ -4, 15};
	BasketL.collider = Collider(BasketLVerts, 4);

	BasketR.transform.m_position = vec2{ -.5f, 15 };
	BasketR.collider = Collider(BasketLVerts, 4);

	img_pole = sfw::loadTextureMap("../dep/pole.png");
	img_net = sfw::loadTextureMap("../dep/net.png");
}

void Hoop::update(GameState & gs, float deltaTime)
{
	Pole.update(gs, deltaTime);
	BasketL.update(gs, deltaTime);
	BasketR.update(gs, deltaTime);
}

void Hoop::debugDraw(const mat3 & camera)
{
	Pole.collider.DebugDraw(camera, Pole.transform, WHITE);
	BasketL.collider.DebugDraw(camera, BasketL.transform, RED);
	BasketR.collider.DebugDraw(camera, BasketR.transform, RED);
}

void Hoop::draw(const mat3 & camera)
{
	mat3 poleCam = camera * Pole.transform.getGlobalTransform();
	mat3 netCam = camera * BasketL.transform.getGlobalTransform();

	sfw::drawTextureMatrix3(img_pole, 0, WHITE, (poleCam * translate(vec2{ 0.5f,11 }) * scale(vec2{ 1.5f ,22 })).m);
	sfw::drawTextureMatrix3(img_net, 0, WHITE, (netCam * translate(vec2{1.85f,1}) * scale(vec2{ 3.5f ,3.f })).m);
}

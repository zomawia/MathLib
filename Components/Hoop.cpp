#include "Hoop.h"
#include "Gamestate.h"
#include "sfwdraw.h"
#include "ObjectCollision.h"
#include <cstdio>

Hoop::Hoop(){
	vec2 PoleVerts[] = { { 0,0 },{ 0,22 },{ 1,22 },{ 1,0 } };
	vec2 BasketLVerts[] = { { 0,0 },{ 0,2 },{ .5f , 2 },{ .5f ,0 } };
	vec2 NetVerts[] = { {0,0},{0,2},{1,0},{1,2},{0,2},{0,0}};

	Pole.rigidbody.mass = 1000;
	BasketL.rigidbody.mass = 1000;
	BasketR.rigidbody.mass = 1000;

	Pole.transform.m_facing = 0;
	Pole.transform.m_position = vec2{ 800, 300 };
	Pole.transform.m_scale = vec2{ 10,10 };
	Pole.collider = Collider(PoleVerts, 4);
	

	BasketL.transform.m_parent = &Pole.transform;
	BasketR.transform.m_parent = &Pole.transform;

	BasketL.transform.m_position = vec2{ -4, 15};
	BasketL.collider = Collider(BasketLVerts, 4);

	BasketR.transform.m_position = vec2{ -.5f, 15 };
	BasketR.collider = Collider(BasketLVerts, 4);


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
	
}

#include "PlayerShip.h"
#include "Gamestate.h"

PlayerShip::PlayerShip(){
	vec2 hullverts[] = { {0,3},{-2,-3},{2,-3} };

	collider =				Collider(hullverts, 3);
	transform.m_scale =		vec2{ 10,10 };
	
	//rigidbody.mass = 10.f;	
	//transform.m_position =	vec2{ 200,200 };
	
}

void PlayerShip::update(GameState & gs, float deltaTime){
	locomotion.update(transform, rigidbody);
	controller.update(locomotion);
	rigidbody.integrate(transform, deltaTime);
}

void PlayerShip::draw(const mat3 & camera){
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(transform, camera);

}
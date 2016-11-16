#include "PlayerShip.h"
#include "Gamestate.h"
#include "sfwdraw.h"

PlayerShip::PlayerShip(){
	vec2 hullverts[] = { {0,3},{-2,-3},{2,-3} };

	collider =				Collider(hullverts, 3);
	transform.m_scale =		vec2{ 10,10 };
	
	//bullet.transform.m_parent = &transform;

	//rigidbody.mass = 10.f;	
	//transform.m_position =	vec2{ 200,200 };
	
}

void PlayerShip::update(GameState & gs, float deltaTime){
	locomotion.update(transform, rigidbody);
	controller.update(locomotion);
	rigidbody.integrate(transform, deltaTime);
	
	if (sfw::getKey('T')){
		gs.tractor.isAlive = true; // reset the beam
		gs.tractor.oneFrame = false;

		// have it look where we are looking
		gs.tractor.transform.m_position = transform.m_position;
		gs.tractor.transform.m_facing = transform.m_facing;
	}
	else gs.tractor.isAlive = false;

	// Bullet spawning Example!
	if (sfw::getKey('F') && !gs.bullet.isAlive)
	{
		// bring it to life
		gs.bullet.timer = 2.f;

		// set up it's position and stuff
		gs.bullet.transform.m_position = transform.m_position;
		gs.bullet.transform.m_facing = transform.m_facing;

		//reset velocity
		gs.bullet.rigidbody.velocity = vec2{ 0,0 };
		// get it moving
		gs.bullet.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}

}

void PlayerShip::draw(const mat3 & camera){
	//transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
	shiprender.draw(transform, camera);


}
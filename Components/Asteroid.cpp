#include "Asteroid.h"

Asteroid::Asteroid(){
	vec2 hullVrts[] = { {1,1}, {1,-1}, {-1,-1}, {-1,1 } };
	collider = Collider(hullVrts, 4);
	render.size = 1;
	transform.m_scale = vec2{ 10,10 };
	
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 5.f;
}

void Asteroid::update(float deltaTime, GameState &gs){
	rigidbody.integrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 &camera){
	render.draw(transform, camera);
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}

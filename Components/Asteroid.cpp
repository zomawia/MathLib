#include "Asteroid.h"

Asteroid::Asteroid(){
	vec2 hullVrts[] = { {1,1}, {1,-1}, {-1,-1}, {-1,1 } };
	collider = Collider(hullVrts, 4);
	render.size = 1;
	transform.m_scale = vec2{ 10,10 };
	
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 1;
}

void Asteroid::update(float deltaTime, GameState &gs){
	rigidbody.integrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 &camera){
	//render.draw(transform, camera);
	mat3 U = camera * transform.getGlobalTransform();
	sfw::drawTextureMatrix3(ball, 0, WHITE, (U * scale(vec2{ 2.5f ,2.5f })).m);

	//transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);
}

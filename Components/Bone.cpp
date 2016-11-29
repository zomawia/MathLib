#include "Bone.h"

Bone::Bone(){
	rigidbody.mass = 2;

}

void Bone::update(GameState & gs, float deltaTime){
	rigidbody.integrate(transform, deltaTime);

}

void Bone::draw(const mat3 & camera)
{
}

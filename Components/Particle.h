#pragma once

#include "Transform.h"
#include "RigidBody.h"
#include "oobpool.h"
#include "Gamestate.h"
#include "Donald.h"

class Particle
{
public:
	Transform	transform;
	RigidBody       rigidbody;
	unsigned int img_head;

	Particle(){ 
		img_head = sfw::loadTextureMap("../dep/donaldhead.png"); 
		transform.m_position.x = 500;
		transform.m_position.y = 500;
	}

	// remaining life
	float lifetime;

	// Returns true if the particle is past its lifetime (lifetime < 0)
	bool isExpired() const { return lifetime < 0; }

	// Ticks down the lifetime and updates the rigidbody.
	void update(float deltaTime) {
		
		if (!isExpired())
		{
			lifetime -= deltaTime;
			rigidbody.integrate(transform, deltaTime);
		}
	}

	// Draws the particle.
	void draw(const mat3 &camera) {
		if (!isExpired()) {
			mat3 headCam = camera * transform.getGlobalTransform();
			sfw::drawTextureMatrix3(img_head, 0, WHITE, 
				(headCam * scale(vec2{ 2.5f ,2.5f })).m);
			}
		}

	// Resets this particle's lifetime.
	void reset(float initial) {
		lifetime = initial;
	}
};
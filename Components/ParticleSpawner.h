#pragma once

#include "oobpool.h"
#include "Particle.h"

#include <vector>

class ParticleSpawner
{
	// Object pool is used to store particles.
	obpool<Particle> particlePool;

public:
	Transform transform;

	float spawnTimer;
	float spawnInterval;            // time between each particle instantiation
	unsigned int maxParticles = 200;      // maximum number of particles allowed
	bool spawnedOnce = false;
	
	ParticleSpawner() {
		spawnTimer = 0;
	}

	ParticleSpawner(float interval, unsigned int particleCount) {
		spawnInterval = interval;
		maxParticles = particleCount;
		spawnTimer = spawnInterval;
	}

	

	// Updates every live particle.
	// Should call free on each particle that has expired.
	// Should attempt to add more particles after the specified interval.
	void update(float deltaTime, class GameState &gs) {

		spawnTimer -= deltaTime;

		if (spawnTimer <= 0 && particlePool.Count() < maxParticles) {
			Particle part;
			part.rigidbody.addForce({ -5,-2 });
			part.lifetime = 2.5f;
			part.transform.m_parent = &transform;
			part.transform.m_scale = { 50,50 };
			
			particlePool.push(part);
			
			spawnTimer = spawnInterval;
		}

		for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter) {				
			(*iter).update(deltaTime, gs);			
			if ((*iter).isExpired()) {
				iter.free();
			}
			
			
		}
	}

	// Draws every live particle.
	void draw(const mat3 &camera) {		
		for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter) {
			(*iter).draw(camera);
		}
	}
};

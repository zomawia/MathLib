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

	float spawnInterval = 1.0f;            // time between each particle instantiation
	unsigned int maxParticles = 10;      // maximum number of particles allowed

									// Updates every live particle.
									// Should call free on each particle that has expired.
									// Should attempt to add more particles after the specified interval.
	void update(float deltaTime) {
		for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter) {
			(*iter).update(deltaTime);
		}
	}

	// Draws every live particle.
	void draw(const mat3 &camera) {		
		for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter) {
			(*iter).draw(camera);
		}
	}
};

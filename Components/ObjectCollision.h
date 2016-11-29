#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "Bullet.h"
#include "TractorBeam.h"
#include "PlayerArm.h"

void playerAsteroidColl(PlayerShip &player, Asteroid &as);
void playerAsteroidColl(Bone &player, Asteroid &as);

void HoopAsteroidColl(Bone &hoop, Asteroid &as);
void DonaldAsteroidColl(Bone &donald, Asteroid &as2);

void asteroidColl(Asteroid &as1, Asteroid &as2);
void BulletAsteroidCollision(Bullet &b, Asteroid &a);
void TractorAsteroidCollision(TractorBeam & tractor, Asteroid & asteroid);
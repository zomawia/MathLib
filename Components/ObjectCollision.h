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
bool BoneAsteroidScoreHitDetectorCounterWhenCollisionHappens(Bone &hitdet, Asteroid &as);

void asteroidColl(Asteroid &as1, Asteroid &as2);
void BoneBoneCollisionUsedForDonaldTrumpDroppingDownTrumpWalls(Bone &as1, Bone &as2);
void BulletAsteroidCollision(Bullet &b, Asteroid &a);
void TractorAsteroidCollision(TractorBeam & tractor, Asteroid & asteroid);
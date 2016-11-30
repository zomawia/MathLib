#include "ObjectCollision.h"

void playerAsteroidColl(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);
	if (result.penetrationDepth >= 0)
	{
		//player.transform.m_scale *= 1.25f;
	}
}

void playerAsteroidColl(Bone & player, Asteroid & as)
{
	CollisionData result =
		ColliderCollision(player.transform, player.collider,
			as.transform, as.collider);

	if (result.penetrationDepth >= 0)
	{
		as.rigidbody.force = { 0,0 };
		as.rigidbody.velocity = { 0,0 };
		as.transform = player.transform;
		//as.transform.m_facing = player.transform.m_facing;
		as.transform.m_position = player.transform.m_position + vec2{ 0,-1.5f };
	}
}

void HoopAsteroidColl(Bone & hoop, Asteroid & as){
	StaticResolution(as.transform, as.rigidbody, as.collider, hoop.transform, hoop.collider, 1.f);
}

void DonaldAsteroidColl(Bone & donald, Asteroid & as2)
{
	DynamicResolution(donald.transform, donald.rigidbody, donald.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

bool BoneAsteroidScoreHitDetectorCounterWhenCollisionHappens(Bone & hitdet, Asteroid & as){
	CollisionData result =
		ColliderCollision(hitdet.transform, hitdet.collider,
			as.transform, as.collider);
	
	return result.penetrationDepth >= 0;

}

void asteroidColl(Asteroid & as1, Asteroid & as2){
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void BoneBoneCollisionUsedForDonaldTrumpDroppingDownTrumpWalls(Bone & as1, Bone & as2){
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void BulletAsteroidCollision(Bullet &b, Asteroid &a)
{
	// make sure the bullet is active!
	if (!b.isAlive) return;

	// Use dynamic resolution, so the bullet bumps stuff away.
	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);


	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		b.timer = 0;
	}
}

void TractorAsteroidCollision(TractorBeam & tractor, Asteroid & asteroid)
{
	// Make sure the tractor is active!
	if (!tractor.isAlive) return;

	// We don't use resolution-- the tractor is non-physical!
	// Just want to know if the asteroid is in the beam.
	CollisionData result =
		ColliderCollision(tractor.transform, tractor.collider,
			asteroid.transform, asteroid.collider);

	// if it is
	if (result.penetrationDepth >= 0)
	{
		// find the direction between
		vec2 dir = normal(tractor.transform.getGlobalPosition() -
			asteroid.transform.getGlobalPosition());
		// and add a force to pull the objet toward us.
		asteroid.rigidbody.addForce(dir * 500);
		// If we flip the force, we can push stuff away.
	}
}
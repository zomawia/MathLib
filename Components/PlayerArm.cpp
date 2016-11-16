#include "PlayerArm.h"



PlayerArm::PlayerArm()
{
	shoulder.transform.m_facing = 0;
	shoulder.transform.m_po

	upper.transform.m_parent = &shoulder.transform;
	lower.transform.m_parent = &upper.transform;
	hand.transform.m_parent = &lower.transform;
}

void PlayerArm::update(GameState & gs, float deltaTime)
{
}

void PlayerArm::debugDraw(const mat3 & camera)
{
	shoulder.rigidbody.debugDraw(camera, shoulder.transform);
}

void PlayerArm::draw(const mat3 & camera)
{
}

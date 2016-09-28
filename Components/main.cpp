#include "sfwdraw.h"
#include "vec2.h"
#include "transform.h"
#include "flops.h"

void main()
{
	sfw::initContext();
	Transform trans;

	trans.position = vec2{ 400, 300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };
	
	while (sfw::stepContext())
	{
		trans.facing += sfw::getDeltaTime();
		trans.scale.x += sfw::getDeltaTime();
		trans.scale.y += sfw::getDeltaTime();
		trans.debugDraw();
	}

	sfw::termContext();
}
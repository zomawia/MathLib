#include "sfwdraw.h"
#include "vec2.h"
#include "transform.h"
#include "flops.h"

void main()
{
	sfw::initContext();
	Transform trans, trans2;

	trans.color = RED;
	trans2.color = BLUE;

	trans.position = vec2{ 400, 300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };
	
	while (sfw::stepContext())
	{
		trans.facing += sfw::getDeltaTime();
		trans.scale.x += sfw::getDeltaTime();
		trans.scale.y += sfw::getDeltaTime();
		trans.debugDraw();
		trans2.debugDraw();

		sfw::drawCircle(trans.position.x+dot(trans.dirEnd, trans2.dirEnd), trans2.position.y, 3, 6, GREEN);
	}

	sfw::termContext();
}
#include "sfwdraw.h"
#include "vec2.h"
#include "transform.h"
#include "flops.h"
#include <cmath>
#include <cstdio>
#include "RigidBody.h"

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);

	float gravity = 9.8f;
	
	while (sfw::stepContext())
	{	
		
	}

	sfw::termContext();
}
#include "sfwdraw.h"
#include "vec2.h"
#include "transform.h"
#include "flops.h"
#include <cmath>
#include <cstdio>

void main()
{
	sfw::initContext();
	float time = 0;
	
	while (sfw::stepContext())
	{
		for (int i = 0; i < 100; ++i)
		{			
			// example
			/*float x1 = i / 100.f;
			float y1 = linearHalf(x1);

			float x2 = (i+1) / 100.f;			
			float y2 = linearHalf(x2);*/

			//a
			/*float x1 =  i / 100.f;
			float y1 = growFast(x1);
			float x2 = (i + 1) / 100.f;
			float y2 = growFast(x2);*/

			//b
			/*float x1 = i / 100.f;
			float y1 = growSlow(x1);
			float x2 = (i + 1) / 100.f;
			float y2 = growSlow(x2);*/

			//c
			/*float x1 = i / 100.f;
			float y1 = hardAngle(x1);
			float x2 = (i + 1) / 100.f;
			float y2 = hardAngle(x2);*/

			//d
			/*float x1 = i / 100.f;
			float y1 = bounceFlip(x1);
			float x2 = (i + 1) / 100.f;
			float y2 = bounceFlip(x2);*/

			//e
			/*float x1 = i / 100.f;
			float y1 = parabFlip(x1);
			float x2 = (i + 1) / 100.f;
			float y2 = parabFlip(x2);*/

			float x1 = i /100.f;
			float x2 = (i+1) / 100.f;

			/*float y1 = lerp(0, .5f, x1);
			float y2 = lerp(0, .5f, x2);*/
		
			/*float y1 = quadBezier(.25f, 0, 1, x1);
			float y2 = quadBezier(.25f, 0, 1, x2);*/

			/*float y1 = hermiteSpline(1, 1, 0, 1, x1);
			float y2 = hermiteSpline(1, 1, 0, 1, x2);*/

			//float y1 = cardinalSpline(.0f, .5f, 1, time, x1);
			//float y2 = cardinalSpline(.0f, .5f, 1, time, x2);

			printf("%f \n", time);

			/*float y1 = catRomSpline(.25f, .75f, 1, x1);
			float y2 = catRomSpline(.25f, .75f, 1, x2);*/

			x1 *= 800;
			x2 *= 800;
			y1 *= 600;
			y2 *= 600;

			sfw::drawLine(x1, y1, x2, y2, WHITE);
			sfw::drawCircle(x2, y2, 12, 12, GREEN);
		}
	}

	sfw::termContext();
}
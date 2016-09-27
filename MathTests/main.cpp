#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"

int main()
{
	//printf("Hello World! %d", doNothing(6));
	
	// unit tests
	assert(doNothing(0) == 5);

	//a
	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);

	//b
	assert(test_quad_roots(1, 0, 0).roots == 1);
	assert(test_quad_roots(1, -2, 0).roots == 2);
	//assert(test_quad_roots(1, 0, 4).roots == 0);

	//c
	assert(lerp(0, 5, 1) == 5);
	assert(lerp(2, 8, 4) == 26);

	//d
	Point Point1 = { 1, 1 };
	Point Point2 = { 5, 9 };
	
	printf("distance: %f \n\n", distance(Point1, Point2));

	//assert(distance(Point1, Point2) > 8.944271);

	//e
	Point3d A = { 0, 0, 0 };
	Point3d B = { 1, 12, 13 };
	printf("inner: %f \n\n", inner(A, B));
	//assert(inner(A, B) == 64);

	//f
	plane myPlane = { 0,0,1,0 };
	printf("plane distance: %f \n\n", plane_distance(myPlane, A));
	assert(plane_distance(myPlane, A) == 0);

	//g

	assert(	(vec2{ 1,0 } + vec2{ 0,1 } == vec2{ 1,1 })	);

	assert((vec2{ 1,1 } - vec2{ 1,1 } == vec2{ 0,0 }));

	assert((vec2{ 1,2 } * 5 == vec2{ 5,10 }));

	assert((5 * vec2{ 1,2 } == vec2{ 5,10 }));

	assert((vec2{ 20,10 } / 2 == vec2{ 10,5 }));

	assert((-vec2{ 1,2 } == vec2{ -1,-2 }));

	assert(	((vec2{ 5,4 } += vec2{5,4}) == vec2{10, 8})	);

	assert(((vec2{ 1,3 } -= vec2{ 2,2 }) == vec2{ -1, 1 }));

	assert(((vec2{ 2,4 } *= 5) == vec2{ 10, 20 }));

	assert(((vec2{ 10,6 } /= 2) == vec2{ 5,3 }));

	assert((vec2{ 1,1 } == vec2{ 1,1 }));

	assert((vec2{ 1,1 } != vec2{ 0,1 }));

	assert((magnitude(vec2{ 3,4 }) == 5));

	



	getchar();

	return 0;
}
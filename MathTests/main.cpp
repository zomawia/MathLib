#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"

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
	
	//printf("distance: %f \n\n", distance(Point1, Point2));

	//assert(distance(Point1, Point2) > 8.944271);

	//e
	Point3d A = { 0, 0, 0 };
	Point3d B = { 1, 12, 13 };
	//printf("inner: %f \n\n", inner(A, B));
	//assert(inner(A, B) == 64);

	//f
	plane myPlane = { 0,0,1,0 };
	//printf("plane distance: %f \n\n", plane_distance(myPlane, A));
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


	// normalization and magnitude
	assert((magnitude(vec2{ 3,4 }) == 5));
	assert((magnitude(vec2{ 20,21 }) == 29));

	assert(fequals(-1, -.9999999f));
	assert(fequals(1, .99999999f));

	assert(rad2deg(angleBetween(vec2{1,0}, vec2{0,1})) == 90);	
	assert(rad2deg(angleBetween(vec2{ 1,0 }, vec2{ 1,1 })) == 45);

	assert(dot(vec2{1,0}, vec2{1,1}) == 1);

	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 })
		== vec3{ 0,0,1 }));
	assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((rad2deg(angle(vec2{ 0,1 })) == 90));
	assert((rad2deg(angle(vec2{ -1, 0 })) == 180));
	
	// matrix math
	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat3 mI3 = mat3Identity();
	mat2 t0 = mat2{ 4,3,2,1 };
	mat3 nums = mat3{ 8,7,6,5,4,3,2,1,0 };
	mat3 mat0 = { 0,0,0,0,0,0,0,0,0 };
	vec2 v0 = { 1,0 };
	vec3 v30 = { 1,0,0 };

	assert(m0 == m0);
	assert(mat0 == mat0);

	assert(mI * 2 == 2 * mI);
	assert(mI3 * 2 == 2 * mI3);

	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert((mI3 * 2 == mat3{ 2,0,0,0,2,0,0,0,2 }));

	assert(mI + m0 == mI);
	assert(mI3 + mat0 == mI3);

	assert(mI - mI == m0);
	assert(mI3 - mI3 == mat0);

	assert(mI * -1 == -mI);
	assert(mI3 * -1 == -mI3);

	assert(mI * mI == mI);
	assert(mI3 * mI3 == mI3);

	assert((mat2{ 1,2,3,4 }) * mI == (mat2{ 1,2,3,4 }));
	assert((mat3{ 1,2,3,4,5,6,7,8,9 } * mI3 == (mat3{ 1,2,3,4,5,6,7,8,9 })));

	assert(transpose(mI) == mI);
	assert(transpose(mI3) == mI3);

	assert(inverse(mI) == mI);
	assert(inverse(mI3) == mI3);

	assert(t0 * inverse(t0) == mI);
	assert(mI3 * inverse(mI3) == mI3);

	assert(mI * v0 == v0);
	assert(mI3 * v30 == v30);

	assert((t0 * v0 == vec2{ 4,2 }));

	// transform matrix
	vec3 jorb = { 2,5,1 };
	assert((scale(vec2{ 5,1 }) * jorb == vec3{10,5,1}));

	vec3 test = rotation(deg2rad(90)) * jorb;
	
	printf("%f %f %f\n", jorb[0], jorb[1], jorb[2]);
	printf("%f %f %f\n", test[0], test[1], test[2]);

	assert(((rotation(deg2rad(90)) * jorb == vec3{ -5,2,1 })));

	assert((translate(vec2{ 0,3 }) * jorb == vec3{ 2,8,1 }));

	mat3 S = scale(vec2{ 2,1 });
	mat3 T = translate(vec2{ 4,3 });
	mat3 R = rotation(deg2rad(90));
	
	mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };

	printf("All asserts working!\n");
	getchar();

	return 0;
}
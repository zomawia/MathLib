#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
#include <cmath>
#include "shapes.h"
#include "collision.h"

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
	assert(((rotation(deg2rad(90)) * jorb == vec3{ -5,2,1 })));
	assert((translate(vec2{ 0,3 }) * jorb == vec3{ 2,8,1 }));

	// matrix exercise
	vec3 SVec3 = { 0,0,1 };
	mat3 S1 = rotation(deg2rad(-90)) * translate(vec2{ 10,0 });
	mat3 S2 = rotation(deg2rad(45)) * translate(vec2{4,0});
	mat3 S3 = rotation(deg2rad(45)) * translate(vec2{ -6,0 });
	mat3 S4 = translate(vec2{ 6,4 });

	vec3 result = S1 * S2 * S3 * S4 * SVec3;

	assert((result == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2) , 1 }));

	// Circle

	Circle c = { 0,0,5 };
	Circle tester = rotation(45) * c;

	assert((translate(vec2{ 4,0 }) * c == Circle{ 4,0,5 }));

	assert((scale(vec2{ 2, 1 }) * c == Circle{ 0,0,10 }));	
	assert((scale(vec2{ 2, 2 }) * c == Circle{ 0,0,10 }));
	assert((scale(vec2{ 1, 2 }) * c == Circle{ 0,0,10 }));
	assert((scale(vec2{ -1, 1 }) * c == Circle{ 0,0,5 }));

	assert((rotation(45) * c == Circle{ 0,0,5 }));

	// AABB

	AABB testA = { 1,2,3,4 };
	assert((testA.min() == vec2{ -2, -2 }));
	assert((testA.max() == vec2{ 4, 6 }));

	// Collision1D

	assert(collisionDetection1D(0, 2, 1, 3).result() == true);
	assert(collisionDetection1D(0, 2, 1, 3).penetrationDepth == 1);
	assert(collisionDetection1D(1, 3, 0, 2).penetrationDepth == 1);

	assert(collisionDetection1D(0, 2, 1, 3).collisionNormal == 1);
	assert(collisionDetection1D(1, 3, 0, 2).collisionNormal == -1);

	// swepts
	assert(sweptDetection1D(0,1,5,  3,4,0).entryTime == .4f);
	assert(sweptDetection1D(0, 1, -5, 3, 4, 10).result() == false);

	// boxCOllision
	AABB boxA = { 0,0,2,4 }; 
	AABB boxB = { 2,2,2,4 };

	assert(boxCollision(boxA, boxB).penetrationDepth == 2);
	assert((boxCollision(boxA, boxB).collisionNormal == vec2{ 1,0 }));
	assert((boxCollision(boxB, boxA).collisionNormal == vec2{ -1,0 }));

	// boxCollisionSwept
	AABB As = { 0,0,1,1};
	AABB Bs = { 0,10,1,1 };
	assert(fequals(boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0,-1 }).entryTime, 4));
	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 }).entryTime, -6));
	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 }).exitTime, -4));

	// planeBoxCollision
	AABB Bp = { 0,0,4,4 };

	Plane P1 = { 0,0,0,1 };		// clipping case
	Plane P2 = { 0,-10, 0, 1 }; // non overlapping
	Plane P3 = { 0, 10, 0, 1 }; // fully overlapping

	Plane P4 = { vec2{6,6}, normal(vec2{-1,1}) };	//overlapping
	Plane P5 = { vec2{6,6}, normal(vec2{-1,-1}) };	//non-overlapping

	assert(planeBoxCollision(P1, Bp).result());
	assert(!planeBoxCollision(P2, Bp).result());
	assert(planeBoxCollision(P3, Bp).result());
	assert(planeBoxCollision(P4, Bp).result());
	assert(!planeBoxCollision(P5, Bp).result());

	Plane P6 = { 10,0,-1,0 }; //fully overlapping

	assert(fequals(planeBoxCollisionSwept(P6, vec2{ 1,0 }, Bp, vec2{ 1,0 }).entryTime, 6.f));

	// convex hulls
	vec2 verts[] = { { 0,1 },{ 1,1 },{ 1,0 },{ 0,0 } };

	vec2 verts2[] = { { -1,-1 },{ -1,1 },{ 0,0 } };

	Hull myHull(verts, 4);
	Hull otherHull(verts2, 3);

	assert((myHull.normals[0] == vec2{ 0, 1 }));
	assert((myHull.normals[1] == vec2{ 1, 0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));


	Hull tHull = translate(vec2{ 1, 0 }) * myHull;

	assert((tHull.vertices[0] == vec2{ 1, 1 }));
	assert((tHull.vertices[1] == vec2{ 2, 1 }));
	assert((tHull.vertices[2] == vec2{ 2, 0 }));
	assert((tHull.vertices[3] == vec2{ 1, 0 }));

	assert(fequals(HullCollision(myHull, otherHull).penetrationDepth, 0));
	assert(fequals(HullCollision(otherHull, tHull).penetrationDepth, -1));


	printf("All asserts working!\n");	
	getchar();

	return 0;
}
#include "Test.h"
#include <cmath>

// This is a develop branch!

int doNothing(int x)
{
	return x*x + 2 * x + 5;
}

float test_quad(float x)
{
	return x*x + 2 * x - 7;
}

quad_results test_quad_roots(float a, float b, float c)
{
	//the area under a sqrt is often called a determinant
	// if the det is less than 0, there cant be any roots
	// if the det is 0, there is 1 root
	
	quad_results temp;

	float det = sqrt(b*b - 4 * a*c);

	if (det < 0) temp.roots = 0;

	else if (det == 0)
	{
		temp.roots = 1;
	}
	else if (det > 0)
	{
		temp.roots = 2;		
	}

	temp.right_root = (-b + sqrt((b*b) - 4 * a*c)) / (2 * a);
	temp.left_root = (-b - sqrt((b*b) - 4 * a*c)) / (2 * a);

	return temp;

}

float lerp(float start, float end, float t)
{
	return start + t * (end - start);
}

float distance(Point P1, Point P2)
{
	return sqrt( (P2.x - P1.x)*(P2.x - P1.x) + (P2.y - P1.y)*(P2.y - P1.y) );
}

float inner(Point3d P, Point3d Q)
{
	return (P.x*Q.x) + (P.y*Q.y) + (P.z*Q.z);
}

float plane_distance(plane P, Point3d X)
{
	return (P.a*X.x + P.b * X.y + P.c*X.z + P.d) / sqrt(P.a * P.a + P.b * P.b + P.c *P.c);
}

float cubic_bezier_curve(float t, const Point3d &p1, const Point3d &p2,
	const Point3d &p3, const Point3d &p4)
{
	float ot = 1 - t;
	Point3d r;
	r.x = ot*ot*ot*p1.x + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p4.x;
	r.y = ot*ot*ot*p1.y + 3 * ot*ot*t*p2.y + 3 * ot*t*t*p3.y + t*t*t*p4.y;
	r.z = ot*ot*ot*p1.z + 3 * ot*ot*t*p2.z + 3 * ot*t*t*p3.z + t*t*t*p4.z;
	// A^3 + 3A^2B + 3AB^2 + B^3
	return 0;
}
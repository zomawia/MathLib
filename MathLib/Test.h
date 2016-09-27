#pragma once

int doNothing(int x);

//a
float test_quad(float x);

//b
struct quad_results
{
	float left_root, right_root;
	int roots; //0, 1, 2
};

quad_results test_quad_roots(float a, float b, float c);

//c
float lerp(float start, float end, float t);

struct Point { float x, y; };

//d
float distance(Point P1, Point P2);

//e
struct Point3d { float x, y, z; };
float inner(Point3d P1, Point3d P2);

//f
struct plane { float a, b, c, d; };
float plane_distance(plane P, Point3d X);

//g
float cubic_bezier_curve(float t, float p0, float p1, float p2, float p3);
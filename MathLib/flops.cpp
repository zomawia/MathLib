#include "flops.h"
#include <cmath>

const double PI = 3.14159265358979323846;


bool fequals(float lhs, float rhs)
{
	// return true if the delta between the 
	// two operands is less than some threshold
	
	return fabsf(lhs - rhs) <= 0.00001f;
}

float deg2rad(float deg)
{
	return (deg / 180)*PI;
}

float rad2deg(float rad)
{
	return (rad/PI)*180;
}

float linearHalf(float x)
{
	return 0.5f * x;
}

float growFast(float x)
{
	return x*x;
}

float growSlow(float x)
{
	return 1 - growFast(1-x);
}

float hardAngle(float x)
{
	return x < 0.5 ? 2 * x : -2 * (x - 1);
}

float bounce(float x)
{	
	return abs(cos(x * 10) * (1-x));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabFlip(float x)
{
	return 1 - (2 * x -1)*(2 * x - 1);
}

float lerp(float start, float end, float alpha)
{
	return start + alpha * (end - start);
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return lerp(
		lerp(start, mid, alpha),
		lerp(mid, end, alpha), alpha);
}

float cubicBezier(float start, float mid1, float mid2, float end, float alpha)
{
	return lerp(
		lerp(start, mid2, alpha),
		lerp(mid1, end, alpha), alpha);
}

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float asq = alpha*alpha;
	float acub = asq * alpha;

	float h00 = 2 * acub - 3 * asq + 1;
	float h01 = -2 * acub + 3 * asq;
	float h10 = acub - 2 * asq + alpha;
	float h11 = acub - asq;

	return h00 * start + h10 * s_tan + h01 * end + h11 * e_tan;
}

float cardinalSpline(float start, float mid, float end, float tight, float alpha)
{
	float tan0 = (mid - start) * tight;
	float tan1 = (end - mid) * tight;

	return hermiteSpline(start, tan0, end, tan1, alpha);
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}
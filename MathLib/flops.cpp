#include "flops.h"
#include <cmath>

const double PI = 3.14159265358979323846;


bool fequals(float lhs, float rhs)
{
	// return true if the delta between the 
	// two operands is less than some threshold
	
	return fabsf(lhs - rhs) <= 0.0000002f;
}

float deg2rad(float deg)
{
	return (deg / 180)*PI;
}

float rad2deg(float rad)
{
	return (rad/PI)*180;
}

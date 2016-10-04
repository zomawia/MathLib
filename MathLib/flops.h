#pragma once

// for close number comparison
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

// BASIC CURVING STUFF
float linearHalf(float x);
float growFast(float x);
float growSlow(float x);
float bounce(float x);
float hardAngle(float x);
float bounceFlip(float x);
float parabFlip(float x);

// CURVING FUNCTIONS

//Linear interpolation lerp
float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

float cubicBezier(float start, float mid1, float mid2, float end, float alpha);

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha);

float cardinalSpline(float start, float mid, float end, float tight, float alpha);

float catRomSpline(float start, float mid, float end, float alpha);



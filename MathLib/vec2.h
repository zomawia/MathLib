#pragma once


union vec2
{
	float v[2];
	struct { float x, y; };

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);
vec2 operator/(const vec2 &lhs, float rhs);
// need division

vec2 operator-(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);

vec2 &operator/=(vec2 &lhs, const float &rhs);
vec2 &operator*=(vec2 &lhs, const float &rhs);
vec2 &operator/=(const float &rhs, vec2 &lhs);
vec2 &operator*=(const float &rhs, vec2 &lhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

// divide by magnitude
vec2 normal(const vec2 &v);

//
float dot(const vec2 &rhs, const vec2 &lhs);

// returns in radians
float angleBetween(const vec2 &rhs, const vec2 &lhs);

// right handed
vec2 perp(const vec2 &v);

//arctangent
// find the angle of the vector. returns in radians
float angle(const vec2 &v);

// vec2{cos(a), sin(a)};
vec2 fromAngle(float a);

// CURVING FUNCTIONS
vec2 lerp(const vec2 &start, const vec2 &end, float alpha);

vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);

vec2 hermiteSpline(const vec2 &start, const vec2 &s_tan, const vec2 &end, const vec2 &e_tan, float alpha);

vec2 cardinalSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float tight, float alpha);

vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);

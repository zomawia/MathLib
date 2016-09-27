#pragma once

struct vec2 { float x, y; };

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
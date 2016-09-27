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

//arithmetic operations:
	// comp add
	// comp sub
	// scaler mult
	// scaler div

// relational operators
	// comp equiv
	// comp non equiv

// vector operations
	// mag (pythagorean therem

// assignment expressions
	// assignment addition
	// assignment sub
	// assignment scalar mult
	// assignment scalar div

//unary negation
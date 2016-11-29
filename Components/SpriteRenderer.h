#pragma once
#include "mat3.h"
#include "transform.h"


class SpriteRenderer {

	void draw(const mat3 &camera, const Transform &T);

};
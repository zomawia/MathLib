#pragma once

#include "mat3.h"
#include "transform.h"


unsigned int font;

class TextRenderer {

	TextRenderer();
	
	void drawTextBinding(const mat3 &camera, const Transform &T);
	//void drawTextStatic(char )

};
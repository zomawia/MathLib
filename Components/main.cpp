#include "sfwdraw.h"
#include "Gamestate.h"
#include <cstdio>

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);

	GameState game;

	game.play();

	while (sfw::stepContext()) {
		float dt = sfw::getDeltaTime();
		game.update(dt);
		game.draw();


	}

	sfw::termContext();
}
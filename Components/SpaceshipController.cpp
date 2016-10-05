#include "SpaceshipController.h"
#include "sfwdraw.h"

void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput += sfw::getKey('A');
	hInput -= sfw::getKey('D');

	float vInput = 0.0f;
	vInput -= sfw::getKey('S');
	vInput += sfw::getKey('W');

	loco.doThrust(vInput);
	loco.doTurn(hInput);
}

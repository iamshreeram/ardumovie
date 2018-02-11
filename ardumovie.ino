#include <Arduboy2.h>
#include <Sprites.h>
#include "images.h"

Arduboy2Base arduboy;
Sprites sprites;

void setup()
{
	arduboy.boot(); // raw hardware
	arduboy.blank(); // blank the display

	arduboy.flashlight(); // light the RGB LED and screen if UP button is being held.

	// check for and handle buttons held during start up for system control
	arduboy.systemButtons();

	arduboy.audio.begin();

	// wait for all buttons to be released
	do
	{
		arduboy.delayShort(50);
	}
	while (arduboy.buttonsState());

	arduboy.initRandomSeed();
}

void loop()
{
	// draw everything to the screen
	arduboy.display(CLEAR_BUFFER);
}

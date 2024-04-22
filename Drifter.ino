/*
 Name:		Drifter.ino
 Created:	19/04/2024 09:43:12
 Author:	gab
*/

#include <DigitalIO.h>
#include <avr/pgmspace.h>
#include "src/Manette/Manette.h"

PsxControllerBitBang<PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK> psx;

void setup() {
	fastPinMode(PIN_BUTTONPRESS, OUTPUT);
	fastPinMode(PIN_HAVECONTROLLER, OUTPUT);

	delay(300);

	Serial.begin(115200);
	Serial.println(F("Ready!"));
}

///////////////////////////////////////////////////////////////////

void loop() {
	static byte slx, sly, srx, sry;   // declaration des variable pour les manches Left et right

	fastDigitalWrite(PIN_HAVECONTROLLER, haveController);

	if (!haveController)
	{
		if (psx.begin())
		{
			Serial.println(F("Controller found!"));
			delay(300);
			if (!psx.enterConfigMode())
			{
				Serial.println(F("Cannot enter config mode"));
			}
			else
			{
				PsxControllerType ctype = psx.getControllerType();
				PGM_BYTES_P cname = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr(&(controllerTypeStrings[ctype < PSCTRL_MAX ? static_cast<byte> (ctype) : PSCTRL_MAX])));
				Serial.print(F("Controller Type is: "));
				Serial.println(PSTR_TO_F(cname));

				if (!psx.enableAnalogSticks())
				{
					Serial.println(F("Cannot enable analog sticks"));
				}

				//~ if (!psx.setAnalogMode (false)) {
					//~ Serial.println (F("Cannot disable analog mode"));
				//~ }
				//~ delay (10);

				if (!psx.enableAnalogButtons())
				{
					Serial.println(F("Cannot enable analog buttons"));
				}

				if (!psx.exitConfigMode())
				{
					Serial.println(F("Cannot exit config mode"));
				}
			}
			haveController = true;
		}
	}
	else
	{
		if (!psx.read())
		{
			Serial.println(F("Controller lost :("));
			haveController = false;
		}
		else
		{
			fastDigitalWrite(PIN_BUTTONPRESS, !!psx.getButtonWord());
			dumpButtons(psx.getButtonWord());

			byte lx, ly;
			psx.getLeftAnalog(lx, ly);
			if (lx != slx || ly != sly)
			{
				dumpAnalog("Left", lx, ly);
				slx = lx;
				sly = ly;
			}

			byte rx, ry;
			psx.getRightAnalog(rx, ry);
			if (rx != srx || ry != sry) {     // si different de la valeur pr�cedante
				dumpAnalog("Right", rx, ry);   // on affiche
				srx = rx;
				sry = ry;
			}
		}
	}
	delay(1000 / 60);
}


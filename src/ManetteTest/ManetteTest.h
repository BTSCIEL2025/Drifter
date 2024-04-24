#ifndef MANETTETEST_H
#define MANETTETEST_H

#include <DigitalIO.h>
#include <PsxControllerBitBang.h>

#include <avr/pgmspace.h>
typedef const __FlashStringHelper* FlashStr;
typedef const byte* PGM_BYTES_P;
#define PSTR_TO_F(s) reinterpret_cast<const __FlashStringHelper *> (s)

boolean haveController = false;

// These can be changed freely when using the bitbanged protocol
const byte PIN_PS2_ATT = 8; // 10;
const byte PIN_PS2_CMD = 7;  //11;
const byte PIN_PS2_DAT = 6;  //12;
const byte PIN_PS2_CLK = 9;  // 13;

const byte PIN_BUTTONPRESS = A0;
const byte PIN_HAVECONTROLLER = A1;

const char buttonSelectName[] PROGMEM = "Select";
const char buttonL3Name[]     PROGMEM = "L3";
const char buttonR3Name[]     PROGMEM = "R3";
const char buttonStartName[]  PROGMEM = "Start";
const char buttonUpName[]     PROGMEM = "Up";
const char buttonRightName[]  PROGMEM = "Right";
const char buttonDownName[]   PROGMEM = "Down";
const char buttonLeftName[]   PROGMEM = "Left";
const char buttonL2Name[]     PROGMEM = "L2";
const char buttonR2Name[]     PROGMEM = "R2";
const char buttonL1Name[]     PROGMEM = "L1";
const char buttonR1Name[]       PROGMEM = "R1";
const char buttonTriangleName[] PROGMEM = "Triangle";
const char buttonCircleName[]   PROGMEM = "Circle";
const char buttonCrossName[]    PROGMEM = "Cross";
const char buttonSquareName[]   PROGMEM = "Square";

const char* const psxButtonNames[PSX_BUTTONS_NO] PROGMEM = {
	buttonSelectName,
	buttonL3Name,
	buttonR3Name,
	buttonStartName,
	buttonUpName,
	buttonRightName,
	buttonDownName,
	buttonLeftName,
	buttonL2Name,
	buttonR2Name,
	buttonL1Name,
	buttonR1Name,
	buttonTriangleName,
	buttonCircleName,
	buttonCrossName,
	buttonSquareName
};

const char ctrlTypeUnknown[] PROGMEM = "Unknown";
const char ctrlTypeDualShock[] PROGMEM = "Dual Shock";
const char ctrlTypeDsWireless[] PROGMEM = "Dual Shock Wireless";
const char ctrlTypeGuitHero[] PROGMEM = "Guitar Hero";
const char ctrlTypeOutOfBounds[] PROGMEM = "(Out of bounds)";

const char* const controllerTypeStrings[PSCTRL_MAX + 1] PROGMEM = {
	ctrlTypeUnknown,
	ctrlTypeDualShock,
	ctrlTypeDsWireless,
	ctrlTypeGuitHero,
	ctrlTypeOutOfBounds
};

#endif
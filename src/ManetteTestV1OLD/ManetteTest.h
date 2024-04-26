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
const byte PIN_PS2_ATT = 8; // Attention;
const byte PIN_PS2_CMD = 7;  // Commande;
const byte PIN_PS2_DAT = 6;  // Donnée;
const byte PIN_PS2_CLK = 9;  // Clock;

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

class Manette {
public:
    static byte jlx, jly, jrx, slx, sly, srx, sry;
    PsxControllerBitBang <PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK> controller;

    void setupController() {
        if (controller.begin()) {
            haveController = true;
        } else {
            haveController = false;
        }
    }

    byte getX() {
            // Jlx prend la valeur de lx
            jlx = controller.getLeftAnalog(PsxControllerBitBang <PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK>::LX);
            return jlx;
    }

    byte getY() {
            // Jly prend la valeur de ly
            jly = controller.getLeftAnalog(PsxControllerBitBang <PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK>::LY);
            return jly;
    }
    byte getZ() {
            // Jrx prend la valeur de rx
            jrx = controller.getRightAnalog(PsxControllerBitBang <PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK>::RX);
            return jrx;
    }
    byte getBouton(){
        if (haveController) {
            return PsxButtons(controller.getButtonWord());
        }
        return 0;
    }
};

#endif
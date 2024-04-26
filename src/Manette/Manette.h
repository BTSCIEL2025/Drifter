#ifndef MANETTETEST_H
#define MANETTETEST_H

#include <DigitalIO.h>
#include <PsxControllerBitBang.h>

#include <avr/pgmspace.h>
typedef const __FlashStringHelper* FlashStr;
typedef const byte* PGM_BYTES_P;
#define PSTR_TO_F(s) reinterpret_cast<const __FlashStringHelper *> (s)



// These can be changed freely when using the bitbanged protocol
const byte PIN_PS2_ATT = 8; // Attention
const byte PIN_PS2_CMD = 7;  // Command
const byte PIN_PS2_DAT = 6;  // Data
const byte PIN_PS2_CLK = 9;  // Clock

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
    byte jlx, jly, jrx, jry, slx, sly, srx, sry;
  	byte rx, ry, lx, ly ;  // deplacement LS

//======================================================================================
class Manette {
public:
    boolean haveController = false;


    PsxControllerBitBang <PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK> controller;
    //---------------------------------------------
    void setupController() {
      if (controller.begin()) {
        Serial.println("Controller started");
        controller.enterConfigMode();
        Serial.println("Entered config mode");
        controller.enableAnalogSticks();
        Serial.println("Analog sticks enabled");
        controller.exitConfigMode();
        Serial.println("Exited config mode");
        haveController = true;
      } else 
      {
        Serial.println("Controller failed to start");
        haveController = true;
      }
    }
    //---------------------------------------------
    byte getButton() {
        if (haveController) {
            return PsxButtons(controller.getButtonWord());
        }
        return 0;
    }
    //---------------------------------------------
    byte psxButtonToIndex(PsxButtons psxButtons) {
      byte i;

      for (i = 0; i < PSX_BUTTONS_NO; ++i) {
        if (psxButtons & 0x01) {
          break;
        }

        psxButtons >>= 1U;
      }

      return i;
    }

    //---------------------------------------------
    FlashStr getButtonName(PsxButtons psxButton) {
      FlashStr ret = F("");

      byte b = psxButtonToIndex(psxButton);
      if (b < PSX_BUTTONS_NO) {
        PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr(&(psxButtonNames[b])));
        ret = PSTR_TO_F(bName);
      }

      return ret;
    }
    
    //---------------------------------------------
    void dumpButtons(PsxButtons psxButtons) {
    static PsxButtons lastB = 0;

    if (psxButtons != lastB) {
      lastB = psxButtons;     // Save it before we alter it

      Serial.print(F("Pressed: "));

      for (byte i = 0; i < PSX_BUTTONS_NO; ++i) {
        byte b = psxButtonToIndex(psxButtons);
        if (b < PSX_BUTTONS_NO) {
          PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr(&(psxButtonNames[b])));
          Serial.print(PSTR_TO_F(bName));
        }

        psxButtons &= ~(1 << b);

        if (psxButtons != 0) {
          Serial.print(F(", "));
          }
        }

        Serial.println();
      }
    }
  //=======================================================================================
    void dumpAnalog (const char *str, const byte x, const byte y) {
      Serial.print (str);
      Serial.print (F(" x = "));
      Serial.print (x);
      Serial.print (F(", y = "));
      Serial.println (y);
    }
//=======================================================================================

    void updateAnalogSticks(){
  //    byte lx, ly;
			controller.getLeftAnalog (lx, ly);
      // Serial.print("début condition si gauche");


      Serial.print("  updateAnalogSticks:  lx: ");    Serial.print(lx);
      Serial.print("   slx: ");   Serial.print(slx);
      Serial.print("   ly: ");    Serial.print(ly);
      Serial.print("   sly: ");   Serial.print(slx);   	






			if (lx != slx || ly != sly){  // si different de la valeur précedante aaa 
				//dumpAnalog ("Left", lx, ly);  
				slx = lx;   // on save la derniere valeur 
				sly = ly;
        Serial.print("MAJ valeurs gauche     ");
			}

//			byte rx, ry;
			controller.getRightAnalog (rx, ry);
      // Serial.print("début condition si droite");
			if (rx != srx || ry != sry) {     // si different de la valeur précedante aaa
				//dumpAnalog ("Right", rx, ry);   // on affiche
				srx = rx;
				sry = ry;
        Serial.print("MAJ valeurs droite     ");
			}
    }
			
    byte getX(void){  return slx;  }
    byte getY(void){  return sly;  }
    byte getZ(void){  return srx;  }

private:

};


#endif

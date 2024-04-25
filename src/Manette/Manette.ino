#include <avr/pgmspace.h> 
#include <DigitalIO.h>
#include "ManetteTest.h"

byte Manette::jlx = 0;
byte Manette::jly = 0;
byte Manette::jrx = 0;
byte Manette::jry = 0;

Manette manette;

PsxControllerBitBang<PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK> psx;

void setup() {
    fastPinMode(PIN_BUTTONPRESS, OUTPUT);
    fastPinMode(PIN_HAVECONTROLLER, OUTPUT);

    delay(300);

    Serial.begin(115200);
    Serial.println(F("Ready!"));
}

void loop() {


    fastDigitalWrite(PIN_HAVECONTROLLER, haveController);

    if (!haveController) {
        if (psx.begin()) {
            Serial.println(F("Controller found!"));
            delay(300);
            if (!psx.enterConfigMode()) {
                Serial.println(F("Cannot enter config mode"));
            } else {
                PsxControllerType ctype = psx.getControllerType();
                PGM_BYTES_P cname = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr(&(controllerTypeStrings[ctype < PSCTRL_MAX ? static_cast<byte> (ctype) : PSCTRL_MAX])));
                Serial.print(F("Controller Type is: "));
                Serial.println(PSTR_TO_F(cname));

                if (!psx.enableAnalogSticks()) {
                    Serial.println(F("Cannot enable analog sticks"));
                }

                if (!psx.enableAnalogButtons()) {
                    Serial.println(F("Cannot enable analog buttons"));
                }

                if (!psx.exitConfigMode()) {
                    Serial.println(F("Cannot exit config mode"));
                }
            }
            haveController = true;
        }
    } else {
        if (!psx.read()) {
            Serial.println(F("Controller lost :("));
            haveController = false;
        } else {
            fastDigitalWrite(PIN_BUTTONPRESS, !!psx.getButtonWord());
            PsxButtons(psx.getButtonWord());
            testDump();
        }
    }
    delay(1000 / 60);
}

/*void testDump() {
    Serial.print("X : ");
    Serial.print(manette.getX());
    Serial.print(" Y : ");
    Serial.print(manette.getY());
    Serial.print(" Z : ");
    Serial.println(manette.getZ());
}*/

void testDump() {
        Serial.println(manette.getX());
        Serial.println(manette.getY());
        Serial.println(manette.getZ());
}


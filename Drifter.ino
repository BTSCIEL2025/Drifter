/*
 Name:		Drifter.ino
 Created:	19/04/2024 09:43:12
*/
// Importation des différentes libs
#include <DigitalIO.h>
#include <avr/pgmspace.h>
#include "src/Manette/Manette.h"
#include "src/Motor/Motor.h"

//définitions des objets et des constantes/variables
Manette manette;
Motor motor;

byte Manette::jlx = 0;
byte Manette::jly = 0;
byte Manette::jrx = 0;
byte Manette::jry = 0;

void setup() {
	fastPinMode(PIN_BUTTONPRESS, OUTPUT);
	fastPinMode(PIN_HAVECONTROLLER, OUTPUT);

	delay(300);

	Serial.begin(115200);
	Serial.println(F("Ready!"));
}

///////////////////////////////////////////////////////////////////

void loop() {
	Serial.println(manette.getX());
  Serial.println(manette.getY());
  Serial.println(manette.getZ());

  byte x = manette.getX();
  byte y = manette.getY();
  byte z = manette.getZ();

  motor.maj(x,y,z);
  motor.majsortie();
}


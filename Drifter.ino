/*
 Name:		Drifter.ino
 Created:	19/04/2024 09:43:12
*/
// Importation des différentes libs
#include <DigitalIO.h>
#include <avr/pgmspace.h>
#include "src/Manette/Manette.h"
#include "src/Motor/Motor.h"
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);

//définitions des objets et des constantes/variables
Manette manette;


byte Manette::jlx = 0;
byte Manette::jly = 0;
byte Manette::jrx = 0;
byte Manette::jry = 0;

Motor motor(&pca);
byte x = 0;
byte y = 0;
byte z = 0;

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println("Début du setup -----------------------------------------");
	fastPinMode(PIN_BUTTONPRESS, OUTPUT);
	fastPinMode(PIN_HAVECONTROLLER, OUTPUT);
  manette.setupController();
  motor.begin();
	delay(1000);
  Serial.println("Fin du setup -----------------------------------------\n");
	Serial.println(F("Ready!"));
}

///////////////////////////////////////////////////////////////////

void loop() {

  byte jlx, jly;

  byte z = manette.getZ();
  Serial.println(manette.controller.getLeftAnalog(jlx, jly));
  Serial.println(manette.getY());
  Serial.println(manette.getZ());
  motor.maj(x, y, z);
  delay(1000);
  motor.majsortie();


}


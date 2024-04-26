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

////////////////////////////////////////////////////////////////
  // DEPLACEMENT MANUEL

  if (!manette.haveController) 
  {
		if (manette.controller.begin ()) 
    {
			Serial.println (F("Controller found!"));
			delay (300);
			if (!manette.controller.enterConfigMode ()) 
      {
				Serial.println (F("Cannot enter config mode"));
			} 
      else 
      {
				PsxControllerType ctype = manette.controller.getControllerType ();
				PGM_BYTES_P cname = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr (&(controllerTypeStrings[ctype < PSCTRL_MAX ? static_cast<byte> (ctype) : PSCTRL_MAX])));
				Serial.print (F("Controller Type is: "));
				Serial.println (PSTR_TO_F (cname));

				if (!manette.controller.enableAnalogSticks ()) 
        {
					Serial.println (F("Cannot enable analog sticks"));
				}
				
				//~ if (!psx.setAnalogMode (false)) {
					//~ Serial.println (F("Cannot disable analog mode"));
				//~ }
				//~ delay (10);
				
				if (!manette.controller.enableAnalogButtons ()) 
        {
					Serial.println (F("Cannot enable analog buttons"));
				}
				
				if (!manette.controller.exitConfigMode ()) 
        {
					Serial.println (F("Cannot exit config mode"));
				}
			}			
			manette.haveController = true;
		}
	} 
  else 
  {
		if (!manette.controller.read ())   // si l'on arrive pas à lire la telecommande
    {
			Serial.println (F("Controller lost :("));
			manette.haveController = false;
		} 
    else 
    {
	// LS   		fastDigitalWrite (PIN_BUTTONPRESS, !!psx.getButtonWord ());
			manette.dumpButtons (manette.controller.getButtonWord ());  

			byte lx, ly;
			manette.controller.getLeftAnalog (lx, ly);
			if (lx != slx || ly != sly)  // si different de la valeur précedante aaa
      {
				manette.dumpAnalog ("Left", lx, ly);  
				slx = lx;   // on save la derniere valeur 
				sly = ly;
			}

			byte rx, ry;
			manette.controller.getRightAnalog (rx, ry);
			if (rx != srx || ry != sry) {     // si different de la valeur précedante aaa
				manette.dumpAnalog ("Right", rx, ry);   // on affiche
				srx = rx;
				sry = ry;
			}
		}
	}
  delay (1000 / 60);

  Serial.print("\n   lx: "); Serial.print(manette.getX());
  Serial.print("   ly: "); Serial.print(manette.getY());
  Serial.print("   rx: "); Serial.print(manette.getZ());
  motor.maj(slx, sly, srx);
  motor.majsortie();

//////////////////////////////////////// FIN UTILISATION MANUELLE
}


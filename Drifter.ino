/*
 Name:		Drifter.ino
 Created:	19/04/2024 09:43:12
*/
// Importation des différentes libs
#include <Arduino.h>
#include <DigitalIO.h>
#include <avr/io.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h>
#include "src/Manette/Manette.h"
#include "src/Motor/Motor.h"
#include "src/Ecran/Automate.h"
#include "src/Ecran/Ecran.h"
#include "src/Bouton/Bouton.h"
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);

//////////////////////////////////// DEFINITIONS //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
#define NUM_DIGITAL_PINS 20

Manette manette;
Motor motor(&pca);
Bouton monclav;
Ecran monecran;
Automate monauto;

unsigned long lastTransitionTime = 0;
const unsigned long debounceDelay = 200;
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println("Début du setup -----------------------------------------");
    // INITIALISATION ECRAN OLED
  monecran.initial();
  monecran.erase();

  // INITIALISATION MOTEURS ET MANETTE 
	fastPinMode(PIN_BUTTONPRESS, OUTPUT);
	fastPinMode(PIN_HAVECONTROLLER, OUTPUT);
  manette.setupController();
  motor.begin();
  //FIN INTIALISATION MOTEURS ET MANETTE

	delay(1000);
  // arret des moteurs(128 étant le point 0):
  motor.maj(128, 128, 128);
  motor.majsortie();

  Serial.println("Fin du setup -----------------------------------------\n");
	Serial.println(F("Ready!"));
}

///////////////////////////////////////////////////////////////////

void loop() {

////////////////////////////////////////////////////////////////
////// AFFICHAGE ECRAN (ECRAN ET BOUTON ET AUTOMATE) ///////////
////////////////////////////////////////////////////////////////

int transition = monclav.readButton();
    static int etat = 0;
    static int lastTransition = -1;

    // Mettre à jour l'état de l'automate en fonction de la transition du bouton
    if (transition != -1 && (millis() - lastTransitionTime) > debounceDelay) {
        lastTransitionTime = millis();
        etat = monauto.getAutomValue(transition, etat);
    }
    
    switch(etat) {
      case 6:
////////////////////////////////////////////////////////////////
/////////// DEPLACEMENT MANUEL (MANETTE ET MOTEURS) ///////////
////////////////////////////////////////////////////////////////

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
			fastDigitalWrite (PIN_BUTTONPRESS, !!manette.controller.getButtonWord ());
			manette.dumpButtons (manette.controller.getButtonWord ());  

			byte lx, ly;
			manette.controller.getLeftAnalog (lx, ly);
			if (lx != slx || ly != sly)  // si different de la valeur précedante aaa
      {
				//manette.dumpAnalog ("Left", lx, ly);  
				slx = lx;   // on save la derniere valeur 
				sly = ly;
			}

			byte rx, ry;
			manette.controller.getRightAnalog (rx, ry);
			if (rx != srx || ry != sry) {     // si different de la valeur précedante aaa
				//manette.dumpAnalog ("Right", rx, ry);   // on affiche
				srx = rx;
				sry = ry;
			}
		}
	}
  // LS delay (1000 / 60);

  Serial.print("\nlx="); Serial.print(manette.getX()); // get X joystick gauche (pivot)
  Serial.print(" ly="); Serial.print(manette.getY()); // get Y joystick gauche (avance)
  Serial.print(" rx="); Serial.print(manette.getZ()); // get X joystick droit (pivot)


  // SRX = PIVOT X (A dans maj() ??)
  // SLY = AVANCE/RECUL Y GAUCHE (B dans maj() ??)
  // SLX = TRANSLATION X GAUCHE (C dans maj() ??)
  /*
  srx = 128;
  sly = 128;
  slx = 128;
*/
  motor.maj(sly, srx, slx);
   
  motor.majsortie();

//delay(3000);

  	//pca.writeMicroseconds(0,2000); // Moteur 1 
		//pca.writeMicroseconds(1,2000); // Moteur 2
		//pca.writeMicroseconds(2,2000); // Moteur 3
		//pca.writeMicroseconds(3,2000);  // Moteur 4



//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// FIN UTILISATION MANUELLE ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


        break;
      case 9:

        break;
    }
    monecran.erase(); 
    monecran.afficher(etat);
    Serial.println(etat);



//end loop
}


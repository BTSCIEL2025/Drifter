#include "Pompe.h"

// --------------------------- constructeurs --------------------------- 
Pompe::Pompe()
{
	duree     = 3000;					  // Arrosera pendant 1 seconde
	dateDebut = 0;					    // dtae du debut d'arrosage
	enFct     = false;					// Pompe initialement eteinte
}


void Pompe::maj(void)
{    
  Serial.println();
  Serial.print(" Maj");
  Serial.print("    duree: ");   Serial.print(duree);
  Serial.print("    date debut: ");   Serial.print(dateDebut);
  Serial.print("    enFct: ");   Serial.print(enFct);
  Serial.print("    millis(): ");   Serial.print(millis());
  
  
  // --------------------------- pour test a modifier pour reel --------------------------- 
  // ---------------------------------- POUR MARCHE ---------------------------------- 
	if (!digitalRead(3) && !enFct)                          // Pompe a l arret -> Demande le demarrage
	{
		miseOn();                                             // MISE EN ROUTE
	}
  // ---------------------------------- POUR ARRET ---------------------------------- 
  else
	if (
    		( !digitalRead(2) && (enFct == true))             // En fonctionnement et on aliment 2 = STOP
	        ||                                              // OU 
         (enFct && (dateDebut+duree < millis()) )         // En fonctionnement et on à dépasse le temps défini = STOP
         )    
	{
		miseOff();                                             // MISE A L ARRET
	}

}

void Pompe::miseOn()
{
	enFct     = true;
	dateDebut = millis();
  Serial.println("On");

}

void Pompe::miseOff()
{
	enFct     = false;
	dateDebut = 0;
  Serial.println("Off");
}

bool Pompe::getEnFct() 
{
	return enFct;

}
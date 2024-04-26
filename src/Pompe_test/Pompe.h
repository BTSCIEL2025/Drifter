#ifndef POMPE_H
#define POMPE_H
#include <Adafruit_PWMServoDriver.h>    // pour module PCA9586 16 chanel 12 bits (violet)

#define PMW Adafruit_PWMServoDriver(0x40)

class Pompe
{
public :
	Pompe();                
	void maj(void);         //MAJ de l'objet
	void miseOn(void);      // Mise en route
	void miseOff(void);     // Mise en arret

	bool getEnFct();        // true = en fonctionnement ----- false = arretée

private :
	long duree;             // temps d'arrosage
	long dateDebut;         // date de debut d'arrosage
	bool enFct;							// 1 = On --- 0 = Off
	Adafruit_PWMServoDriver pwm; //variable nécésaire au servo moteur
};
#endif 
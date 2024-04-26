#ifndef GYRO_H
#define GYRO_H


#include <Adafruit_PWMServoDriver.h>    // pour module PCA9586 16 chanel 12 bits (violet)
#define PIN_LED 15

class Gyro
{
	public :

    //Constructeurs
		gyro();
		gyro(int, int,Adafruit_PWMServoDriver*);

    //Getteurs
		bool getEtat();
		int getdOn();
    int getdOff();
    long getDateDebut();
    bool getEtatLampe();

    //Setters 
    void setEtat(bool);
    void setdOn(int);
    void setdOff(int);
    void setDateDebut(long);
    void setEtatLampe(bool);

    //Autres fonctions
		void miseOn();
		void miseOff();
    void maj();

	private :
		int dOn;                    //durée led allumée
		int dOff;                   //durée led eteinte
		bool etat;                  // etat du module
    long dateDebut;             //en ms
    bool etatLampe;             //etat de la led
    Adafruit_PWMServoDriver *pwm; //variable nécésaire au servo moteur

};
#endif 

/*Semaine projet Drifter
  Sonar
  Mougin Léane
  24/04/24
  version 1
*/

// Fichier de d�finition de la classe Sonar
/*
Le sonar contient un capteur de lumi�re attach� sur un servo moteur allant jusqu'a 270° qui permet sa rotation
Il doit scanner tout l'environnement autour de lui et analyser si il y a une zone plus lumineuse
que le reste et nous indiquer la zone en degr�.
*/

#ifndef SONAR_H
#define SONAR_H

//Bbibliotheques et constantes necessaires au servo moteur
#include <Wire.h>                       // pour utilisation de l'I2C.
#include <Adafruit_PWMServoDriver.h>    // pour module PCA9586 16 chanel 12 bits (violet)
#define MIN_PULSE_WIDTH  600   //  Largeur minimum de l'impulsion: pour puissance minimum
#define MAX_PULSE_WIDTH 2600   //  Largeur maximum de l'impulsion : pour Puissance max
#define FREQUENCY        50    //  50hz d'origine.

#define MAX_VAL 40
#define PIN_CAPT_LUM A1
#define CANALSERVO 4
#define DELTAOFEU 50


class Sonar
{
public:
	// Constructeurs
	Sonar();                //initialisé à 10 valeurs sur 270°
	Sonar(int, int, int,Adafruit_PWMServoDriver*);   //angle de rotation max du servo,nbr de mesures voulue par tour, intervalle de temps entre chaque mesure

	// Getters
  int getOrientation() const;
	bool getEtat() const;
  int getNbMesure() const;
	int getLecture(int) const;  //le rang du tableau voulu en paramètre
	long getDateDebut() const;
	int getIntervalle() const;
	int getAvance() const;
  int getFeu() const;
  int getSens() const;
  int getNbTour() const;

	//Setters
	void setOrientation(int);
	void setEtat(bool);
  void setNbMesure(int);
	void setLecture(int,int);
	void setDateDebut(long);
	void setIntervalle(int);
	void setAvance(int);
  void setFeu(int);
  void setSens(int);
  void setNbTour(int);


	//Autres fonctions
	void miseOn();          //Allume le module
	void miseOff();         //eteint le module
	void maj();             //Met a jour le module
	int lireLum();          //lit la valeur de la lumière en ohm
	int moyLum();           //fait la moyenne de toutes les valeurs du tableau déjà rentrées
	int maxLum();           //indique la valeur la valeur du tableau qui indique la lumière la plus forte
	int rangLumMax();       //indique le rang du tableau pour lequel la lumière est la plus forte
	int oFeu();					    //renvoie l'angle du feu si il y a, -1 sinon
  int pulseWidth(int);    //fonction convertisantles degrés en valeur analogique pour le servo


private:
	bool etat;			          // 1 = en marche, 0 sinon
	int orientation;	      //en degr?s
  int nbMesure;           //nombre de mesures effectuée sur une rotation
	int lecture[MAX_VAL];	  //tableau contenant les valeurs lues
	long dateDebut;	        //en ms
	int intervalle;		      //en ms
	int avance;			        //combien de mesures ont deja �t� faites
  int feu;                //indique l'angle du feu, -1 si il n'y a pas le feu
  int sens;               //horaire 1 ou anti-horaire -1
  int nbTours;            //Nombre de tours complets qu'a fait le sonar 
  Adafruit_PWMServoDriver *pwm; //variable nécésaire au servo moteur
};
#endif // !SONAR_H

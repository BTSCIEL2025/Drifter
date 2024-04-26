/*
 * Semaine projet Drifter
 * MOUGIN Léane
 * Bibliotheque du module radar
 * 24/04/24
 * Le radar permetra de recuperer la distance entre le drifter et la surface ou objet devant lui dans
 * une fourchette de 3 cm à 4m
*/

#ifndef RADAR_H
#define RADAR_H

#define LONGMIN 3                 // longeur minimale pouvant etre mesurée
#define LONGMAX 400               // longeur maximale pouvant etre mesurée
#define FREQMESURE 1000           // intervalle entre chaque mesure

class Radar
{
  public: 

    // Constructeurs

    Radar();                    
    Radar(int,int,int);              // Numéro , broche tirg, broche echo

    // Getters

    bool getEtat() const;
    int  getNum() const;
	  long getDistance() const;
	  int  getTrig() const;
	  int  getEcho() const;
    long  getDateDebut() const;


    //Setters

    void setEtat(bool);
    void setNum(int);
	  void setDistance(long);
	  void setTrig(int);
	  void setEcho(int);
    void setDateDebut(long);


    //Autres fonctions

    void miseOn();                    // Allume le module
	  void miseOff();                   // Eteint le module
	  void maj();                       // Met a jour le module

  

  private:
    bool etat;                         // 1 = en marche, 0 sinon
    int  num;                          // Numero de matricule
    long distance;                     // En cm, -1 si moins de 3cm , -2 si plus de 4m
    int  trig;                         // A quoi est relié la broche Trig
    int  echo;                         // A quoi est relié la broche Echo
    long  dateDebut;                   // En ms

};
#endif // !RADAR_H

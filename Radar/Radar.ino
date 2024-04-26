/*
 * Semaine projet Drifter
 * MOUGIN Léane
 * Definition du module radar
 * 24/04/24
 * Le radar permetra de recuperer la distance entre le drifter et la surface ou objet devant lui dans
 * une fourchette de 3 cm à 4m
*/

#include "Radar.h"
using namespace std;

//Constructeurs par défaults---------------------------------------------------------------------------------

Radar::Radar(){
  etat = false;                        
  num = 0;                          
  distance = 0;                   
  trig = 0;                
  echo = 0; 
  dateDebut = millis();
}

Radar::Radar(int monNum, int monTrig, int monEcho){
  etat = false;                        
  num = monNum;                          
  distance = 0;                   
  trig = monTrig;                
  echo = monEcho; 
  dateDebut = millis();
}

//Getteurs--------------------------------------------------------------------------------------------------

bool Radar::getEtat() const{
  return etat;
}

int Radar::getNum() const{
  return num;
}

long Radar::getDistance() const{
  return distance;
}

int Radar::getTrig() const{
  return trig;
}

int Radar::getEcho() const{
  return echo;
}

long Radar::getDateDebut() const{
  return dateDebut;
}


//Setteurs-----------------------------------------------------------------------------------------------

void Radar::setEtat(bool etat){
  this-> etat = etat;
}

void Radar::setNum(int num){
  this-> num = num;
} 

void Radar::setDistance(long dist){
  this-> distance = dist;
}

void Radar::setTrig(int trig){
  this-> trig = trig;
}

void Radar::setEcho(int echo){
  this-> echo = echo;
}

void Radar::setDateDebut(long date)
{
  this-> dateDebut = date;
}


//Autres fonctions----------------------------------------------------------------------------------------

void Radar::miseOn(){
  setEtat(true);
  pinMode(getTrig(), OUTPUT);                           // Broche Trigger en sortie //
  pinMode(getEcho(), INPUT);                            // Broche Echo en entree //
}  

void Radar::miseOff(){
  setEtat(false);
}   

void Radar::maj(){
  
  long duree;
  if(getEtat()){
    if(millis() > getDateDebut() + FREQMESURE){

      setDateDebut(millis());

      digitalWrite(getTrig(), LOW);                     // On efface l'etat logique de TRIG //
      delayMicroseconds(2);
      digitalWrite(getTrig(), HIGH);                    // On met la broche TRIG a "1"//
      delayMicroseconds(10);
      digitalWrite(getTrig(), LOW);                     // On remet la broche TRIG a "0" //
      
      duree = pulseIn(getEcho(), HIGH);                 // On mesure combien de temps le niveau logique haut est actif sur ECHO //
      setDistance(duree * 0.034 / 2);

      if(getDistance() < LONGMIN ){
        setDistance(-1);
      }
      if(getDistance() > LONGMAX){
        setDistance(-2);
      }
    }
    
  }
}

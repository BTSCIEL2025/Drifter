#include "Gyro.h"

//constructeurs

Gyro::gyro()
{
	dOn = 1000;
	dOff = 1000;
	etat = false;
  dateDebut = -1;
  etatLampe = false;
}

Gyro::gyro(int on, int off,Adafruit_PWMServoDriver *pwm)
{
	dOn = on;
	dOff = off;
	etat = false;
  dateDebut = -1;
  etatLampe = false;
}

//Guetteurs

int Gyro::getdOn()
{
  return dOn;
}
int Gyro::getdOff()
{
  return dOff;
}

bool Gyro::getEtat(){
  return etat;
}

long Gyro::getDateDebut(){
  return dateDebut;
}

bool Gyro::getEtatLampe(){
  return etatLampe;
}

//Setters

void Gyro::setdOn(int a)
{
  dOn = a;
}
void Gyro::setdOff(int a)
{
  dOff = a;
}

void Gyro::setEtat(bool a){
  etat = a;
}

void Gyro::setDateDebut(long a){
  dateDebut = a;
}

void Gyro::setEtatLampe(bool a){
  etatLampe = a;
}

//Autres fonctions

void Gyro::miseOn()
{
  setEtat(true);
  digitalWrite(PIN_LED, HIGH);
  setDateDebut(millis()); 
  
}

void Gyro::miseOff() 
{
  setEtat(false);
  digitalWrite(PIN_LED, LOW);
}

void Gyro::maj() 
{
  if(getEtat()){
    static bool majFaite = false; // Déclaration statique pour conserver la valeur entre les appels
    if(millis() > getDateDebut() + getdOn() && !majFaite){
      if(getEtatLampe()){   
          digitalWrite(PIN_LED, LOW);
          setEtatLampe(false);
          Serial.println("on");
        }
      if(!getEtatLampe()){
        digitalWrite(PIN_LED, HIGH);
        setEtatLampe(true);
        Serial.println("off");
      }
      setDateDebut(millis());
      majFaite = true;
    }else{
      majFaite = false;
    }
  }
}


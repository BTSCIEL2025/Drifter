#include "Gyro.h"

//constructeurs
Gyro::gyro()
{
	dOn = 1000;
	dOff = 1000;
	etat = 0;	//OFF
}
	void Gyro::marche()
	{
		etat = 1;
		digitalWrite(A0, HIGH);
	}
	void Gyro::arret() 
	{
		etat = 0;
		digitalWrite(A0, LOW);
	}
	int Gyro::getdOn()
	{
		return dOn;
	}
 	int Gyro::getdOff()
	{
		return dOff;
	}
  void Gyro::setdOn(int a)
  {
    dOn = a;
  }
  void Gyro::setdOff(int a)
  {
    dOff = a;
  }
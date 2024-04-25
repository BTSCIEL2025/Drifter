#include "Gyro.h"

Gyro mongyro;
void setup()
{
pinMode(A0,OUTPUT);
Serial.begin(115200);
}
void loop()
{
// lecture des entrées




// traitement et affectations des objets




// affectation des sorties




mongyro.marche();
  Serial.println("JE SUIS LA");
  mongyro.setdOn(1000);
	delay(mongyro.getdOn());

mongyro.arret();
  Serial.println("JE SUIS PAS LA");
  mongyro.setdOff(1000);
	delay(mongyro.getdOff());
}
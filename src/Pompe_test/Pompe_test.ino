#include "Pompe.h"

	Pompe maPompe;

void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  Serial.println("Fin de setup");
}
void loop()
{
                                          // 1 traitement copie des entree
    maPompe.maj();                        // 2 traitement de l'objet et de entrees
    digitalWrite(4,maPompe.getEnFct());   // 3 traitement : recopie sur la sortie
    delay(500);
}

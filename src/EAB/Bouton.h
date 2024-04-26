#ifndef BOUTON_H
#define BOUTON_H
#include <Arduino.h>
#include "Ecran.h"

#define buttonPin A3 // Broche pour les boutons

class Bouton
{
private:

public:
    int readButton() {
    int analogValue = analogRead(buttonPin);

    // Déterminer quel bouton est appuyé en fonction de la tension lue
    if (analogValue < 100) {
        return 0; // RIGHT
        Serial.println("RIGHT");
    }
    else if (analogValue < 300) {
        return 3; // UP
        Serial.println("UP");
    }
    else if (analogValue < 500) {
        return 2; // DOWN
        Serial.println("DOWN");
    }
    else if (analogValue < 700) {
        return 1; // LEFT
        Serial.println("LEFT");
    }
    else if (analogValue < 900) {
        return 4; // SELECT
        Serial.println("SELECT");
    }
    else {
        return -1; // Aucun bouton détecté
    }
}

};
#endif

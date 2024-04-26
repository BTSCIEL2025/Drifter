#ifndef ECRAN_H
#define ECRAN_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Automate.h"

#define SCREEN_WIDTH 128 // Largeur de l'écran OLED en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED en pixels

#define OLED_RESET -1 // Reset de l'écran OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Configuration de l'écran

class Ecran {
  private: 
    Automate automate;

  public:
    void initial();
    void erase();
    void afficher(int);
};
#endif
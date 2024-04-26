#include "Ecran.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



void Ecran::initial() {
  Serial.begin(9600);
  // Initialisation de l'écran OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
    Serial.println(F("Écran SSD1306 non trouvé"));
    for (;;);
  }
}

void Ecran::erase() {
  display.clearDisplay();
}

void Ecran::afficher(int etat) {
  switch(etat) {
    case 0:
      display.setTextSize(1); // Taille du texte
      display.setTextColor(SSD1306_WHITE); // Couleur du texte (blanc)
      display.setCursor(10, 10);
      display.println(F("Accueil - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE); // Ligne horizontale
      display.setTextSize(1);
      display.setCursor(10, 30);
      display.println(F("Press RIGHT"));
      display.setCursor(10, 50);
      display.println(F("to continue..."));
      display.display();
      break;
    case 1:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(5, 10);
      display.print(">");
      display.println(F("Demarrage"));
      display.setTextSize(1);
      display.setCursor(5, 30);
      display.print("-");
      display.println(F("Configuration"));
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Maintenance"));
      display.display();
      break;
    case 2:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(5, 10);
      display.print("-");
      display.println(F("Demarrage"));
      display.setTextSize(1);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Configuration"));
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Maintenance"));
      display.display();
      break;
    case 3:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(5, 10);
      display.print("-");
      display.println(F("Demarrage"));
      display.setTextSize(1);
      display.setCursor(5, 30);
      display.print("-");
      display.println(F("Configuration"));
      display.setCursor(5, 50);
      display.print(">");
      display.println(F("Maintenance"));
      display.display();
      break;
    case 4:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Demarrage - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Manuel"));
      display.setTextSize(1);
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Automatique"));
      display.display();
      break;
    case 5:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(10, 10);
      display.println(F("Demarrage - Drifter")); 
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print("-");
      display.println(F("Manuel"));
      display.setTextSize(1);
      display.setCursor(5, 50);
      display.print(">");
      display.println(F("Automatique"));
      display.display();
      break;
    case 6:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("D. Manuel - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Demarrage"));
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("manuel active"));
      display.display();
      break;
    case 7:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("D. Manuel - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Souhaitez-vous"));
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("quitter le mode ?"));
      display.display();
      break;
    case 8:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("D. Auto. - Drifter")); 
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Demarrage"));
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("auto. active"));
      display.display();
      break;
    case 9:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("D. Auto - Drifter")); 
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Souhaitez-vous"));
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("quitter le mode ?"));
      display.display();
      break;
    case 10:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Maint. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Capteur Lumino."));
      display.setTextSize(1);
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Servo moteur"));
      display.display();
      break;
    case 11:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Maint. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Servo moteur"));
      display.setTextSize(1);
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Pompe a eau"));
      display.display();
      break;
    case 12:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Maint. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Pompe a eau"));
      display.setTextSize(1);
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Sonar 1"));
      display.display();
      break;
    case 13:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Maint. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Sonar 1"));
      display.setTextSize(1);
      display.setCursor(5, 50);
      display.print("-");
      display.println(F("Sonar 2"));
      display.display();
      break;
    case 14:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Maint. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(5, 30);
      display.print(">");
      display.println(F("Sonar 2"));
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("Fin Maintenance"));
      display.display();
      break;
    case 15:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(10, 10);
      display.println(F("Lumino. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Lumino : OK"));
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("SELECT pour Finir"));
      display.display();
      break;
    case 16:
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
      display.println(F("Servo. - Drifter")); 
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Rotation : OK")); // Intégrer vérification de la rotation des Servo
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("SELECT pour Finir"));
      display.display();
      break;
    case 17:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(10, 10);
      display.println(F("Pompe. - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Pompe : OK")); // Intégrer vérification de la pompe
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("SELECT pour Finir"));
      display.display();
      break;
    case 18:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(10, 10);
      display.println(F("Sonar 1 - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Sonar : OK")); // Intégrer vérification du sonar 1
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("SELECT pour Finir"));
      display.display();
      break;
    case 19:
      display.setTextSize(1); 
      display.setTextColor(SSD1306_WHITE); 
      display.setCursor(10, 10);
      display.println(F("Sonar 2 - Drifter"));
      display.drawFastHLine(0, SCREEN_HEIGHT / 3, SCREEN_WIDTH, SSD1306_WHITE);
      display.setCursor(0, 30);
      display.println(F("Sonar : OK")); // Intégrer vérification du sonar 2
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.println(F("SELECT pour Finir"));
      display.display();
      break;
}
display.display();
}


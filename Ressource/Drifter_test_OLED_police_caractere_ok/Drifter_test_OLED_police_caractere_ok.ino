/*
   ______               _                  _///_ _           _                   _
  /   _  \             (_)                |  ___| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier :       autresPolicesDeCaracteresSsd1306.ino
  
  Description :   Affiche des texte avec des polices de caractères différentes,
                  sur un écran OLED i2c faisant 128x64 pixels (contrôleur SSD1306)

  Auteur :        Jérôme TOMSKI (https://passionelectronique.fr/)
  Créé le :       26.07.2021

  /// ATTENTION \\\ : LES POLICES DE CARACTÈRES PRENNENT BEAUCOUP DE PLACE EN MÉMOIRE. Utilisez les donc avec parcimonie !

  Convertisseur TTF vers GFX FONTS utilisé : https://rop.nl/truetype2gfx/

*/

#include <Adafruit_SSD1306.h>


//========= Police de caractère : AlarmClock (https://www.dafont.com/fr/alarm-clock.font)

//#include "alarm_clock6pt7b.h"                       // Normal, en 6 pts

//========= Police de caractère : FreeMono (fournie avec librairie Adafruit GFX)

#include <Fonts/FreeMono9pt7b.h>                    // Normal (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeMono12pt7b.h>
//#include <Fonts/FreeMono18pt7b.h>
//#include <Fonts/FreeMono24pt7b.h>

//#include <Fonts/FreeMonoBold9pt7b.h>              // Gras (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeMonoBold12pt7b.h>
//#include <Fonts/FreeMonoBold18pt7b.h>
//#include <Fonts/FreeMonoBold24pt7b.h>

//#include <Fonts/FreeMonoOblique9pt7b.h>           // Italique (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeMonoOblique12pt7b.h>
//#include <Fonts/FreeMonoOblique18pt7b.h>
//#include <Fonts/FreeMonoOblique24pt7b.h>

//#include <Fonts/FreeMonoBoldOblique9pt7b.h>       // Gras + Italique (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeMonoBoldOblique12pt7b.h>
//#include <Fonts/FreeMonoBoldOblique18pt7b.h>
//#include <Fonts/FreeMonoBoldOblique24pt7b.h>

//========= Police de caractère : FreeSans (fournie avec librairie Adafruit GFX)

#include <Fonts/FreeSans9pt7b.h>                    // Normal (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSans12pt7b.h>
//#include <Fonts/FreeSans18pt7b.h>
//#include <Fonts/FreeSans24pt7b.h>

//#include <Fonts/FreeSansBold9pt7b.h>              // Gras (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSansBold12pt7b.h>
//#include <Fonts/FreeSansBold18pt7b.h>
//#include <Fonts/FreeSansBold24pt7b.h>

//#include <Fonts/FreeSansOblique9pt7b.h>           // Italique (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSansOblique12pt7b.h>
//#include <Fonts/FreeSansOblique18pt7b.h>
//#include <Fonts/FreeSansOblique24pt7b.h>

//#include <Fonts/FreeSansBoldOblique9pt7b.h>       // Gras + Italique (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSansBoldOblique12pt7b.h>
//#include <Fonts/FreeSansBoldOblique18pt7b.h>
//#include <Fonts/FreeSansBoldOblique24pt7b.h>

//========= Police de caractère : FreeSerif (fournie avec librairie Adafruit GFX)

#include <Fonts/FreeSerif9pt7b.h>                   // Normal (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSerif12pt7b.h>
//#include <Fonts/FreeSerif18pt7b.h>
//#include <Fonts/FreeSerif24pt7b.h>

//#include <Fonts/FreeSerifBold9pt7b.h>             // Gras (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSerifBold12pt7b.h>
//#include <Fonts/FreeSerifBold18pt7b.h>
//#include <Fonts/FreeSerifBold24pt7b.h>

//#include <Fonts/FreeSerifItalic9pt7b.h>           // Italique (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSerifItalic12pt7b.h>
//#include <Fonts/FreeSerifItalic18pt7b.h>
//#include <Fonts/FreeSerifItalic24pt7b.h>

//#include <Fonts/FreeSerifBoldItalic9pt7b.h>       // Gras + Italique (en 9, 12, 18, et 24 pts)
//#include <Fonts/FreeSerifBoldItalic12pt7b.h>
//#include <Fonts/FreeSerifBoldItalic18pt7b.h>
//#include <Fonts/FreeSerifBoldItalic24pt7b.h>


#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3D        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);   // Le "Wire" indique qu'on travaille en I2C


// ========================
// Initialisation programme
// ========================
void setup() {

  // Initialisation de l'écran OLED
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);                               // Arrêt du programme (boucle infinie) si échec d'initialisation
  

  // Affichage d'un texte "Hello World", avec une des autre polices disponibles 
  ecranOLED.clearDisplay();                 // Vidange du buffer de l'écran OLED
  ecranOLED.setTextSize(1);                 // Sélection de l'échelle 1:1
  ecranOLED.setTextColor(WHITE);            // Couleur "blanche" (ou colorée, si votre afficheur monochrome est bleu, jaune, ou bleu/jaune)
  ecranOLED.setCursor(0,1);                 // Positionnement du curseur dans l'angle haut-gauche, avec décalage de 1 pixel vers le bas

  //ecranOLED.setFont(&alarm_clock6pt7b);     // Sélection de la police "Alarm Clock"
  ecranOLED.println("AlarmClock  sdfmlkgmlkhfdqmlkheem(origfmlkhemtorgijmoidjhglkjqlmgd");            // …et affichage du nom de cette police

  ecranOLED.setFont(&FreeMono9pt7b);        // Sélection de la police "Free Mono"
  ecranOLED.println("FreeMono");            // …et affichage du nom de cette police

  ecranOLED.setFont(&FreeSans9pt7b);        // Sélection de la police "Free Sans"
  ecranOLED.println("FreeSans");            // …et affichage du nom de cette police

  ecranOLED.setFont(&FreeSerif9pt7b);       // Sélection de la police "Free Serif"
  ecranOLED.println("FreeSerif");           // …et affichage du nom de cette police

  ecranOLED.display();

  // Nota : pour revenir à la police de caractère "d'origine", il suffit d'écrire la ligne : display.setFont();
  
}


// =================
// Boucle principale
// =================
void loop() {
  // Boucle sans fin (code principal dans partie "setup", en fait)
  
}
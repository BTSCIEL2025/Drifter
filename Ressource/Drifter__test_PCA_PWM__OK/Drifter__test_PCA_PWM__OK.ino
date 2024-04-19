/*****************************************************************************************

Fichier :    Drifter__test_PCA_PWM__OK  
             avec arduino UNO pas de resistance de rapel ni sur SCL ni sur SDA
LS.
//-------------------------------------------
utilisation avec NODE MCU ESP8266:

à voir:  https://electropeak.com/learn/interfacing-pca9685-16-channel-12-bit-pwm-servo-driver-with-arduino/

----------------------------------
l.SPI:
carte PCA SEED STUdIO sans mofification d'adresse.
groove - 16 - channel PWM Driver(PCA9685)
Adafruit_PWMServoDriver(0x7F);
SCL A5 sur ARDUINO UNO
SDA A4 sur ARDUINO UNO 
GND sur Esp GND 
VCC sur Esp Vin


Puissance 
    VCC à 5V
    alim servo 5V


!!!   ATTENTION
!!!  les servo-moteurs font chuter la tension d'alimentation 5 v qui vient du port USB
!!!   ==> ce qui peut provoquer le RESET du microcontroleur
//-------------------------------------------

((utilisation avec Arduino NANO:
((SCL sur D4
((SDA sur D5
(( et adresse 0x7F 

//-------------------------------------------


*****************************************************************************************/
#include "Wire.h"                       // pour utilisation de l'I2C.
#include "Adafruit_PWMServoDriver.h"    // pour module PCA9586 16 chanel 12 bits (violet)

//  ls27/03/2024Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x7F);   // sur l'adafruit j'ai shunté tous les strap   //(0x40); // sur l'adafruit d'originecréation de l'objet pwm
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);   //  28/03/2024 couleur Jaune Rouge Noir sans strap  //(0x40); // sur l'adafruit d'originecréation de l'objet pwm

#define MIN_PULSE_WIDTH  600   //  Largeur minimum de l'impulsion: pour puissance minimum
#define MAX_PULSE_WIDTH 2600   //  Largeur maximum de l'impulsion : pour Puissance max
#define FREQUENCY        50    //  50hz d'origine.
                               // si l'on met 400 pour 400 hz ==> le led s'etteind!!!

void setup() {
  pwm.begin(); 
  pwm.setPWMFreq(FREQUENCY);
}


/********************************************************
retourne une valeur 
********************************************************/
int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void loop() {
  pwm.setPWM(0, 0, pulseWidth(0));       
  /*
  reference: https://learn.adafruit.com/16-channel-pwm-servo-driver/library-reference
      Arguments of:   pwm.setPWM(0, 0, pulseWidth(0));   : 
                     channel: The channel that should be updated with the new values (0..15)
                     on:      The tick (between 0..4095) when the signal should transition from low to high
                     off:     the tick (between 0..4095) when the signal should transition from high to low
  */
 

  for(int i =0 ;i<3; i++)  // pour chnager les Sorties 0 à 2 du PWM
  { 
            // Chanel   dureeOn     duree O
    pwm.setPWM(   i,        0,    pulseWidth(45));   delay(200);
    pwm.setPWM(   i,        0,    pulseWidth(90));   delay(200);
    pwm.setPWM(   i,        0,    pulseWidth(135));  delay(200);
    pwm.setPWM(   i,        0,    pulseWidth(170));  delay(200); 
    pwm.setPWM(   i,        0,    pulseWidth(0));    delay(200);
 
  }
}
using namespace std;

#include "Sonar.h"
#define PMW Adafruit_PWMServoDriver(0x40)


int light = 0; // intitialise la valeur de la lumière
Sonar test = Sonar();


void setup(){
  Serial.begin(9600); // configure serial to talk to computer
  test.miseOn();
}

void loop(){
    while(test.getNbTour()<2){
      test.maj();
    }
      test.miseOff();
      for(int i = 0; i< 10; i++){
        Serial.println(test.getLecture(i));
      }
      Serial.println(test.oFeu());
    delay(500000);
}

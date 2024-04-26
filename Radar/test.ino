using namespace std;

#include "Radar.h"

Radar test1 = Radar(1,3,2);
Radar test2 = Radar(1,5,4);


void setup(){
  Serial.begin(115200); // configure serial to talk to computer
  test1.miseOn();
  test2.miseOn();
}

void loop(){
  test1.maj();
  Serial.print("radar 1 : ");
  Serial.println(test1.getDistance());
  test2.maj();
  Serial.print("radar 2 : ");
  Serial.println(test2.getDistance());
  delay(1000);
}

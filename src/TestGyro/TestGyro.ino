#include "Gyro.h"
#define PMW Adafruit_PWMServoDriver(0x40)


Gyro test = Gyro();

void setup()
{
  Serial.begin(115200);
  test.miseOn();
}
void loop()
{
}
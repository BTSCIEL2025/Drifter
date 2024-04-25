#include "Motor.h"
#include <Wire.h>//https://www.arduino.cc/en/reference/wire
#include <Adafruit_PWMServoDriver.h>//https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library

void setup()
{
Serial.begin(115200);
Serial.println(("Initialize System"));
	Motor motor;
	motor.maj();
	motor.majsortie();
	delay(1000);
	motor.A = 0;
	motor.B = 0;
	motor.C = 0;
	motor.maj();
	motor.majsortie();
  Serial.println(("Fin de setup"));
}
void loop()
{

}
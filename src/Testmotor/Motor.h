#ifndef MOTOR_H
#define MOTOR_H
#include <Wire.h>//https://www.arduino.cc/en/reference/wire
#include <Adafruit_PWMServoDriver.h>//https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library

#define nbPCAServo 4
class Motor
{
public:
	Motor();
	
	void maj(void);
  void majsortie();
	int A = 0;
	int B = 0;
	int C = -128;

private:
	
	int MIN_IMP[nbPCAServo] = { 500,  500, 2500, 2500 };
	int MAX_IMP[nbPCAServo] = { 2500, 2500,  500,  500 };
	int somme[4] = { 0,0,0,0 };
	int Sortie_Pwm[4] = { (MAX_IMP[0] + MIN_IMP[0]) / 2,(MAX_IMP[1] + MIN_IMP[1]) / 2,(MAX_IMP[2] + MIN_IMP[2]) / 2,(MAX_IMP[3] + MIN_IMP[3]) / 2 };
	void init(void);
  Adafruit_PWMServoDriver pca;
};
#endif 

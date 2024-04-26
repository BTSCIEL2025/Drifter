#ifndef MOTOR_H
#define MOTOR_H
#include <Wire.h>//https://www.arduino.cc/en/reference/wire
#include <Adafruit_PWMServoDriver.h>//https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library


#define nbPCAServo 4


class Motor 
{
public:
	// Variable de PCA qui pointe sur l'adresse 0x40, passage obligatoire dans le main des définitions d'adresses I2C, sinon blocage lors du setup
	Motor(Adafruit_PWMServoDriver *monPca) {
		pca = monPca;
	}
	
	void begin() {
		pca->begin();
		pca->setPWMFreq(60); // Analog servos run at ~60 Hz updates
		init();
	}
	void maj(byte A, byte B, byte C) {
		//Afficher les valeurs de A, B et C dans le moniteur série
		Serial.println(A);
		Serial.println(B);
		Serial.println(C);
		somme[0] = A + B + C;   Sortie_Pwm[0] = map(somme[0], 0, 255, MIN_IMP[0], MAX_IMP[0]);
		somme[1] = A + B - C;   Sortie_Pwm[1] = map(somme[1], 0, 255, MIN_IMP[1], MAX_IMP[1]);
		somme[2] = A - B - C;   Sortie_Pwm[2] = map(somme[2], 0, 255, MIN_IMP[2], MAX_IMP[2]);
		somme[3] = A - B + C;   Sortie_Pwm[3] = map(somme[3], 0, 255, MIN_IMP[3], MAX_IMP[3]);
		/*Serial.println(Sortie_Pwm[0]);
		Serial.println(Sortie_Pwm[1]);
		Serial.println(Sortie_Pwm[2]);
		Serial.println(Sortie_Pwm[3]);*/
	}
	void majsortie() {  
		// Afficher les 4 Sortie_Pwm dans le moniteur série
		Serial.println(Sortie_Pwm[0]);
		Serial.println(Sortie_Pwm[1]);
		Serial.println(Sortie_Pwm[2]);
		Serial.println(Sortie_Pwm[3]);
		pca->writeMicroseconds(0,Sortie_Pwm[0]);
		pca->writeMicroseconds(1,Sortie_Pwm[1]);
		pca->writeMicroseconds(2,Sortie_Pwm[2]);
		pca->writeMicroseconds(3,Sortie_Pwm[3]); 
	}
private:
	
	int MIN_IMP[nbPCAServo] = { 500,  500, 2500, 2500 };
	int MAX_IMP[nbPCAServo] = { 2500, 2500,  500,  500 };
	int somme[4] = { 0,0,0,0 };
	int Sortie_Pwm[4] = { (MAX_IMP[0] + MIN_IMP[0]) / 2,(MAX_IMP[1] + MIN_IMP[1]) / 2,(MAX_IMP[2] + MIN_IMP[2]) / 2,(MAX_IMP[3] + MIN_IMP[3]) / 2 };
	void init() {
		maj(0,0,0); 
		majsortie();
		somme[0] = 0;   Sortie_Pwm[0] = 0;
		somme[1] = 0;   Sortie_Pwm[1] = 0;
		somme[2] = 0;   Sortie_Pwm[2] = 0;
		somme[3] = 0;   Sortie_Pwm[3] = 0;
		// majsortie();
	}
    Adafruit_PWMServoDriver *pca;
};
#endif 

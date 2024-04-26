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


	//-----------------------------------------------------------------------------------------------
	void maj( byte A, byte B, byte C) {      //    motor.maj(srx, sly, slx);
		//Afficher les valeurs de A, B et C dans le moniteur série

        //il faut inverser le Y left car pousser on a 0 et tirré on a 255:
        A = map(A, 0, 255, 255, 0 );

		Serial.print("  maj(): A= "); 		Serial.print(A);
		Serial.print(" B= "); 		Serial.print(B);
		Serial.print(" C= ");		Serial.print(C);
		Serial.print("   ");
// debut LS

        //map(somme[0], 0, 780, MIN_IMP[0], MAX_IMP[0]);
		
		// passage en int pour avoir le signe
		int intA = map(A, 0 ,255, -127, 127);
		int intB = map(B, 0 ,255, -127, 127);
		int intC = map(C, 0 ,255, -127, 127);
		
	Serial.print("  MAPP A= ");     Serial.print(intA);
		Serial.print(" B= "); 		Serial.print(intB);
		Serial.print(" C= ");		Serial.print(intC);
		Serial.print("   ");



		somme[0] = intA + intB + intC;   Sortie_Pwm[0] = map(somme[0], -390 ,390, MIN_IMP[0], MAX_IMP[0]);
		somme[1] = intA + intB - intC;   Sortie_Pwm[1] = map(somme[1], -390 ,390, MIN_IMP[1], MAX_IMP[1]);
		somme[2] = intA - intB + intC;   Sortie_Pwm[2] = map(somme[2], -390 ,390, MIN_IMP[2], MAX_IMP[2]);
		somme[3] = intA - intB - intC;   Sortie_Pwm[3] = map(somme[3], -390 ,390, MIN_IMP[3], MAX_IMP[3]);

// fin t LS
/*
		somme[0] = A + B + C;   Sortie_Pwm[0] = map(somme[0], 0, 780, MIN_IMP[0], MAX_IMP[0]);
		somme[1] = A + B - C;   Sortie_Pwm[1] = map(somme[1], 0, 780, MIN_IMP[1], MAX_IMP[1]);
		somme[2] = A - B + C;   Sortie_Pwm[2] = map(somme[2], 0, 780, MIN_IMP[2], MAX_IMP[2]);
		somme[3] = A - B - C;   Sortie_Pwm[3] = map(somme[3], 0, 780, MIN_IMP[3], MAX_IMP[3]);
*/		
		Serial.print(" S0= ");		Serial.print(Sortie_Pwm[0]);
		Serial.print(" S1= ");		Serial.print(Sortie_Pwm[1]);
		Serial.print(" S2= ");		Serial.print(Sortie_Pwm[2]);
		Serial.print(" S3= ");		Serial.print(Sortie_Pwm[3]);
	}

	//--------------------------------------------------------------------------------
	void majsortie() {  
		// Afficher les 4 Sortie_Pwm dans le moniteur série
		/*Serial.println(Sortie_Pwm[0]);
		Serial.println(Sortie_Pwm[1]);
		Serial.println(Sortie_Pwm[2]);
		Serial.println(Sortie_Pwm[3]);*/
		pca->writeMicroseconds(0,Sortie_Pwm[0]);
		pca->writeMicroseconds(1,Sortie_Pwm[1]);
		pca->writeMicroseconds(2,Sortie_Pwm[2]);
		pca->writeMicroseconds(3,Sortie_Pwm[3]); 
	}
private:
	
	int MIN_IMP[nbPCAServo] = { 500, 500,   2500, 2500 };
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

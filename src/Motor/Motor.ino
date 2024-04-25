#include "Motor.h"


/*Motor::Motor() 
{
	Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);  // pas de starp 
	pca.begin();
	pca.setPWMFreq(60); 	// Analog servos run at ~60 Hz updates
	init();
}
//Changement car Initialize Setup en boucle (MERCI CHAT GPT)
*/
Motor::Motor() : pca(0x40) {
    pca.begin();
    pca.setPWMFreq(60); // Analog servos run at ~60 Hz updates
    init();
}
void Motor::init(void) {
	somme[0] = 0;   Sortie_Pwm[0] = 0;
	somme[1] = 0;   Sortie_Pwm[1] = 0;
	somme[2] = 0;   Sortie_Pwm[2] = 0;
	somme[3] = 0;   Sortie_Pwm[3] = 0;
	
	// majsortie();
}
void Motor::maj(char A, char B, char C) {
	somme[0] = A + B + C;   Sortie_Pwm[0] = map(somme[0], 0, 255, MIN_IMP[0], MAX_IMP[0]);
	somme[1] = A + B - C;   Sortie_Pwm[1] = map(somme[1], 0, 255, MIN_IMP[1], MAX_IMP[1]);
	somme[2] = A - B - C;   Sortie_Pwm[2] = map(somme[2], 0, 255, MIN_IMP[2], MAX_IMP[2]);
	somme[3] = A - B + C;   Sortie_Pwm[3] = map(somme[3], 0, 255, MIN_IMP[3], MAX_IMP[3]);
	Serial.println(Sortie_Pwm[0]);
	Serial.println(Sortie_Pwm[1]);
	Serial.println(Sortie_Pwm[2]);
	Serial.println(Sortie_Pwm[3]);
}
void Motor::majsortie()
{  
	  pca.writeMicroseconds(0,Sortie_Pwm[0]);
    pca.writeMicroseconds(1,Sortie_Pwm[1]);
    pca.writeMicroseconds(2,Sortie_Pwm[2]);
    pca.writeMicroseconds(3,Sortie_Pwm[3]); 
}



//Libraries
//               Drifter__PCA9685__SERVO_Deplacement_Carre_OK.ino


#include <Wire.h>//https://www.arduino.cc/en/reference/wire
#include <Adafruit_PWMServoDriver.h>//https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
//Constants
#define nbPCAServo 4
//Parameters
int MIN_IMP [nbPCAServo] ={ 500,  500, 2500, 2500}; //, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};
int MAX_IMP [nbPCAServo] ={2500, 2500,  500,  500}; //, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500};
//int MIN_ANG [nbPCAServo] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//int MAX_ANG [nbPCAServo] ={180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180};
//Objects
Adafruit_PWMServoDriver pca= Adafruit_PWMServoDriver(0x40);  // pas de starp 
void setup(){
//Init Serial USB
Serial.begin(115200);
Serial.println(F("Initialize System"));
pca.begin();
pca.setPWMFreq(60); 	// Analog servos run at ~60 Hz updates


/*  // clignoter
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,HIGH);
delay(500);
digitalWrite(LED_BUILTIN,LOW);
delay(500);
digitalWrite(LED_BUILTIN,HIGH);
delay(500);
digitalWrite(LED_BUILTIN,LOW);
delay(500);
digitalWrite(LED_BUILTIN,HIGH);
delay(500);
digitalWrite(LED_BUILTIN,LOW);
delay(500);
*/



//reset des sorties:
    for (int i=0; i<nbPCAServo; i++)  //  nbPCAServo; i++) 
	    pca.setPin(i,0,true); // port du PCA, puissance, ???? desactive 


	//pcaScenario();
  
  //Avant(); 
  Avant2();
  delay(1000);  
  stop();
  delay(1000);
  
  //Avant(); 
  Droite2();
  delay(1000);  
  stop();
  delay(1000);

  Arriere2();
  delay(1000);
  stop();
  delay(1000);
  
  Gauche2();
  delay(1000);
  stop();
  delay(1000);
 
  }
//===========================================================================
void loop(){
 
}
//**************************************************************************
//----------------------------------------------------------------------------
void Ar()
{   
   	Serial.print("Ar:");
    //vers Avant:
	   
    pca.writeMicroseconds(0,MIN_IMP[0]); //delay(10);
    pca.writeMicroseconds(1,MIN_IMP[1]); //delay(10);
    pca.writeMicroseconds(2,MIN_IMP[2]); //delay(10);
    pca.writeMicroseconds(3,MIN_IMP[3]); //delay(10);
     
 }//----------------------------------------------------------------------------
void stop()
{   
   	Serial.print("stop:");
    //vers Avant:
	  for (int i=0; i<4; i++)  //  nbPCAServo; i++) 
    {
      pca.writeMicroseconds(i,(MAX_IMP[i]+MIN_IMP[i])/2);

    }
 }
//**************************************************************************
void AvantTous()
{   
   	Serial.print("AvantTous():");
    pca.writeMicroseconds(0,MAX_IMP[0]);
    pca.writeMicroseconds(1,MAX_IMP[1]);
    pca.writeMicroseconds(2,MAX_IMP[2]);
    pca.writeMicroseconds(3,MAX_IMP[3]);
 }
 
//----------------------------------------------------------------------------
void ArriereTous(void)
{   
   	Serial.println("RArriereTous :");
    for (int i=0; i<4; i++)  //  nbPCAServo; i++) 
    {
   	  Serial.print("  Servo: ");
 	    Serial.print(i);

      pca.writeMicroseconds(i,MIN_IMP[i]);
    }
    delay(2000);
    for (int i=0; i<4; i++)  //  nbPCAServo; i++) 
	    pca.setPin(i,0,true); // port du PCA, puissance, ???? desactive 
}
void Avant2()
{  
   	Serial.print("Avant2:");
    //vers Avant:
	  pca.writeMicroseconds(0,MAX_IMP[0]);
    pca.writeMicroseconds(1,MAX_IMP[1]);
    pca.writeMicroseconds(2,MAX_IMP[2]);
    pca.writeMicroseconds(3,MAX_IMP[3]); 
}
void Droite2()
{  
   	Serial.print("Avant2:");
    //vers Avant:
	  pca.writeMicroseconds(0,MAX_IMP[0]);
    pca.writeMicroseconds(1,MIN_IMP[1]);
    pca.writeMicroseconds(2,MAX_IMP[2]);
    pca.writeMicroseconds(3,MIN_IMP[3]); 
}
void Gauche2()
{  
   	Serial.print("Avant2:");
    //vers Avant:
	  pca.writeMicroseconds(0,MIN_IMP[0]);
    pca.writeMicroseconds(1,MAX_IMP[1]);
    pca.writeMicroseconds(2,MIN_IMP[2]);
    pca.writeMicroseconds(3,MAX_IMP[3]); 
}

void Arriere2()
{  
   	Serial.print("Arriere2:");
    //vers Avant:
	  pca.writeMicroseconds(0,MIN_IMP[0]);
    pca.writeMicroseconds(1,MIN_IMP[1]);
    pca.writeMicroseconds(2,MIN_IMP[2]);
    pca.writeMicroseconds(3,MIN_IMP[3]); 
}
//----------------------------------------------------------------------------
void Avant()
{   
   	Serial.print("Avant:");
    //vers Avant:
	  pca.setPin(0,0,true); // deactivate pin i
    pca.writeMicroseconds(0,MAX_IMP[0]);
    delay(1000);
	  pca.setPin(0,0,true); // deactivate pin i
    
    pca.writeMicroseconds(1,MAX_IMP[1]);
    delay(1000);
	  pca.setPin(1,0,true); // deactivate pin i
    
    pca.writeMicroseconds(2,MAX_IMP[2]);
    delay(1000);
	  pca.setPin(2,0,true); // deactivate pin i
    
    pca.writeMicroseconds(3,MAX_IMP[3]);
    delay(1000);
    pca.setPin(3,0,true); // deactivate pin i
 }
//**************************************************************************

//----------------------------------------------------------------------------
void pcaScenario(){/* function pcaScenario */
  ////Scenario to test servomotors controlled by PCA9685 I2C Module
  for (int i=0; i<4; i++)  //  nbPCAServo; i++) 
  {
   	Serial.println("pcaScenario:");
 	  Serial.println(i);

	  //int middleVal=((MAX_IMP[i]+MIN_IMP[i])/2)/20000*4096; // conversion µs to pwmval
	  //pca.setPWM(i,0,middleVal);

    //vers Avant:
	  for(int pos=(MAX_IMP[i]+MIN_IMP[i])/2;pos<MAX_IMP[i];pos+=10){
	  	pca.writeMicroseconds(i,pos);
      delay(10);
 	  }
	  for(int pos=MAX_IMP[i];pos>MIN_IMP[i];pos-=10){
		  pca.writeMicroseconds(i,pos);
      //LS delay(10);
	  }
	  for(int pos=MIN_IMP[i];pos<(MAX_IMP[i]+MIN_IMP[i])/2;pos+=10){
		  pca.writeMicroseconds(i,pos);
      // LS  delay(10);
	  }
	  pca.setPin(i,0,true); // deactivate pin i
	}
}
//=====================================================================
/*
int jointToImp(double x,int i){// function jointToImp 
////Convert joint angle into pwm command value
 				
 					int imp=(x - MIN_ANG[i]) * (MAX_IMP[i]-MIN_IMP[i]) / (MAX_ANG[i]-MIN_ANG[i]) + MIN_IMP[i];
 					imp=max(imp,MIN_IMP[i]);
 					imp=min(imp,MAX_IMP[i]);
 					
 return imp;
}
*/
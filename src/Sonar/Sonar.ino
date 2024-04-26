/*Semaine projet Drifter
  Sonar
  Mougin Léane
  24/04/24
  version 1
*/

#include "Sonar.h"




//Constructeurs par d�faults---------------------------------------------------------------------------------
Sonar::Sonar() {
	etat = 0;
  orientation = 270;
  dateDebut = millis();
  nbMesure = 10;
  intervalle = 200;
  avance = 0;
  feu = -1;
  sens = 1;
  nbTours = 0;
}

//Constructeur comprennant les valeurs
/*
* int angle : L'angle maximal que le servo moteur peut atteindre
* int nbMes : Le nombre de mesures que l'on veut effectuer sur une rotation du moteur
* int inter : L'intervalle en temps que l'on souhaite attendre entre chaque mesures
*/
Sonar::Sonar(int angle, int nbMes, int inter,Adafruit_PWMServoDriver *pwm) {
  etat = 0;
  dateDebut = millis();
  orientation = angle;
  nbMesure = nbMes;
  intervalle = inter;
  avance = 0;
  feu = -1;
  sens = 1;
  nbTours = 0;
  pwm = pwm;
}

//Getteurs--------------------------------------------------------------------------------------------------

int Sonar::getOrientation() const
{
	return orientation;
}

bool Sonar::getEtat() const
{
	return etat;
}

int Sonar::getNbMesure() const{
  return nbMesure;
}

int Sonar::getLecture(int i) const
{
	return lecture[i];
}

long Sonar::getDateDebut() const
{
	return dateDebut;
}

int Sonar::getIntervalle() const
{
	return intervalle;
}

int Sonar::getAvance() const
{
	return avance;
}

int Sonar::getFeu() const
{
	return feu;
}

int Sonar::getSens() const
{
	return sens;
}

int Sonar::getNbTour() const
{
  return nbTours;
}

//Setteurs-----------------------------------------------------------------------------------------------

void Sonar::setOrientation(int orientation)
{
  this->orientation = orientation;
}

void Sonar::setEtat(bool etat)
{ 
   this->etat = etat;
}

void Sonar::setNbMesure(int nbM){
  this->nbMesure = nbM;
}

void Sonar::setLecture(int rang, int val)
{
  this->lecture[rang] = val;
}

void Sonar::setDateDebut(long date)
{
  this->dateDebut = date;
}

void Sonar::setIntervalle(int intervalle)
{
  this->intervalle = intervalle;
}

void Sonar::setAvance(int avance)
{
  this->avance = avance;
}

void Sonar::setFeu(int feu)
{
  this->feu = feu;
}

void Sonar::setSens(int sens)
{ 
   this->sens = sens;
}

void Sonar::setNbTour(int tour)
{
  this->nbTours = tour;
}

//Autres fonctions----------------------------------------------------------------------------------------

int Sonar::pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, getOrientation(), MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void Sonar::miseOn(){
  setEtat(1);
  pwm->begin(); 
  pwm->setPWMFreq(FREQUENCY);
  pwm->setPWM(CANALSERVO, 0, pulseWidth(0));                      //on met le servo à l'angle 0     
  setDateDebut(millis());                                         // on indique le temps du lancement
}  

void Sonar::miseOff(){
  setEtat(0);
  pwm->setPWM(CANALSERVO, 0, pulseWidth(135));   // on le remet a son angle d'origine   
  setSens(1);
}   

void Sonar::maj(){
  if(this->etat){
    //Permet de faire les mesures dans les deux sens et d'incrementer le nombre de tour
    if(getAvance() + 1 == getNbMesure() && getSens()==1){                     //+1 car on part de 0 et pas de 1
      setSens(-1);
      setNbTour(getNbTour() + 1);         
    }else if(getAvance()  == 0 && getSens()==-1){
      setSens(1);
      setNbTour(getNbTour() + 1);
    }
    if(getSens()==1){
      if(millis()>getDateDebut() + getAvance() * getIntervalle() + getNbTour() * getNbMesure() * getIntervalle()){                              //tps au lancement + tps pris pour le tour courant + tps pris par les tours passé
        pwm->setPWM(CANALSERVO, 0, pulseWidth(getAvance() * (getOrientation() / getNbMesure())));                                               //pulseWidth donne les °, combien-ième mesure * nb °dans une intervalle       
        setLecture(getAvance(),lireLum());
        setAvance(getAvance() + getSens());                                                                                                     //on augmente de 1 si sens horaire et on diminue si anti-horaire
      }
    }else{                                                                                                                                      //sens anti-horaire
      if(millis()>getDateDebut() + (getNbMesure()-getAvance()) * getIntervalle() + getNbTour() * getNbMesure() * getIntervalle()){              //tps au lancement + tps pris pour le tour courant + tps pris par les tours passé
        pwm->setPWM(CANALSERVO, 0, pulseWidth(getOrientation()-((getNbMesure()-getAvance()) * (getOrientation() / getNbMesure()))));            //pulseWidth donne les °, combien-ième mesure * nb °dans une intervalle       
        setLecture(getAvance(),lireLum());
        setAvance(getAvance() + getSens());                                                                                                     //on augmente de 1 si sens horaire et on diminue si anti-horaire
      }
    }
  }
} 

int Sonar::lireLum(){
  return analogRead(PIN_CAPT_LUM);
}          

int Sonar::moyLum(){
  int moy = 0;
  if(getNbTour()==0){                                                   //si le tableau n'a pas encore été complettement remplit
    for(int i = 0; i<getAvance() + 1;i++){
      moy += getLecture(i);
    }
    return moy/getAvance();
  }else{                                                                //sinon on fait la moyenne de tout le tableau
    for(int i = 0; i<getNbMesure() ;i++){
      moy += getLecture(i);
    }
  }
  return moy/getNbMesure();
} 

int Sonar::maxLum(){
  int max = getLecture(0);
  if(getNbTour()==0){                                                   //si le tableau n'a pas encore étécomplettement remplit
    for(int i = 1; i<getAvance() + 1;i++){
      if(getLecture(i)>max){
        max = getLecture(i);
      }
    }
  }else{
    for(int i = 0; i<getNbMesure() ;i++){
      if(getLecture(i)>max){
        max = getLecture(i);
      }
    }
  }
  return max;
} 

int Sonar::rangLumMax(){
  for(int i = 0; i<getNbMesure() ;i++){
    if(getLecture(i) == maxLum()){
      return i;
    }
  }
  return -1;  //si on arrive là il y a eu un problème
}


int Sonar::oFeu(){
  if(maxLum()-moyLum() > DELTAOFEU){
    setFeu(rangLumMax() * getOrientation() / getNbMesure());        //getOrientation / getNbMesure correspond à l'intervalle en degres entre deux mesures
  }
  return getFeu();
}
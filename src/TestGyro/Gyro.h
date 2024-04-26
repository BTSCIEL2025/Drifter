#ifndef GYRO_H
#define GYRO_H
class Gyro
{
	public :
		gyro();
		gyro(int dOn, int dOff);
		void marche();
		void arret();
		bool getEtat();
		int getdOn();
    int getdOff();
    void setdOn(int);
    void setdOff(int);

	private :
		int dOn;
		int dOff;
		bool etat; // 1 = On --- 0 = Off
};
#endif 

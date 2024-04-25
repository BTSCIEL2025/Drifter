#ifndef POMPE_H
#define POMPE_H

class Pompe
{
public :
	Pompe();                
	void maj(void);         //MAJ de l'objet
	void miseOn(void);      // Mise en route
	void miseOff(void);     // Mise en arret

	bool getEnFct();        // true = en fonctionnement ----- false = arretée

private :
	long duree;             // temps d'arrosage
	long dateDebut;         // date de debut d'arrosage
	bool enFct;							// 1 = On --- 0 = Off
	
};
#endif 
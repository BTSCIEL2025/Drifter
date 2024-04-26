#ifndef AUTOMATE_H
#define AUTOMATE_H

#define nbr_etat 20
#define nbr_transition 5 

class Automate {
  private:
    int autom[nbr_transition][nbr_etat] = {
      {1,2,3,3,5,5,7,6,9,8,11,12,13,14,14,15,16,17,18,19},
      {0,1,1,2,1,4,7,6,9,8,3,10,11,12,13,15,16,17,18,19},
      {0,1,2,3,4,5,7,6,9,8,10,11,12,13,14,15,16,17,18,19},
      {0,1,2,3,4,5,7,6,9,8,10,11,12,13,14,15,16,17,18,19},
      {0,4,2,10,6,8,7,4,8,5,15,16,17,18,19,10,11,12,13,14},
    };
  public:
    int getAutomValue(int i, int j) {
        return autom[i][j];
    }
};
#endif
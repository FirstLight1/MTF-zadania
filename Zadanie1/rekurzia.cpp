#include "rekurzia.h"

void obrat_Re(int pole[], int lavy, int pravy){
    if(lavy > pravy){
        return;
    }

    int x = pole[pravy];
    pole[pravy] = pole[lavy];
    pole[lavy] = x;
    
    obrat_Re(pole, lavy + 1, pravy - 1);

}
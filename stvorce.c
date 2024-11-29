#include <stdio.h>

typedef struct{
    double y;
    double x;
}stredBod_t;

typedef struct{
    stredBod_t S;
    double dlzka;
    double dolnaStrana;
    double hornaStrana;
    double pravaStrana;
    double lavaStrana;
}stvorec_t;

typedef struct{
    double xSur;
    double ySur;
}priescnik_t;

void hranice(stvorec_t stvorce[], int pocet);
priescnik_t priesecniky(stvorec_t stvorce[], int pocet);
double min(double a, double b);
double max(double a, double b);

int main(void){
    stvorec_t stvorce[10];
    int pocetStvorcov;
    priescnik_t vysledok;

    scanf("%d", &pocetStvorcov);

    for(int i = 0; i < pocetStvorcov; i++){
        scanf("%lf %lf %lf", &stvorce[i].S.x, &stvorce[i].S.y, &stvorce[i].dlzka);
    }

    hranice(stvorce, pocetStvorcov);

    vysledok = priesecniky(stvorce, pocetStvorcov);

    if (vysledok.xSur > 0 && vysledok.ySur > 0){
        printf("%.2lf %.2lf", vysledok.xSur, vysledok.ySur);
    } else {
        printf("nie");
    }
    return 0;
}


void hranice(stvorec_t stvorce[], int pocet){
    for(int i = 0; i < pocet; i++){
        stvorce[i].dolnaStrana = stvorce[i].S.y - (stvorce[i].dlzka / 2.0);
        stvorce[i].hornaStrana = stvorce[i].S.y + (stvorce[i].dlzka / 2.0);
        stvorce[i].pravaStrana = stvorce[i].S.x + (stvorce[i].dlzka / 2.0);
        stvorce[i].lavaStrana = stvorce[i].S.x - (stvorce[i].dlzka / 2.0);

    }
}

priescnik_t priesecniky(stvorec_t stvorce[], int pocet){
    double xMax =stvorce[0].pravaStrana , xMin = stvorce[0].lavaStrana;
    double yMax = stvorce[0].hornaStrana, yMin = stvorce[0].dolnaStrana;
    for(int i = 1; i < pocet; i++){
        xMax = min(xMax, stvorce[i].pravaStrana);
        xMin = max(xMin, stvorce[i].lavaStrana);
        yMax = min(yMax, stvorce[i].hornaStrana);
        yMin = max(yMin, stvorce[i].dolnaStrana);
    }

    priescnik_t vysledok;

    if (xMin <= xMax && yMin <= yMax){
        vysledok.xSur = xMin;
        vysledok.ySur = yMin;
    } else {
        vysledok.xSur = -1;
        vysledok.ySur = -1;
    }

    return vysledok;
}

double min(double a, double b){
    if(a <= b){
        return a;
    } else {
        return b;
    }
}

double max(double a, double b){
    if (a >= b){
        return a;
    } else {
        return b;
    }
}

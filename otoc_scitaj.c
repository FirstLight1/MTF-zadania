#include <stdio.h>

int otocCislo(int cislo);

int main(){
    int cislo, opacneCislo;

    scanf("%d", &cislo);

    opacneCislo = otocCislo(cislo);
    printf("%d", opacneCislo);
    return 0;
}

int otocCislo(int cislo){
    int x = 0;
    while(cislo != 0){
        int cislica = cislo % 10;
        x = x * 10 + cislica;
        cislo = cislo / 10;
    }
    return x;
}
#include <stdio.h>
#include <stdbool.h>

long long int otocCislo(long long int cislo);

int main(){
    long long int cislo, opacneCislo, palindrom;
    int medzisucet = 0, i = 0;

    scanf("%lld", &cislo);

    do {
    opacneCislo = otocCislo(cislo);
    if (cislo == opacneCislo){
        break;
    }
    cislo += opacneCislo;
    palindrom = otocCislo(cislo);
    i++;
    } while (cislo != palindrom);

    printf("%d %lld", i, cislo);
    return 0;
}

long long int otocCislo(long long int cislo){
    long long int x = 0;
    while(cislo != 0){
        long long int cislica = cislo % 10;
        x = x * 10 + cislica;
        cislo = cislo / 10;
    }
    return x;
}

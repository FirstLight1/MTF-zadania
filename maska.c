#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pocetPodsekvencii(char vstupN[], char maska[]);

int main(){
    char vstupN[300];
    char maska[4];
    int x;
    

    fgets(vstupN, sizeof(vstupN), stdin);
    vstupN[strcspn(vstupN, "\n")] = '\0';
    fgets(maska, sizeof(maska), stdin);
    maska[strcspn(maska, "\n")] = '\0';

    x = pocetPodsekvencii(vstupN, maska);

    printf("%d ", x);


}


int pocetPodsekvencii(char vstupN[], char maska[]){
    int pocet = 0;
    int a = maska[0]; int b = maska[2];
        for (int i = 0; i < strlen(vstupN); i++){
            if(vstupN[i] == a){
                for (int j = i; j < strlen(vstupN); ++j){
                    if (vstupN[j+1] == b){
                        pocet++;
                    }
                }
            }
        }        
    return pocet;
}
#include <stdio.h>

int vanEck(int start, int iteracia);

int main(){
    int startCislo, iteracia, x;

    scanf("%d %d", &startCislo, &iteracia);

    x = vanEck(startCislo, iteracia);

    printf("%d", x);

    return 0;
}

int vanEck(int start, int iteracia){
    int sekvencia[100];
    sekvencia[0] = start;

    for(int i = 1; i <= iteracia ; i++){
        int poslednaHodnota = sekvencia[i - 1];
        int videne = -1;

        for(int j = i - 2; j >= 0; j--){
            if(sekvencia[j] == poslednaHodnota){
                videne = j + 1;
                break;
            }
        }
        
        if(videne == -1){
            sekvencia[i] = 0;
        } else {
            sekvencia[i] = (i - 1) - (videne - 1);
        }
        
    }
    return sekvencia[iteracia];
}
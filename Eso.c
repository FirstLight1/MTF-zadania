#include <stdio.h>

#define MAX 4

void nacitajData(int data[][MAX]);
int overRiadok(int data[][MAX]);
int overStlpec(int data[][MAX]);
int neparne(int parnost[]);
int parne(int parnost[]);

int main(){
    int data[MAX][MAX];
    int x, y;

    nacitajData(data);
    x = overRiadok(data);
    y = overStlpec(data);
    if (data[x][y] == 1){
        data[x][y] = 0;
    } else {
        data[x][y] = 1;
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("%d", data[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

void nacitajData(int data[][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            scanf("%d", &data[i][j]);
        }
    }
}


int overRiadok(int data[][MAX]){
    int parnost[4];
    int p = 0, n = 0, x;

    for(int i = 0; i < MAX; i++){
        int x = 0;
        for(int j = 0; j < MAX; j++){
            x += data[i][j]; 
        }
        if (x % 2 == 0){
            parnost[i] = '2';
        } else {
            parnost[i] = '1';
        }
    }
    for (int i = 0; i < MAX; i++){
        if (parnost[i] == '2'){
            p++;
        } else {
            n++;
        }
    }

    if (p > n){
       x = parne(parnost);
    } else {
        x = neparne(parnost);
    }


    return x;
}

int overStlpec(int data[][MAX]){
    int parnost[4];
    int p = 0, n = 0, y;

    for(int i = 0; i < MAX; i++){
        int x = 0;
        for(int j = 0; j < MAX; j++){
            x += data[j][i]; 
        }
        if (x % 2 == 0){
            parnost[i] = '2';
        } else {
            parnost[i] = '1';
        }
    }
    for (int i = 0; i < MAX; i++){
        if (parnost[i] == '2'){
            p++;
        } else {
            n++;
        }
    }

    if (p > n){
       y = parne(parnost);
    } else {
        y = neparne(parnost);
    }

    return y;
}

int neparne(int parnost[]){
    for (int i = 0; i < MAX; i++){
        if (parnost[i] == '2'){
            return i;
        }
    }   
}

int parne(int parnost[]){
    for (int i = 0; i < MAX; i++){
        if (parnost[i] == '1'){
            return i;
        }
    }
}
#include <stdio.h>

void nacitajPole(char Pole[][101], int m, int n);
void miny(char Pole[][101], int m, int n);

int main(){
    int m,n;
    scanf("%d %d", &m, &n);

    char Pole[101][101];

    nacitajPole(Pole, m, n);

    miny(Pole, m, n);

    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            printf("%c", Pole[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void nacitajPole(char Pole[][101], int m, int n){
    
    for (int i = 0; i <= n + 1 ; i++){
        Pole[0][i] = 'X';
        Pole[m + 1][i] = 'X';
    }

    
    for (int i = 0; i < m + 2; i++){
        Pole[i][0] = 'X';
        Pole[i][n + 1] = 'X';
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            scanf(" %c", &Pole[i][j]);
            if (Pole[i][j] == '.'){
                Pole[i][j] = '0';
            }
        }
    }


}

void miny(char Pole[][101], int m, int n){
    
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if(Pole[i][j] == '*'){
                for(int x = -1; x <=1; x++){
                    for(int y = -1; y<=1; y++){
                        if(Pole[i + x][j + y] != '*'){
                            Pole[i + x][j + y]++;
                        }
                    }
                }
            }     
        }
    
    }

}

#include <stdio.h>
#define MAX 3

typedef struct{
    int body;
    int cierna;
    int biela;
    int cervena;
}body_t;

typedef struct{
    double x;
    double y;
}suradniceZasahu_t;

void trefy(suradniceZasahu_t hits[MAX]);
body_t spocitajBody(suradniceZasahu_t hits[]);
void extraBody(body_t x);

int main(){
    body_t x;
    suradniceZasahu_t hits[MAX];

    trefy(hits);

    x = spocitajBody(hits);
    extraBody(x);
    
    printf("%d", x.body);
    return 0;
}

void trefy(suradniceZasahu_t hits[]){
    for(int i = 0; i < MAX; i++){
        scanf("%lf %lf", &hits[i].x, &hits[i].y);
    }
}

body_t spocitajBody(suradniceZasahu_t hits[MAX]){
    body_t x = {0, 0, 0, 0};
    for(int i = 0; i < MAX; i++){
        if(-5.0 < hits[i].x < 5.0  && -5.0 < hits[i].y < 5.0){
            x.body += 100;
            x.cierna++;
        } else if (-35.0 < hits[i].x < 35.0 && -35.0 < hits[i].y < 35.0){
            x.body += 50;
            x.biela++;
        } else {
            x.body += 20;
            x.cervena++;
        }
    }
    return x;
}

void extraBody(body_t x){
    if (x.cierna == 3){
        x.body += 200;
    }
    if (x.biela == 3){
        x.body += 10; 
    }
    if (x.cervena == 3){
        x.body += 50;
    }
    if (x.cierna == 1 && x.biela == 1 && x.cervena == 1){
        x.body += 60;
    }
}
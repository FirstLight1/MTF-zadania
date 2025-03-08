#include <iostream>
#include "iteracia.h"
#include "rekurzia.h"

using namespace std;


int main(){
    int pocetPrvkov, lavy = 0;
    int *pole1 = NULL;
    int *pole2 = NULL;

    cin>>pocetPrvkov;

    int pravy = pocetPrvkov - 1;

    pole1 = new int[pocetPrvkov];
    pole2 = new int[pocetPrvkov];

    if (pole1 != NULL && pole2 != NULL && pocetPrvkov > 0){
        for(int i = 0; i < pocetPrvkov; i++){
            cin>>pole1[i];
            pole2[i] = pole1[i];
        }
    }

    obrat_It(pole1, pocetPrvkov);
    obrat_Re(pole2, lavy, pravy);

    for(int i = 0; i < pocetPrvkov; i++){
        cout<<pole1[i];
        
    }

    cout<<endl;

    for(int i = 0; i < pocetPrvkov; i++){   
        cout<<pole2[i];
    }
    delete []pole1;
    delete []pole2;
    return 0;
}

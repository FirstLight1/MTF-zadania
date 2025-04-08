#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "shellSort.h"
#include "mergeSort.h"

#define nLogN 1000000


using namespace std;

typedef void(*sortFunc)(unsigned int*, int, int);

void randomNumbers(unsigned int *arr, int dlzka);
void vytvorArr(unsigned int *arr1, unsigned int *arr2, int dlzka);
bool zoradene(unsigned int *arr, int dlzka);
double zmerajCas(sortFunc sort, unsigned int* arr, int x, int dlzka);

int main(){
    srand(time(NULL));
    
    for (int j = 1; j <= 10; j++){
        cout<<"Pocet prvkov = "<<nLogN *j<<endl;
        int dlzka = nLogN * j;
        unsigned int *arr1 = new unsigned int[dlzka];
        unsigned int *arr2 = new unsigned int[dlzka];
        double tShell = 0.0, tMerge = 0.0;
        int stred = (dlzka) / 2;
        

        for (int i = 0; i < 3; i++)
        {   
            double cas;

            vytvorArr(arr1, arr2, dlzka);
            cas = zmerajCas(*shellSort, arr1, stred, dlzka);
            tShell += cas;
            cout<<"i:"<<i + 1<<" shell cas:"<<cas<<endl;

            cas += zmerajCas(*mergeSort, arr2, 0 ,dlzka);
            tMerge += cas;
            cout<<"merge cas:"<<cas<<endl;
        }

    cout<<"Priemerny čas shell sortu:"<<tShell / 3<<endl;
    cout<<"Priemerny čas merge sortu:"<<tMerge / 3<<endl;
    
    delete[] arr1;
    delete[] arr2;
    }
    return 0;
}

void randomNumbers(unsigned int *arr, int dlzka){
    for (int i = 0; i < dlzka; i++){
    arr[i] = rand();
    }
}

void vytvorArr(unsigned int *arr1, unsigned int *arr2, int dlzka){
    randomNumbers(arr1, dlzka);
    for (int i = 0; i < dlzka; i++)
    {
        arr2[i] = arr1[i];
    }
}

bool zoradene(unsigned int *arr, int dlzka){
    for (int i = 0; i < dlzka - 1; i++){
        if (arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

double zmerajCas(sortFunc sort, unsigned int* arr, int x, int dlzka){
    clock_t start = clock();
    double t;

    sort(arr, x, dlzka);
    if(zoradene(arr, dlzka)){
        start = clock() - start;
    }
    t = ((double) start) / CLOCKS_PER_SEC;

    return t;
}



#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "shellSort.h"
#include "mergeSort.h"

#define nLogN 10000000
#define n2 50000

using namespace std;

typedef void(*sortFunc)(unsigned int*, int, int);

void randomNumbers(unsigned int *arr);
void vytvorArr(unsigned int *arr1, unsigned int *arr2, int dlzka);
bool zoradene(unsigned int *arr, int dlzka);
double zmerajCas(sortFunc sort, unsigned int* arr, int x, int dlzka);

int main(){
    srand(time(NULL));
    unsigned int *arr1 = new unsigned int[n2];
    unsigned int *arr2 = new unsigned int[n2];
    
    double tShell = 0.0, tMerge = 0.0;
    
    int stred = n2 / 2;

    for (int i = 0; i < 3; i++)
    {   
        double cas;

        vytvorArr(arr1, arr2, n2);
        cas = zmerajCas(*shellSort, arr1, stred, n2);
        tShell += cas;
        cout<<"i:"<<i + 1<<" shell cas:"<<cas<<endl;

        cas += zmerajCas(*mergeSort, arr2, 0 ,n2);
        tMerge += cas;
        cout<<"merge cas:"<<cas<<endl;
    }

    cout<<"Priemerny čas shell sortu:"<<tShell / 3<<endl;
    cout<<"Priemerny čas merge sortu:"<<tMerge / 3<<endl;
    
    delete[] arr1;
    delete[] arr2;
    return 0;
}

void randomNumbers(unsigned int *arr){
    for (int i = 0; i < n2; i++){
    arr[i] = rand();
    }
}

void vytvorArr(unsigned int *arr1, unsigned int *arr2, int dlzka){
    randomNumbers(arr1);
    for (int i = 0; i < n2; i++)
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
    if(zoradene(arr, n2)){
        start = clock() - start;
    }
    t = ((double) start) / CLOCKS_PER_SEC;

    return t;
}



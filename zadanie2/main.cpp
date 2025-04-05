#include <iostream>
#include <time.h>
#include <stdlib.h>
//#include "shellSort.h"
#include "mergeSort.h"

#define nLogN 10000000
#define n2 50000

using namespace std;

void randomNumbers(unsigned int *arr);

int main(){
    srand(time(NULL));
    //unsigned int *arr = new unsigned int[20];
    
    int dlzka = 10;
    unsigned int arr[] = {3, 5, 7, 1, 6, 2, 9, 8, 4, 0};
    //randomNumbers(arr);
    //int stred = 10 / 2;
    //shellSort(arr, 10, stred);
    mergeSort(arr, 0, dlzka);
    
    
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<endl;
    }
    

    //delete arr;
    return 0;
    
}


void randomNumbers(unsigned int *arr){
    for (int i = 0; i < 9; i++){
    arr[i] = rand();
}

}



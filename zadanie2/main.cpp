#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "shellSort.h"
//#include "mergeSort.h"

#define nLogN 10000000
#define n2 50000

using namespace std;

void randomNumbers(unsigned int *arr);

void shellSortwiki(unsigned int * array, int dlzka) {
    int gap = dlzka / 2;
    while (gap > 0) { //dokud mame co porovnavat
        for (int i = 0; i < dlzka - gap; i++) { //upraveny insertion sort
            int j = i + gap;
            int tmp = array[j];
            while (j >= gap && tmp < array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
        }
        if (gap == 2) { //zmena velikosti mezery
            gap = 1;
        } else {
            gap /= 2.2;
        }
    }
}


int main(){
    srand(time(NULL));
    //unsigned int *arr = new unsigned int[20];
    
    
    unsigned int arr[] = {3, 5, 7, 1, 6, 2, 9, 8, 4, 0};
    //randomNumbers(arr);
    int stred = 5 / 2;
    shellSort(arr, 10, stred);
    //shellSortwiki(arr, 10);

    
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



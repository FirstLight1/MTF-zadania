#include "shellSort.h"

void shellSort(unsigned int *arr, int dlzka, int gap){
    
    if (gap < 1){
        return;
    }

    for(int i = 0; i < dlzka - gap; i++){
        int j = i + gap;
        int tmp = arr[j];

        while (j >= gap && tmp < arr[j - gap])
        {
            arr[j] = arr[j - gap];
            j -= gap;
        }

        arr[j] = tmp;
    }

    shellSort(arr, dlzka, gap / 2);

}


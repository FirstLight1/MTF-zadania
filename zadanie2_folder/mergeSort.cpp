#include "mergeSort.h"

using namespace std;

void merge(unsigned int *arr, int zaciatok,int stred, int koniec);

void mergeSort(unsigned int *arr, int zaciatok, int koniec){
    
    if(zaciatok >= koniec) return;
    
    int stred = (zaciatok + koniec)/ 2;
    
    mergeSort(arr, zaciatok, stred);
    mergeSort(arr, stred + 1, koniec);
    merge(arr, zaciatok, stred, koniec);

}

void merge(unsigned int *arr, int zaciatok,int stred, int koniec){
    
    int velkost = koniec - zaciatok + 1;
    unsigned int *temp = new unsigned int[velkost]; 


    int i = zaciatok;
    int j = stred + 1;
    int k = 0;

    while (i <= stred && j <= koniec)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }


    while (i <= stred){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= koniec){
        temp[k] = arr[j];
        j++;
        k++;
    }   


    for (int  i = 0; i < velkost; i++)
    {
        arr[zaciatok + i ] = temp[i];
    }

    delete[] temp;
    
}
/**
 * @file iteracia.cpp
 * @author Lukáš Kamen
 * @date 10.3.2025
 */

#include "iteracia.h"
#include <iostream>

void obrat_It(int Pole[], int pocetPrvkov){

    for(int i = 0; i < pocetPrvkov / 2; i++){
        int x;
        x = Pole[pocetPrvkov - i - 1];
        Pole[pocetPrvkov - i - 1] = Pole[i];
        Pole[i] = x;
    }

}
/**
 * @file hlavny.cpp
 * @author Lukáš Kamen
 * @date 10.3.2025
 * @brief Hlavný súbor programu na zvrátenie poradia prvkov v poli.
 *
 * @param Tento program načítava pole celých čísel od používateľa a následne
 * zavolá 2 funkcie na obrátenie tohto pola:
 * 1. **Iteratívnou metódou** pomocou funkcie `obrat_It()`
 * 2. **Rekurzívnou metódou** pomocou funkcie `obrat_Re()`
 *
 * @param Program tiež obsahuje ošetrenie vstupu pre prípad, že používateľ zadá 0 alebo 1 prvok.
 * Výsledné polia sú vypísané na obrazovku.
 */

#include <iostream>
#include "iteracia.h"
#include "rekurzia.h"

using namespace std;

/**
 * @brief Hlavná funkcia programu.
 *
 * @param Funkcia načítava počet prvkov poľa od používateľa a ošetruje 
 * prípady, keď má pole 0 alebo 1 prvok. Následne dynamicky alokuje dve polia, 
 * do ktorých sa načítajú hodnoty zo vstupu. Po naplnení sú tieto polia 
 * obrátené dvoma metódami:
 * - **Iteratívne** pomocou `obrat_It()`
 * - **Rekurzívne** pomocou `obrat_Re()`
 *
 * Program na konci vypíše výsledky a uvoľní dynamicky alokovanú pamäť.
 *
 * @return Ak sa program vykoná úspešne, vráti 0. Pri chybe v alokácii pamäte vráti 1.
 */

int main(){

    int pocetPrvkov; /**< Počet prvkov v poli, načítaný od používateľa. */
    int lavy = 0;   /**< Index ľavého konca poľa pre rekurzívnu funkciu. */
    int *pole1 = NULL;  /**< Smerník na pole použité pri iterácii. */
    int *pole2 = NULL;  /**< Smerník na pole použité pri rekurzii */

    cin>>pocetPrvkov;

    if(pocetPrvkov == 0){
        cout<<"Pole musí mať aspoň 1 prvok."<<endl;
        return 0;
    }

    if(pocetPrvkov == 1){
        cin>>pocetPrvkov;
        cout<<pocetPrvkov;
        return 0;
    }

    int pravy = pocetPrvkov - 1;    /**< Index pravého konca poľa pre rekurzívnu funkciu. */

    pole1 = new int[pocetPrvkov];
    pole2 = new int[pocetPrvkov];

    /**
     * @brief Načítanie údajov do polí, ak majú oba smerníky hodnotu NULL a počet prvkov je viac ako 0.
     */
    
    if (pole1 != NULL && pole2 != NULL && pocetPrvkov > 0){
        for(int i = 0; i < pocetPrvkov; i++){
            cin>>pole1[i];
            pole2[i] = pole1[i];
        }
    }
    /**
     * Nasleduje zavolanie funkcii obrat_It, ktorá obráti pole čísel iteračnou metódou s parametrami pre pole, v ktorom sú uložené hodnoty a počet prvkov v tomto poli.
     * Keď sa táto funkcia vykoná zavolá sa funkcia obrat_Re s parametrami pre pole čísel, index lavej a pravej strany. Táto funkcia má za úlohu otočiť pole čísel pomocou iteračnej metódy.
     */
    obrat_It(pole1, pocetPrvkov);
    obrat_Re(pole2, lavy, pravy);

    for(int i = 0; i < pocetPrvkov; i++){
        cout<<pole1[i];
        
    }

    cout<<endl;

    for(int i = 0; i < pocetPrvkov; i++){   
        cout<<pole2[i];
    }

    /**
     * Pred ukončením programu sa uvolní alokovaná pamäť.
     */

    delete []pole1;
    delete []pole2;

    return 0;
}

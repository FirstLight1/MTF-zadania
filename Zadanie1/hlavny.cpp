/**
 * @mainpage # Iterácia vs. Rekurzia
 * 
 * ## Zadanie
 * 
 * Vytvoriť funkcie na obrátenie prvkov v poli pomocou iteračnej a rekurzívnej metódy.
 * 
 * ## Vývojový diagram
 * 
 * 
 * @image html obrat_it.png 
 * <center>diagram funkcie obrat_It</center>
 *  
 * ## Analýza problému pre rekurzívnu verziu
 * 
 * @par Na riešenie problému pomocou rekurzie som prišiel tak, že som najpv vyriešil ako vymeniť hodnoty dvoch prvkov v poli. Následne stačilo len upraviť parametre funkcie tak aby sa zväčšoval index na lavej strane pola a naopak index na pravej strane sa musel zmenšovať.
 * Ukončenie rekurzívneho volania funkcie nastane vtedy ak premenná, v ktorej je uložený lavý index pola má vačšiu hodnotu ako premenná, v ktorej je uložená hodnota pravého indexu pola.
 * 
 * ## Vzorový príklad
 * @paragraph Vzorový príklad pre iteračnú verziu kde pole[] = {1, 2, 3, 4, 5}.
 * 
 * | i        | pocetPrvkov | Pred zámenu     | Zámenu               | Po zámene        |
 * |----------|-------------|-----------------|----------------------|------------------|
 * | 0        | 4           | [1, 2, 3, 4, 5] | `Pole[0] ↔ Pole[4]`  | [5, 2, 3, 4, 1]  |
 * | 1        | 3           | [5, 2, 3, 4, 1] | `Pole[1] ↔ Pole[3]`  | [5, 4, 3, 2, 1]  |
 * | 2        | 2           | [5, 2, 3, 4, 1] | `Pole[2] ↔ Pole[2]`  | [5, 4, 3, 2, 1]  |
 * 
 *        pocetPrvkov = pocetPrvkov - 1 - i
 * 
 * @par Vzorový príklad pre rekúrzívnu verziu kde pole[] = {1, 2, 3, 4, 5}.
 * 
 * Zavolaj ObratRe(pole, 0, 4)  
 *      `Pole[0] ↔ Pole[4]` 
 *      Zavolaj ObratRe(pole, 1, 3) 
 *          `Pole[1] ↔ Pole[3]` 
 *          Zavolaj ObratRe(pole, 2, 2) 
 *              `Pole[2] ↔ Pole[2]` 
 *              Zavolaj ObratRe(pole, 3, 1) 
 *                  return 
 * 
 * 
 * ## Záver
 * 
 *  Cielom bolo vytvoriť algoritmus, ktorý otoči poradie prvkov v poli pomocou iteračnej a rekurzívnej metódy. Pri tvorbe algoritmu som nemal žiadne problémy. Algoritmus spĺňa všetky vlastnosti algoritmov.
 * Rekurzívny algoritmus (obrat_Re) má časovú zložitosť O(n), ale jeho pamäťová náročnosť je O(n) kvôli rekurzívnym volaniam, čo môže viesť k pretečeniu zásobníka pri veľkých poliach. Okrem toho môže byť pomalší kvôli dodatočným nákladom spojeným s rekurziou.

Na druhej strane, iteratívny algoritmus (obrat_It) má rovnakú časovú zložitosť O(n), ale jeho pamäťová náročnosť je iba O(1), pretože nevyžaduje ďalšiu pamäť pre zásobník. Iteratívny prístup je tiež rýchlejší, pretože nevyžaduje rekurzívne volania, ktoré zvyšujú časovú náročnosť.

Pre väčšie polia je teda lepšie zvoliť iteratívny prístup, ktorý je nielen rýchlejší, ale aj šetrí pamäť.
 * 
 */



/**
 * @file hlavny.cpp
 * @author Lukáš Kamen
 * @date 10.3.2025
 * @brief Hlavný súbor programu na zvrátenie poradia prvkov v poli.
 *
 * @paragraph Tento program načítava pole celých čísel od používateľa a následne
 * zavolá 2 funkcie na obrátenie tohto pola:
 * 1. **Iteratívnou metódou** pomocou funkcie `obrat_It()`
 * 2. **Rekurzívnou metódou** pomocou funkcie `obrat_Re()`
 *
 * @paragraph Program tiež obsahuje ošetrenie vstupu pre prípad, že používateľ zadá 0 alebo 1 prvok.
 * Výsledné polia sú vypísané na obrazovku.
 */

#include <iostream>
#include "iteracia.h"
#include "rekurzia.h"

using namespace std;

/**
 * @brief Hlavná funkcia programu.
 *
 * @paragraph Funkcia načítava počet prvkov poľa od používateľa a ošetruje 
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

    int pocetPrvkov;
    int lavy = 0;
    int *pole1 = NULL;
    int *pole2 = NULL;

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

    int pravy = pocetPrvkov - 1; 

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


    delete []pole1;
    delete []pole2;

    return 0;
}

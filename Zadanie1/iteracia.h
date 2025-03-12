/**
 * @file iteracia.h
 * @author Lukáš Kamen
 * @date 10.3.2025
 */

/**
 * @brief Funckia pre obrátenie poradia čísel v poli pomocou iterácie.
 * 
 * @param pole[] Pole, v ktorom sa nachádzajú čísla, ktorých poradie sa má obrátit.
 * 
 * @param pocet Určute počet prvko v pole.
 * 
 * @details Funkcia vykonáva iterácie cez pole a v každej iterácii vymieňa hodnoty 
 * prvkov na pozíciách `i` a `pocetPrvkov - i - 1`, čím sa prvky v poli postupne 
 * obrátia. Tento proces pokračuje, kým sa nedosiahne polovica poľa.
 * 
 * @note Táto funkcia mení hodnoty v pôvodnom poli, takže sa nevyžaduje žiadna ďalšia 
 * alokácia pamäte.
 */
#ifndef iteracia
#define iteracia
void obrat_It(int pole[], int pocet);

#endif
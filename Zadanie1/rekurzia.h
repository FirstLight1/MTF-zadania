/**
 * @file rekurzia.h
 * @author Lukáš Kamen
 * @date 10.3.2025
 */

/**
 * @brief Funckia pre obrátenie poradia čísel v poli pomocou rekurzie.
 * 
 * @param pole[] Pole, v ktorom sa nachádzajú čísla, ktorých poradie sa má obrátit.
 * 
 * @param lavy Index začiatku pola. Začína na nule a každým dalším volaním funcie sa zväčšuje.
 * 
 * @param pravy Index konca pola. Začína na hodnote \c pocetPrvkov - 1 \c, ktorú vypočítame v hlavny.cpp.
 * 
 * @details Funkcia je implementovaná ako rekurzívna metóda, ktorá vymieňa prvky na 
 * pozíciách `lavy` a `pravy`. Potom zavolá sama seba s upravenými indexami 
 * `lavy + 1` a `pravy - 1`. Rekurzia sa ukončí, keď index `lavy` presiahne 
 * alebo sa rovná indexu `pravy`.
 * 
 * @note Táto funkcia mení hodnoty v pôvodnom poli, takže sa nevyžaduje 
 * žiadna ďalšia alokácia pamäte.
 */
#ifndef rekurzia
#define rekurzia
void obrat_Re(int pole[], int lavy, int pravy);

#endif
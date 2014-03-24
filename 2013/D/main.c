/************************************************************************
 * Algorytm : Pracownia AiSD_D - Gramatyki                          *
 * URL      : www.ii.uni.wroc.pl/~mbi/dyd/aisd_13s                      *
 * Autor    : Marek Jenda                                               *
 * Data     : 2013-04-09                                                *
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

// wartosci bitow odpowiednich symboli nieterminalnych
// pozwala to na osmiokrotne zmniejszenie rozmiaru macierzy
#define _A    1
#define _B    2
#define _C    4
#define _D    8
#define _E    16
#define _F    32
#define _G    64
#define _H    128
#define START 128
#define ZERO  0

#define MAX_WORD 1000

// produkcja NIETERMINAL -> NIETERMINAL,NIETERMINAL
typedef struct product1 {
    unsigned char first;
    unsigned char second1;
    unsigned char second2;
} product1;

// produkcja NIETERMINAL -> TERMINAL
typedef struct product2 {
    unsigned char first;
    unsigned char second;
} product2;

// funkcja konwertujaca nieterminale na bity.
unsigned char convert(unsigned char c);


//banalna struktura danych wynikajaca z mej ulomnosci informatycznej
unsigned char a[MAX_WORD][MAX_WORD];      // "trojkat" z nieterminalami
product1 type1[MAX_WORD];                 // zbior produkcji typu N -> NN
product2 type2[MAX_WORD];                 // zbior produkcji typu N -> T
unsigned char word[MAX_WORD];             // wyrazenie

int main()
{
    unsigned char posibl[257][257];
    unsigned char checked[257][257];
    int instances, m1, m2, word_length;
    int length, sublength, split, i, j, k, inst, r;

    // --------- wczytywanie
    scanf("%d", &instances);
    for(inst = 0; inst < instances; inst++)
    {
        scanf("%d %d", &m1, &m2);
        for(i = 1; i <= m1; i++) {
            scanf("\n%c %c %c", &type1[i].first, &type1[i].second1, &type1[i].second2);
            type1[i].first   = convert(type1[i].first);
            type1[i].second1 = convert(type1[i].second1);
            type1[i].second2 = convert(type1[i].second2);
        }
        for(i = 1; i <= m2; i++) {
            scanf("\n%c %c", &type2[i].first, &type2[i].second);
            type2[i].first = convert(type2[i].first);
        }
        scanf("\n%s", &word);
        word_length = strlen(word);
        // --------- koniec wczytywania

        // na poczatku wszystkie kombinacje nieterminali nie wystapily
        for(i = 0; i <= 256; i++)
            for(j = 0; j <= 256; j++) {
                posibl[i][j] = 0;
                checked[i][j] = 0;
        }

        // na pocatku "trojkat" jest pusty
        for(i = 0; i <= word_length; i++)
            for(j = 0; j <= word_length; j++)
                a[i][j] = 0;

        // podstawa "trojkata" wynika z produkcji "terminalnych"
        for(i = 0; i < word_length; i++)
            for(j = 1; j <= m2; j++)
                if(word[i] == type2[j].second)
                    a[i+1][i+1] |= type2[j].first;

        // CYK
        for(length = 2; length <= word_length; length++) { // dla kazdej dlugosci
            for(sublength = 1; sublength <= word_length - length + 1; sublength++) { // dla kazdego podslowa
                r = sublength + length - 1;
                for(split = sublength + 1; split <= r; split++) { // dla kazdego podzialu
                    if(checked[ a[sublength][split-1] ][ a[split][r] ] == 0) {
                        for(k = 1; k <= m1; k++)
                            if(a[sublength][split-1] & type1[k].second1)
                                if(a[split][r] & type1[k].second2) {
                                    posibl[ a[sublength][split-1] ][ a[split][r] ] |= type1[k].first; // czy dana kombinacja nieterminali juz wystapila?
                                    a[sublength][r] |= posibl[ a[sublength][split-1] ][ a[split][r] ];
                                }
                        checked[ a[sublength][split-1] ][ a[split][r] ] = 1;
                    } else
                        a[sublength][r] |= posibl[ a[sublength][split-1] ][ a[split][r] ];
                }

            }
        }

        if(_A & a[1][word_length])
            printf("TAK\n");
        else
            printf("NIE\n");

    }
    return 0;
}





unsigned char convert(unsigned char c) {
    switch(c) {
        case 'A':
            return _A;
            break;
        case 'B':
            return _B;
            break;
        case 'C':
            return _C;
            break;
        case 'D':
            return _D;
            break;
        case 'E':
            return _E;
            break;
        case 'F':
            return _F;
            break;
        case 'G':
            return _G;
            break;
        case 'H':
            return _H;
            break;
        default:
            return ZERO;
            break;
    }
}

/************************************************************************
 * Algorytm : Pracownia AiSD_C - Monety                                 *
 * URL      : www.ii.uni.wroc.pl/~mbi/dyd/aisd_13s                      *
 * Autor    : Marek Jenda                                               *
 * Data     : 2013-04-03                                                *
 ************************************************************************/
#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_BAG_WEIGHT 100001
#define MAX_COINS      101
#define PLUS_INF       1000000000000000000LL
#define MINUS_INF     -1000000000000000000LL
                    // 9223372036854775808

// reprezentacja torby z pieniedzmi
typedef struct elem {
    long long int _min;        // wartosci minimalna zawartosci
    long long int _max;        // wartosc maksymalna zawartosci
    int _min_prev;   // ostatnia moneta w torbie (przypadek min)
    int _max_prev;   // ostatnia moneta w torbie (przypadek max)
} elem;

// reprezentacja monety
typedef struct coin {
    int p;           // jej wartosc
    int w;           // jej ciezar
    int _min_c;      // ilosc tych monet w przypadku min
    int _max_c;      // ilosc tych monet w przypadku max
} coin;

int main()
{
    //printf("TU");
    elem* arr = new elem[MAX_BAG_WEIGHT];
    coin* coins = new coin[MAX_COINS];
    int i, j, f, c, k;

    /// Pobieranie danych
    scanf("%d", &f);
    scanf("%d", &c);
    for(i = 1; i <= c; i++)
        scanf("%d %d", &coins[i].p, &coins[i].w);

    /// Ustalanie wartosci wstepnych
    for(j = 1; j <= f; j++) {
        arr[j]._min = PLUS_INF;
        arr[j]._max = MINUS_INF;
    }
    arr[0]._max = arr[0]._min = 0;

    /// Petla glowna ktora liczy wartosci min i max jednoczesnie
    for(i = 1; i <= c; i++) { //dla kazdej monety
        coins[i]._max_c = coins[i]._min_c = 0;
        for(j = 1; j <= f; j++) {
            if(j-coins[i].w >= 0) {
                if(arr[j]._min > arr[j-coins[i].w]._min + coins[i].p) {
                    arr[j]._min = arr[j-coins[i].w]._min + coins[i].p;
                    arr[j]._min_prev = i;
                }
                if((arr[j]._max < arr[j-coins[i].w]._max + coins[i].p) && (arr[j-coins[i].w]._max != MINUS_INF) ) {
                        arr[j]._max = arr[j-coins[i].w]._max + coins[i].p;
                        arr[j]._max_prev = i;
                }

            }//printf("%d ", arr[j]._max);

        }//printf("\n");
    }

    /// Wypisywanie wyniku
    if(arr[f]._min == PLUS_INF)
        printf("NIE\n");
    else {
        printf("TAK\n");
        printf("%lld\n", arr[f]._min);

        i = j = f;
        while(i > 0){
            coins[arr[i]._min_prev]._min_c++;
            i -= coins[arr[i]._min_prev].w;
        }
        for(i = 1; i <= c; i++)
            printf("%d ", coins[i]._min_c);
        printf("\n");
        printf("%lld\n", arr[f]._max);
        i = k = f;
        while(i > 0 && k > 0){
            coins[arr[i]._max_prev]._max_c++;
            i -= coins[arr[i]._max_prev].w;
            k--;
        }
        for(i = 1; i <= c; i++)
            printf("%d ", coins[i]._max_c);

        printf("\n");
    }
    return 0;
}

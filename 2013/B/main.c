/************************************************************************
 * Algorytm : Pracownia AiSD_B - Tabliczka Mnozenia                     *
 * URL      : www.ii.uni.wroc.pl/~mbi/dyd/aisd_13s                      *
 * Autor    : Marek Jenda                                               *
 * Data     : 2013-03-31                                                *
 * UWAGI    : Algorytm w wersji alfa. Powinien pracowac w O(klogk),     *
 *          : ale z nieustalonych jeszcze powodow dziala dluzej.        *
 ************************************************************************/

/// TODO : ogolna optymalizacja
///        uporzadkowac zmienne, (niektorym dac mniejszy rozmiar)
///        zoptymalizowac kolejke (umieszczanie elementu od korzenia?)
///        eksperymentalnie ustalic wielkosc kolejki.
///        moze cos jest nie tak z doborem elementow z tabliczki mnozenia do kolejki?


#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 1000000
#define INF       1000000000001

typedef unsigned long long int ULL;

ULL a[MAX_QUEUE];
int n;

void ZmienElem(ULL* t, int i, ULL u);
void  PrzesunNizej(ULL* t, int i);
void  PrzesunWyzej(ULL* t, int i);
void BudujKopiec(ULL* t);
ULL FindMax(ULL* t);
void DeleteMax(ULL* t);
void InsertNode(ULL* t, ULL u);

int main()
{
    int i, j, m, k, l, o, bo, bl;
    ULL last = 0; // ostatnim wypisanym elementem jest 0 (element z poza listy)

    n = 0;                           // wielkosc kolejki = 0
    bo = 1, bl = 0;                  // indeksy pozwalajace wypisywanie elementow z macierzy po skosie i od przekatnej w dol;
    scanf("%d %d", &m, &k);
    a[1] = (ULL)INF;                      // pozwala uniknac wejscia w pierwszego ifa w petli glownej.

    /// petla glowna: wypisuje elementy po skosie i od przekatnej w dol
    for(o = l = m; o > 0 && l > 0 && k > 0; o -= ((++bo) % 2), l -= ((++bl) % 2))
        for(i = o, j = l; i <= m && j >= 1 && k > 0; i++, j--) {
            if((ULL)i*j > a[1]) {  // jezeli element jest wiekszy od najwiekszego w kolejce to po prostu go wypisz
                last = a[1];
                printf("%llu\n", a[1]);
                k--;
            } else {
                InsertNode(a, (ULL)i*j);   // umiesc elemenet w kolejce
                if(n > MAX_QUEUE-10 && k > 0) { // jezeli zblizamy sie do konca kolejki to zacznij wypisywac elementy
                    while(last == a[1])  // radz sobie z duplikatami
                        DeleteMax(a);
                    last = a[1];
                    printf("%llu\n", a[1]);
                    DeleteMax(a);
                    k--;
                }
            }
        }

    // to samo co w petli glownej, wypisywanie elementow.
    while(n > 0 && k > 0) {
        if(last == a[1]) {
            DeleteMax(a);
            continue;
        }
        last = a[1];
        printf("%llu \n", a[1]);
        DeleteMax(a);
        k--;
    }


    return 0;
}

/// KOLEJKA PRIORYTETOWA TYPU MAX
//  oparta na strukturze tablicowej przekazywanej przez wskaznik.
//  UWAGA: Rozmiar kopca jest zawarty w zmiennej n bedacej zmienna globalna

// zamienia elemen o podanym indeksie z nowym elemenetem
void ZmienElem(ULL* t, int i, ULL u) {
    ULL x;
    x = t[i];
    t[i] = u;
    if(u < x) {
        PrzesunNizej(t, i);
    } else
        PrzesunWyzej(t, i);
}

// przesuwa nizej elemen z podanego indeksu w celu uzyskania struktury kopca
void  PrzesunNizej(ULL* t, int i) {
    int k, j, doub;
    ULL s;
    k = i;
    do {
        j = k; doub = j << 1;
        if(doub <= n && t[doub] > t[k])
            k = doub;
        if(doub < n  && t[doub + 1] > t[k])
            k = doub + 1;
        s    = t[j];
        t[j] = t[k];
        t[k] = s;
    } while(j != k);
}

// przesuwa wyzej elemen z podanego indeksu w celu uzyskania struktury kopca
void  PrzesunWyzej(ULL* t, int i) {
    int k, j, half;
    ULL s;
    k = i;
    do {
        j = k; half = j >> 1;
        if( j > 1 && t[half] < t[k])
            k = half;
        s    = t[j];
        t[j] = t[k];
        t[k] = s;
    } while(j != k);
}

// buduje kopiec dla podanej tablicy
void BudujKopiec(ULL* t) {
    int i;
    for(i = n / 2; i > 0; i--)
        PrzesunNizej(t, i);
}


// zwraca element najwiekszy
ULL FindMax(ULL* t){
    return t[1];
}

// usuwa najwiekszy element
void DeleteMax(ULL* t){
    t[1] = t[n]; n--;
    PrzesunNizej(t, 1);

}

// wstawia nowy element do kopca
/// TODO: Czy w podanym programie aby na pewno umieszczanie nowego elementu w lisciu
///       jest optymalne? Przeciez niemal za kazdym razem powedruje on w okolice korzenia!
void InsertNode(ULL* t, ULL u) {
    n++;
    a[n] = u;
    PrzesunWyzej(t, n);
}

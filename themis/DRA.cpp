#include <stdio.h>
#include <stdlib.h>

#define MOD 500000003

int test(int);
int modulo(int);
void czysc(int);
int drabina();

int t;    // liczba przypadkow testowych
int n, k; // dlugosc drabiny, liczba pokolorowanych krawedzi
char gora[1005], dol[1005], srodek[1005];
int drzewo[1005][3005], las[1005][3005];

int main()
{
    int i;
    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        scanf("%d %d", &n, &k);
        scanf("%s", gora);
        scanf("%s", srodek);
        scanf("%s", dol);
        printf("\n%d\n", drabina());
    }
    return 0;
}

int test(int x) {
    return x - 48;
}

int modulo(int x) {
    return x % 2;
}

void czysc(int i) {
    int j;
    for(j = 0; j <= k + 4; j++)
        drzewo[i][j] = las[i][j] = 0;
}

int drabina() {
    int i, j, act, prev, _gora, _dol, _srodek;

    // baza
    czysc(0);
    if(test(srodek[0]) == 0) {
        drzewo[0][0] = 1;
        drzewo[0][1] = 0;
    } else {
        drzewo[0][0] = 0;
        drzewo[0][1] = 1;
    }
    las[0][0] = 1;

    for(i = 1; i <= n; i++) {
        act = modulo(i); prev = modulo(i-1);
        czysc(act);
        _gora   = test(  gora[i-1]);
        _dol    = test(   dol[i-1]);
        _srodek = test(srodek[i]);
        for(j = 0; j <= k; j++) {
            drzewo[act][j + _gora + _dol]                     = (drzewo[act][j + _gora + _dol]            + drzewo[prev][j]) % MOD;
            drzewo[act][j + _gora + _srodek]                  = (drzewo[act][j + _gora + _srodek]         + drzewo[prev][j]) % MOD;
            drzewo[act][j + _dol + _srodek]                   = (drzewo[act][j + _dol + _srodek]          + drzewo[prev][j]) % MOD;
            drzewo[act][j + _dol + _gora + _srodek]           = (drzewo[act][j + _dol + _gora + _srodek]  + las[prev][j])    % MOD;
            las[act][j + _dol]                                = (las[act][j + _dol]                       + drzewo[prev][j]) % MOD;
            las[act][j + _gora]                               = (las[act][j + _gora]                      + drzewo[prev][j]) % MOD;
            las[act][j + _gora + _dol]                        = (las[act][j + _gora + _dol]               + las[prev][j])    % MOD;
        }
    }
    return drzewo[act][k];
}
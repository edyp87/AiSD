/**
    @name:     aisd_2014_zadanieB
    @author:   Marek Jenda
    @revision: 1.0
    @date:     28.03.2014
    @file:     B.cpp (main file)
    @depends:  none
    @notes:    This is just a sratch so please treat this code with distanse :)
               Complexity: O(wyso*szer), think cant be better, but there we can still
               decrease constant hidden in big O notation.
**/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

typedef unsigned long long ull;
typedef unsigned long      ul ;


int main() {
    // Getting input and initializing data
    ul wyso, szer;
    scanf("%lu %lu", &wyso, &szer);
    char * dane_akt   = new char[szer+2];           // just read data
    char * dane_poprz = new char[szer+2];           // data read at previous iteration
    std::fill(dane_akt,   dane_akt  +szer+2, '0');  // initialize with char zeroes
    std::fill(dane_poprz, dane_poprz+szer+2, '0');
    ul * aktualny  = new ul[szer+2]();              // last brackets initilize with zeroes, smart :)
    ul * poprzedni = new ul[szer+2]();
    aktualny[1] = 1;                                // first node cat be reached in one way

    // Main loop
    for(ul i = 0; i <= wyso; i++) {
        scanf("%s", dane_akt+1);

        ul pozycja = 1; //position zero has always value zero. Position zero is just a virtual column (filled with zeroes).

        for(ul j = 0; j <= szer; j++) {

            // 1. South route
            ul cyfra_poprz = dane_poprz[j+1] - 48;
            if(cyfra_poprz & ul(4))
                aktualny[j+1] = (aktualny[j+1] + poprzedni[j+1]) % 999979;

            // 2. South-east route
            cyfra_poprz = dane_poprz[j] - 48;
            if(cyfra_poprz & ul(2))
                aktualny[j+1] = (aktualny[j+1] + poprzedni[j]) % 999979;

            // 3. East route
            ul cyfra_akt = dane_akt[j] - 48;
            if(cyfra_akt & ul(1))
                aktualny[j+1] = (aktualny[j+1] + aktualny[j]) % 999979;

            pozycja++;

        }

        std::swap(poprzedni, aktualny);
        std::swap(dane_poprz, dane_akt);
        std::fill(aktualny, aktualny+szer+2, 0);

    }

    printf("%lu\n", poprzedni[szer+1] );

    return 0;
}

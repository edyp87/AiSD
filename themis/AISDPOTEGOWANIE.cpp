//Marek Jenda
//241647
//MSz

#include <stdio.h>
#include <stdlib.h>

unsigned long long potegowanie(unsigned long long podstawa, unsigned long long potega, unsigned long long dzielnik);
unsigned long long potegowanie_binarne(unsigned long long podstawa, unsigned long long potega, unsigned long long dzielnik);

int main()
{
    unsigned long long pod, pot, dziel; //podstawa, potega, dzielnik
    unsigned short i, l; //liczba_przykladow, iterator
    scanf("%d", &l);
    for(i = 0; i < l; i++) {
        scanf("%lld %lld %lld", &pod, &pot, &dziel);
        printf("%lld\n", potegowanie_binarne(pod, pot, dziel));
    }

    return 0;
}

//zrodlo: Wyklad z Matematyki Dyskretnej (prof. MSys)
unsigned long long potegowanie(unsigned long long podstawa, unsigned long long potega, unsigned long long dzielnik) {
    unsigned long long  s;
    unsigned short i;

    for(i = 0, s = 1; i < potega; i++) {
        s = ( s * podstawa ) % dzielnik;
    }

    return s;
}

//zrodlo: Cormen
unsigned long long potegowanie_binarne(unsigned long long podstawa, unsigned long long potega, unsigned long long dzielnik) {
    unsigned long long s;
    s = 1;
    while(potega > 0) {
        if(potega % 2 == 1)
            s = (s * podstawa) % dzielnik;
        potega = potega >> 1;
        podstawa = (podstawa * podstawa) % dzielnik;

    }
    return s;
}
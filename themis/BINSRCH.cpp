//Marek Jenda
//241647
//MSz

#include <iostream>

using namespace std;

int ile_liczb(int x, int *tab, int lewy, int prawy);

int main(void)
{
    int n, i, m, x;
    cin >> n;
    int tab[n];

    for(i = 0; i < n; i++)
        cin >> tab[i];

    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> x;
        cout << n-ile_liczb(x, tab, 0, n - 1) << " ";
    }
}

int ile_liczb(int x, int *tab, int lewy, int prawy)
{
    int srodek;
    while(lewy != prawy)
    {
        srodek = (lewy + prawy) / 2;
        if(tab[srodek] >= x) prawy = srodek;
        else                 lewy  = srodek + 1;
    }
    return (tab[lewy] >= x) ? lewy : lewy + 1;
}
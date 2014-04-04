/* Algorytm : Bellman-Ford - oparte na Cormen (r.24) i CCNA
 * Autor    : Marek Jenda
 * Data     : 2013-03-31
 * UWAGI    : algorytm wypisuje jedynie dlugosci najdkrotszych sciezek,
 *            relaksacje są wykonywane |V|-1 razy dla kazdej krawedzi
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 722337203685477580   // nieskonczonosc
#define N 520         // maks liczba wierzcholkow

// Krawedz skierowana u -> v . W tym algorytmie jest to wygodna struktura danych.
typedef struct edge {
    int u;
    int v;
    int w;
} edge;

edge edges[N*N]; // wszystkie krawedzie
long long int d[N];        // koszt drog do wierzcholkow

int n; // ilosc wierzcholkow
int m; // ilosc krawedzi
int s; // wierzcholek wyrozniony

void initialize();
void relax(int e);
int bellman_ford(int s);

int main()
{
    int i;

    scanf("%d %d %d", &n, &m, &s);
    for(i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    initialize();
    if(bellman_ford(s)) {
        for(i = 0; i <= n; i++)
            if(i != s && d[i] != INF)
                printf("%d %lld\n", i, d[i]);
        return 0;
    } else {
        printf("NIE\n");
        return 0;
    }
}

void initialize() {
    int i;

    for(i = 0; i <= n; i++)
        d[i] = INF;
    d[s] = 0;
};

/* Relaksacja krawedzi (u,v)
 * polega na sprawdzeniu czy porzechodzac przez wierzcholek u, mozna znalezc
 * krotsza od dotychczas najkrotszej sciezki do v.
 * Mowiac inaczej: relaksacja to określanie górnego ograniczenia na wage sciezki.
 * Wynika z nierownosci trojkata: s(s,v) <= s(s,u)) + w(u,v), gdzie s() to najkrotsza sciezka
 */
void relax(int e) {
    if((d[edges[e].u] != INF) && (d[edges[e].v] > d[edges[e].u] + edges[e].w)) {
        d[edges[e].v] = d[edges[e].u] + edges[e].w;
    }

}

int bellman_ford(int s) {
    int i, j;

    for(i = 0; i <= n-1; i++)
        for(j = 0; j < m; j++) {
            relax(j); }

    for(j = 0; j < m; j++)
        if(d[edges[j].v] != INF && (d[edges[j].v] > d[edges[j].u] + edges[j].w))
            return 0;

    return 1;
}



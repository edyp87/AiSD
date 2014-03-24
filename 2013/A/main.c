#include <stdio.h>
#include <stdlib.h>

//------- Typy i Struntury Danych ---------

typedef struct wezel {
    char pole;
    short int w;
    short int k;
    int dist;
    short int vis;
} wezel;

typedef struct wezel_maly {
	char pole;
	char vis;
} wezel_maly;

typedef struct elem {
    wezel  n            ;
    struct elem *nast ;
} elem ;

typedef struct kolejka {
    elem *poczatek ;
    elem *koniec   ;
} kolejka ;

//-----------------------------------------

//-------------- Prototypy ----------------

void init (kolejka *K);
short int pusta (kolejka *K);
void dolacz (wezel x, kolejka *K);
wezel usun (kolejka *K);
int adj(int w, int k);

kolejka Q;
short int m, n;
wezel_maly nodes[2020][2020];
wezel u, a;

int main()
{
    short int i, j, sw, sk, d;
    (void) scanf("%hd %hd\n", &m, &n);
    char tab2[2020];

    init(&Q);

    for(i = 0; i < n; i++) {
	(void) fgets(tab2, sizeof(tab2), stdin);
        for(j = 0; j < m; j++) {
            nodes[i][j].pole = tab2[j];
            nodes[i][j].vis = 0;
            if(nodes[i][j].pole == 'P') {
                u.w = i;
		u.k = j;
		u.dist = 0;
                u.vis = 1;
                dolacz(u,&Q);
            }
            if(nodes[i][j].pole == 'S') {
                sw = i;
                sk = j;
            }
        }
    }

    while(!pusta(&Q)) {// printf("tu");
        u = usun(&Q);
        if(adj(u.w+1, u.k)) {
            d = u.w+1;
	    a.pole = nodes[d][u.k].pole;
            a.vis  = nodes[d][u.k].vis = 1;
            a.dist = u.dist + 1;
	    a.w = d;
	    a.k = u.k;
            dolacz(a, &Q);
            if(a.pole == 'S') {
                printf("%d",  a.dist);
                break;
            }
        }
        if(adj(u.w-1, u.k)) {
            d = u.w-1;
	    a.pole = nodes[d][u.k].pole;
            a.vis = nodes[d][u.k].vis = 1;
            a.dist = u.dist + 1;
	    a.w = d;
	    a.k = u.k;
            dolacz(a, &Q);
            if(a.pole == 'S') {
                printf("%d",  a.dist);
                break;
            }
        }
        if(adj(u.w, u.k+1)) {
            d = u.k+1;
	    a.pole = nodes[u.w][d].pole;
            a.vis = nodes[u.w][d].vis = 1;
            a.dist = u.dist + 1;
	    a.w = u.w;
	    a.k = d;
            dolacz(a, &Q);
            if(a.pole == 'S') {
                printf("%d",  a.dist);
                break;
            }
        }
        if(adj(u.w, u.k-1)) {
            d = u.k-1;
	    a.pole = nodes[u.w][d].pole;
            a.vis = nodes[u.w][d].vis = 1;
            a.dist = u.dist + 1;
	    a.w = u.w;
	    a.k = d;
             dolacz(a, &Q);
            if(a.pole == 'S') {
                printf("%d",  a.dist);
                break;
            }
        }
    }

    if(nodes[sw][sk].vis == 0) printf("NIE");

    return 0;
}

int adj(int w, int k) {
    if( w < 0 || w >= n ||
        k < 0 || k >= m ||
        nodes[w][k].pole == 'x' ||
        nodes[w][k].vis == 1
      )
        return 0;
    else return 1;
}

void init (kolejka *K) {
    K -> poczatek = NULL;
    K -> koniec   = NULL;
}


short int pusta (kolejka *K) {
    return K -> poczatek == NULL;
}

void dolacz (wezel x, kolejka *K) {
    elem *p;
    p = malloc(sizeof(elem));
    p -> n    = x   ;
    p -> nast = NULL;
    if(pusta(K)) {
        K -> poczatek = p;
        K -> koniec   = p;
    } else {
        K -> koniec -> nast  = p;
        K -> koniec          = p;
    }
}

wezel usun (kolejka *K) {
    wezel x;
    elem *p;
    if(pusta(K)) {
        printf("Kolejka jest pusta!\n");
        return x;
    }
    p = K -> poczatek;
    if(K -> poczatek == K -> koniec) {
        x = K -> poczatek -> n;
        free(p);
        K -> poczatek = NULL;
        K -> koniec   = NULL;
        return x;
    }
    x = K -> poczatek -> n;
    K -> poczatek = K -> poczatek -> nast;
    free(p);
    return x;
}

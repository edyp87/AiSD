/* Algorytm : Nawiasowanie iloczynu macierzy - oparte na Cormen (s.374)
 * Autor    : Marek Jenda
 * Data     : 2013-06-11
 */

#include <stdio.h>
#include <stdlib.h>

#define INF 8446744073709551615

unsigned long long min_koszt_nawiasowania(int *p, int n);

int main()
{
    int i, j, n, m;
    int p[201];

    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &n);
        for(j = 0; j <= n; j++)
            scanf("%d", &p[j]);
        printf("%llu\n", min_koszt_nawiasowania(p,n));
    }

    return 0;
}

unsigned long long min_koszt_nawiasowania(int *p, int n) {
    int i, j, k, l;
    unsigned long long m[n+1][n+1], q;

    for(i = 1; i <= n; i++)
        m[i][i] = 0;

    for(l = 2; l <= n; l++)
        for(i = 1; i <= n-l+1; i++){
            j = i + l - 1;
            m[i][j] = INF;
            for(k = i; k <= j - 1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                }
            }

        }

    return m[1][n];

}
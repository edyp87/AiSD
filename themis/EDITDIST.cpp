#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void edit_distance(char* a, char* b);
int min(int x, int y);

int c[1001][1001];

int main()
{
    char a[1001], b[1001];
    int m, n;
    scanf("%d %s", &m, &a);
    scanf("%d %s", &n, &b);
    edit_distance(a, b);
    printf("%d", c[m][n]);
    return 0;
}

void edit_distance(char* a, char* b) {
    int i, j, m, n;

    m = strlen(a);
    n = strlen(b);

    c[0][0] = 0;
    for(i = 1; i <= m; i++)
        c[i][0] = i;
    for(j = 1; j <= n; j++)
        c[0][j] = j;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
             //min(c[i-1][j] + 1, c[i][j-1] + 1);
            c[i][j] = min(c[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 2), min(c[i-1][j] + 1, c[i][j-1] + 1));
}

int min(int m, int n) {
    if(m > n)
        return n;
    else return m;
}
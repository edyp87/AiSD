#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LCS_LENGTH(char* a, char* b, int m, int n);
int c[1001][1001], d[1001][1001];
int   m, n;

int main()
{
    char a[1001], b[1001];
    int i, n, m;

    scanf("%d", &i);
    while(i > 0) {
        scanf("%d", &n);
        scanf("%s", &a);
        scanf("%d", &m);
        scanf("%s", &b);
        LCS_LENGTH(a, b, n, m);
        printf("%d\n", c[n][m]);
        i--;
    }
    return 0;
}

int LCS_LENGTH(char* a, char* b, int m, int n) {
   // m = strlen(a);
   // n = strlen(b);
    int i, j;

    for(i = 1; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                d[i][j] = 0;
            } else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                d[i][j] = 1;
            } else {
                c[i][j] = c[i][j-1];
                d[i][j] = 2;
            }
        }

    //for(i = 0; i <= m; i++) {
    //    for(j = 0; j <= n; j++)
    //        printf("%d ", c[i][j]);
    //    printf("\n");
    //}
}

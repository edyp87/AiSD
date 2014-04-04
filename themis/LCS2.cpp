#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LCS_LENGTH(char* a, char* b);
void PRINT_LCS(char* a, int m, int n);


int c[1001][1001], d[1001][1001];
int   m, n;

int main()
{
    char a[1001], b[1001];

        scanf("%s", &a);
        scanf("%s", &b);
        LCS_LENGTH(a, b);
       // printf("%d\n", c[n][m]);
        PRINT_LCS(a, strlen(a), strlen(b));
    return 0;
}

int LCS_LENGTH(char* a, char* b) {
    m = strlen(a);
    n = strlen(b);
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

void PRINT_LCS(char* a, int m, int n) {
    if(m == 0 || n == 0)
        return;
    if(d[m][n] == 0) {
        PRINT_LCS(a, m-1, n-1);
        printf("%c", a[m-1]);
    } else if(d[m][n] == 1)
        PRINT_LCS(a, m-1, n);
    else
        PRINT_LCS(a, m, n-1);

}
#include <iostream>
#include <cstdio>

using namespace std;
#define INF 1000000000
void stokrotki();

int main() {
    stokrotki();
    return 0;
}

void stokrotki() {
     unsigned short int i, j, n, m; //n - wiersz, m - kolumna
     int temp = INF;

     scanf("%hud", &n); scanf("%hud", &m);
     int** arr = new int*[n+2];
     for(i = 0; i < n+2; i++)
        arr[i] = new int[m+1];
    int* brr = new int[n+2];
     for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
     }

    for(i = 1; i <= m; i++)
        arr[0][i] = arr[n+1][i] = INF;
    brr[0] = brr[n+1] = INF;

    for(j = 2; j <= m; j++) {
        for(i = 1; i <= n; i++)
            brr[i] = arr[i][j] + min(arr[i-1][j-1], min(arr[i][j-1], min(arr[i+1][j-1], brr[i-1])));
        for(i = n; i >= 1; i--) {
            arr[i][j] += min(arr[i-1][j-1], min(arr[i][j-1], min(arr[i+1][j-1], arr[i+1][j])));
            arr[i][j] = min(arr[i][j], brr[i]);
        }
    }

    for(i = 1; i <= n; i++)
        if(temp > arr[i][m])
            temp = arr[i][m];

    printf("%d\n", temp);
}
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int set_max_sum(vector<int> &books, int min, int max);
int set_separators(vector<int> &books, int &m);

int sep, gr = 1000000000;

int main()
{
    vector<int> books;
    int max = 0, min = 0, i, n, temp;

    scanf("%d ", &n);
    scanf("%d\n", &sep);
    sep++;
    for(i = 0; i < n; i++) {
        scanf("%d", &temp);
      //  printf("%d ", temp);
        books.push_back(temp);
        max += temp;
        if(min < temp)
            min = temp;
    }
   // printf("%d, %d %d", min, max, sep);
   set_max_sum(books,  min, max);
   printf("%d\n", gr );
    return 0;
}

int set_max_sum(vector<int> &books, int min, int max) {
    int mid, best = 0;

    while( min < max) {
        mid = (min + max) / 2;

        if((best = set_separators(books, mid)) <= sep) {
            if(max == mid) return mid;
            max = mid;
           // cout << "MAX : "  << max << endl;
        }
        else {
            if(min == mid) return mid;
           // cout << "MIN : "  << min << " " << max << endl;
            min = mid;
        }
       // if(max - min <= 1)
       //     return mid;
        //cout << "    BEST : "  << best << endl;
    }

    return mid;
}

int set_separators(vector<int> &books, int &m) {
    int i, quantity = 0;
    int sum = 0, greatest = 0;

    for(i = 0; i < books.size(); i++) {
        if(sum + books[i] > m) {
            if(sum > greatest)
                greatest = sum;
            sum = 0;
            quantity++;
        }
        sum += books[i];
    }
    if(sum > 0)
        quantity++;
    if(quantity <= sep && gr > greatest)
        gr = greatest;

   // cout << quantity << " ";
    return quantity;
}
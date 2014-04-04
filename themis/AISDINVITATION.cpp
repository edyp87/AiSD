//Marek Jenda
//241647
//MSz

#include <iostream>

using namespace std;

int main(void)
{
	int a, b, swap;
	cin >> a >> b;
	if(b < a)
	{
		swap = b;
		b = a;
		a = swap;
	}
	while(a <= b)
		{
		    if(a % 2)
			cout << a << " ";
			a++;
		}
	return 0;
}
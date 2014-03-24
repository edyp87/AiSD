#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef unsigned long      ul ;
int main() {
	ul l_miast;
	ull suma = 0;
	ull polowa;
	ull temp;
	ull najlepszy = 0;
	ull akt;

	scanf("%lu", &l_miast);

	vector<ull> odcinek(l_miast);

	for(ul i = 0; i < l_miast; i++) {
		scanf("%llu", &odcinek[i]);
		odcinek[i] *= 2;
		suma += odcinek[i];
	}

	polowa = suma / 2;
	akt = 0;

	vector<ull>::iterator p_miasto = odcinek.begin(), d_miasto = odcinek.begin();

	while(d_miasto != odcinek.end()) {
		akt >= polowa ? akt -= *(p_miasto++) : akt += *(d_miasto++);

		akt < polowa ? temp = akt : temp = suma - akt;

		if(najlepszy < temp) najlepszy = temp;
	}

	printf("%llu\n", najlepszy/2);

	return 0;

}
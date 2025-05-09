#include <iostream>
using namespace std;
int main() {
	int n, i; //kreiranje celobrojnih promenljivih za broj elemenata niza i brojač u statičkoj zoni memorije
	int* niz; //kreiranje niza u dinamičkoj zoni memorije

	cout << "Unesi koliko elemanta ima niz: ";
	cin >> n;

	niz = new int[n]; //niz će zauzimati onoliko mesta u memoriji koliko elemanata ima niz

	for (i = 0; i < n; i++) {
		cout << "Unesi element niza: ";
		cin >> niz[i]; //punjenje niza
	}

	int sum = 0; //kreiranje promenljive u statičkoj zoni memorije za sumu elemenata niza
	for (i = 0; i < n; i++) {
		sum += niz[i]; //sumiranje elemenata niza
	}

	cout << "Izgled unetog niza: ";
	for (i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}

	cout << endl;
	cout << "Suma elemenata niza: " << sum;

	delete[]niz; //oslobadjanje dela memorije koje je zauzeto dinamičkom alokacijom za niz
	return 0;
}
/* Slično je kao i kod zadatka gde smo koristili statičku zonu memorije. Razlika je u tome što na početku,
imamo komandu niz=new int[n] koja rezerviše n mesta veličine formata int,
i naravno na kraju komandu delete[]niz koja oslobadja taj prostor. */
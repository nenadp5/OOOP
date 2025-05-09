#include <iostream>
using namespace std;
int main() {
	int n, i, a[40]; //kreiranje celobrojnih promenljivih za broj elemanta niza, brojac i niz u statickoj zoni memorije

	cout << "Unesi koliko elemenata ima vas niz: ";
	cin >> n;

	for (i = 0; i < n; i++) {
		cout << "Unesi element niza: ";
		cin >> a[i]; //unos elemenata niza
	}

	int sum = 0; //kreiranje celobrojne promenljive za sumu elemanta niza
	for (i = 0; i < n; i++) {
		sum += a[i]; //sumiranje elemenata niza
	}
	cout << "Izgled unetog niza: ";
	for (i = 0; i < n; i++) {
		cout << a[i] << " "; //ispis niza
	}

	cout << endl;
	cout << "Suma elemenata niza je: " << sum; //ispis sume niza
	 
	return 0;
}
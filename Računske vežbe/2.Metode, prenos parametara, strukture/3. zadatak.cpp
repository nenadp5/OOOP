#include <iostream>
using namespace std;

int zbir(int niz[], int duzina) { //funkcija za sumiranje elemenata niz, prosledjuje se niz i njegova duzina
	int sum = 0;
	for (int i = 0; i < duzina; i++) {
		sum += niz[i];
	}
	return sum;
}

void prikaz(int niz[], int duzina) { //funkcija za prikaz niza, takodje se prosledjuje niz i njegova duzina
	for (int i = 0; i < duzina; i++) {
		cout << niz[i] << " ";
	}
}

int najveci(int niz[], int duzina) { //funkcija za pronalazenje maksimalnog elementa niza
	int max = niz[0]; //prvi element u nizu postaje maksimalni
	for (int i = 1; i < duzina; i++) {
		if (niz[i] > max) { //svaki sledeci element se poredi sa maksimalnim
			max = niz[i];  //kada naidje neki veci element od maksimalnog onda on postaje novi maksimalni element
		}
	}
	return max;
}

void inkrement(int niz[], int duzina) { //funkcija za inkrementiranje svih elemenata niza
	for (int i = 0; i < duzina; i++) {
		niz[i]++; //prolazimo kroz ceo niz i uvecavamo svaki element posebno
	}
}

int main() {
	int n, i, * a; //kreiramo promenljve za broj elemenata niza, brojac (koji se nalaze u staitckoj zoni memorije) i niz (koji ce biti smesten u dinamickoj zoni memorije)
	
	cout << "Unesi koliko elemenata ima vas niz: ";
	cin >> n;
	a = new int[n]; //niz zauzima onoliko mesta u memoriji koliko elemanta ima, koji su formata int, to smo postigli uz pomoc dinamicke alokacije
	
	for (i = 0; i < n; i++) {
		cout << "Unesi element niza: "; //punjenje elemenata niza
		cin >> a[i];
	}
	
	cout << "Prikaz unetog niza: ";
	prikaz(a, n); //prikazujemo niz uz pomoc funkcije koju smo prethodno kreirali
	cout << endl;
	
	cout << "Suma elemenata toga niza je: " << zbir(a, n) << endl; //sumiramo elemente niza uz pomoc funkcije
	cout << "Najveci element niza je: " << najveci(a, n) << endl; //pronalazimo najveci element uz pomoc funkcije
	cout << "Inkrementiran niz izgleda: ";
	inkrement(a, n); //inkrementiramo i prikazujemo ponovo niz uz pomoc prethodno kreiranih funkcija
	prikaz(a, n);

	delete[]a; //oslobadjamo memoriju koja je bila zauzeta dinamickom alokacijom
	return 0;
}
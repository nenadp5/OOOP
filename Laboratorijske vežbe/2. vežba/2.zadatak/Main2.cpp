#include "Radnik.h"
#include <iostream>
using namespace std;
int main() {
	Radnik* niz[5]; //kreiramo niz od pet pokazivaca na radnike
	for (int i = 0; i < 5; i++) {
		niz[i] = new Radnik(); //prolazimo kroz ceo niz i za svaki element niza vrsimo dinamicku alokaciju
		cin >> *niz[i]; //svaki element niz prosledjujemo metodi za unos vrednosti
	}

	cout << "Uneti niz radnika izgleda: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << *niz[i]; //prolazimo kroz niz i uz pomoc operatora<< ispisujemo vrednosti
		cout << endl;  //"ostream& operator<<(ostream& izlaz, const Radnik& radnik)" i zbog toga imamo * kod prosledjivanja
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		(*niz[i])++; //operator++ "Radnik operator++" za uvecanje vrednosti elemenata niza
	}

	for (int i = 0; i < 4; i++) { //standardna metoda za sortiranje
		int iMin = i; //trenutni element smatramo minimalnim
		for (int j = i + 1; j < 5; j++) { //kreiramo brojac koji ide ispred trenutnog elementa
			if (*niz[iMin] > *niz[j]) {//uz pomoc operatora> poredimo vrednosti za iMin i j, prilikom poziva prosledjujemo * jer je metoda definisana "bool operator>(const Radnik& prvi,const Radnik& drugi);"
				iMin = j;
			}
		}
		if (iMin != i) { //ukoliko se razlikuje minimalna vrednost od pocetne onda se obavlja rotiranje vrednosti
			Radnik* pom = niz[iMin];
			niz[iMin] = niz[i];
			niz[i] = pom;
		}
	}
	cout << "Sortirani niz izgleda: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << *niz[i];  //prolazimo kroz ceo niz i svakog radnika prosledjujemo operatoru za prikaz vrednosti
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		delete niz[i]; //brisemo prostor koji su radnici zauzeli
	}
}
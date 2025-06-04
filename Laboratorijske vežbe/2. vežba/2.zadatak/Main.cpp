#include "Radnik.h"
#include <iostream>
using namespace std;
int main() {
	Radnik* niz[5]; //niz od pet pokazivaca na radnike
	float niz0[] = { 7.5,8,6.7,7.8,7 }; //kreiramo pomocne nizove u kojima su smesteni satovi rada za radnike
	float niz1[] = { 6.5,7,7.7,8.8,5,3 }; //morali smo kreirati ove promenljive jer je to ispravan nacin za direktan unos iz programa
	float niz2[] = { 7.5,8,6.7,7.8,7,2,6 };
	float niz3[] = { 6.5,9,6.9,8.9};
	float niz4[] = { 6.5,8,7.7,7.8,7 };

	niz[0] = new Radnik("Nikola", "Nikolic", 20, 5, 500, niz0); //kreiramo nove radnike uz pomoc konstruktora i prosledjujemo odgovarajuce vrednosti
	niz[1] = new Radnik("Petar", "Petrovic", 20, 6, 550, niz1);
	niz[2] = new Radnik("Milica", "Miletic", 20, 7, 590, niz2);
	niz[3] = new Radnik("Ivana", "Ivanovic", 20, 4, 500, niz3);
	niz[4] = new Radnik("Marko", "Markovic", 20, 5, 555, niz4);

	cout << "Uneti niz radnika izgleda: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << *niz[i]; //prolazimo kroz niz i uz pomoc operatora<< ispisujemo vrednosti
		cout << endl; //"ostream& operator<<(ostream& izlaz, const Radnik& radnik)" i zbog toga imamo * kod prosledjivanja
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		(*niz[i])++; //operator++ "Radnik operator++" za uvecanje vrednosti elemenata niza
	}

	for (int i = 0; i < 4; i++) { //standardna metoda za sortiranje
		int iMin = i; //trenutni element smatramo minimalnim
		for (int j = i + 1; j < 5; j++) { //kreiramo brojac koji ide ispred trenutnog elementa
			if (*niz[iMin] > *niz[j]) { //uz pomoc operatora> poredimo vrednosti za iMin i j, prilikom poziva prosledjujemo * jer je metoda definisana "bool operator>(const Radnik& prvi,const Radnik& drugi);"
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
		cout << *niz[i]; //prolazimo kroz ceo niz i svakog radnika prosledjujemo operatoru za prikaz vrednosti
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		delete niz[i]; //brisemo prostor koji su radnici zauzeli
	}

	return 0;
}
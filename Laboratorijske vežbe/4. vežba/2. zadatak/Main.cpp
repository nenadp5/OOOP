#include "Radnik.h"
#include "StalniRadnik.h"
#include "HonorarniRadnik.h"
#include <iostream> //ukljucujemo sve neophodne biblioteke i header fajlove za rad
using namespace std;
int main() {
	Radnik* niz[5]; //niz od 5 pokazivaca na radnike
	niz[0] = new HonorarniRadnik("Nikola", "Nikolic", 122, 350);
	niz[1] = new StalniRadnik("Milica", "Mitic",70000 , 2500); //na neparnim pozicijama se kreira stalni radnik
	niz[2] = new HonorarniRadnik("Milos", "Milosevic", 135, 350); //na parnim pozicijama se kreira honorarni radnik
	niz[3] = new StalniRadnik("Andjela", "Andjelkovic", 75000, 5000);
	niz[4] = new HonorarniRadnik("Petar", "Petrovic", 143, 350);
	cout << endl;
	cout << "Niz unetih radnika izgleda: " << endl;
	for (int i = 0; i < 5; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz,i za svaki element pozivamo metodu za prikaz
		cout << endl;
	}
	//ovo je cisto deo za vezbu, ne trazi se u okviru zadatka
	for (int i = 0; i < 4; i++) {
		int iMin = i; //kreiramo promenljivu koja uzima trenutnu vrednost
		for (int j = i + 1; j < 5; j++) { //kreiramo brojac koji ide ispred 
			if (*niz[iMin] > *niz[j]) { //svaki element prosledjujemo operatoru za poredjenje radnika, imamo * jer je operator definisan "bool operator(Radnik& drugi)"
				iMin = j;
			}
		}
		if (iMin != i) { //ukoliko ima izmena u odnosu na pocetak vrsi se njihova zamena mesta
			Radnik* pom = niz[i];
			niz[i] = niz[iMin];
			niz[iMin] = pom;
		}
	}

	cout << endl << "Niz sortiranih radnika izgleda: " << endl;
	for (int i = 0; i < 5; i++) {
		niz[i]->prikaz(); //ponovo prolazimo kroz ceo niz i vrsimo ispisivanje radnika, samo sto su ovog puta soritrani od minimalnog do maksimalnog primanja
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		delete niz[i]; //prolazimo kroz ceo niz i brisemo elemente smestene u dinamickoj zoni memorije
	}
	return 0;
}
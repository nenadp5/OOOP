#include "Pravougaonik.h"
#include "Kvadar.h"
#include <iostream>
using namespace std;
int main() {
	Pravougaonik* niz[6]; //niz od sest pokazivaca na pravougaonike
	niz[0] = new Pravougaonik(6, 5); //na parnim pozicijama u nizu se kreira pravougaonik
	niz[1] = new Kvadar(6, 5, 3); //na neparnim pozicijama u nizu se kreira kvadar
	niz[2] = new Pravougaonik(3, 4);
	niz[3] = new Kvadar(3, 4, 2);
	niz[4] = new Pravougaonik(6, 7);
	niz[5] = new Kvadar(6, 7, 6);

	for (int i = 0; i < 6; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz i svaki element niza prosledjujemo metodi za prikaz
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		delete niz[i]; //prolazimo kroz ceo niz i vrsimo brisanje elemenata koji su zauzeti u procesu dinamicke alokacije
	}

	return 0;

}
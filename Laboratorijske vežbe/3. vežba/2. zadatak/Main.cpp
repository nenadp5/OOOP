#include "Radnik.h"
#include "NagradjeniRadnik.h"
#include <iostream>
using namespace std;
int main() {
	Radnik* niz[4]; //niz od cetiri pokazivaca na Radnike
	niz[0] = new NagradjeniRadnik("Petar", 340, 45, 2000); //na parnim pozicijama u nizu se kreira nagradjeni radnik
	niz[1] = new Radnik("Luka", 400, 35); //na neparnim pozicijama u nizu se kreira obicni radnik
	niz[2] = new NagradjeniRadnik("Nikola", 360, 42, 1500);
	niz[3] = new Radnik("Nemanja", 440, 30);

	cout << endl;
	cout << "Uneti niz izgleda: " << endl;
	for (int i = 0; i < 4; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz i svaki element prosledjujemo metodi prikaz
		cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		delete niz[i]; //prolazimo kroz ceo niz i brisemo sve elemente smestene u dinamickoj zoni memorije
	}

	return 0;
}
#include "Ispit.h"
#include "StrucniIspit.h"
#include <iostream>
using namespace std;
int main() {
	Ispit* niz[4]; //niz od 4 pokazivaca na ispite
	niz[0] = new StrucniIspit("Matematika1", 43, 34,0); //buduci da je "Ispit" apstraktna klasa njoj se vrednosti ne mogu dodeljivati na ovakav nacin, pa su zato sve promenljive tipa "StrucniIspit"
	niz[1] = new  StrucniIspit("Elektronika", 33, 32, 20); //kako bismo odvojili strucni ispit od obicnog, samo za vrednost laboratorijskih vezbi prosledimo vrednost 0
	niz[2] = new StrucniIspit("Matematika2", 12, 33,0);
	niz[3] = new StrucniIspit("Programiranje", 30, 31, 20);

	for (int i = 0; i < 4; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz i prosledjujemo vrednosti metodi za prikaz
		cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		delete niz[i]; //oslobadjamo zauzeti memorijski prostor
	}
	return 0;
}
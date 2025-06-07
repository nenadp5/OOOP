#include "Putovanje.h"
#include "Zimovanje.h"
#include "Letovanje.h"
#include <iostream> //ukljucujemo sve neophodne biblioteke i header fajlove za rad
using namespace std;
int main() {
	Putovanje* niz[6]; //niz od sest pokazivaca na putovanja
	niz[0] = new Letovanje("Zrce", 10, 37000, 10000, 25000);
	niz[1] = new Zimovanje("Jahorina", 7, 28000, 9000, 15000);
	niz[2] = new Letovanje("Hawai", 7, 47500, 35000, 37000); //na parnim pozicijama u nizu se upisuju letovanja
	niz[3] = new Zimovanje("Kopaonik", 10, 30000, 2000, 20000); //na neparnim pozicijama u nizu se upisuju zimovanja
	niz[4] = new Letovanje("Budva", 9, 27000, 7000, 15000);
	niz[5] = new Zimovanje("Alpi", 8, 40000, 19000, 29000);

	cout << endl;
	cout << "Ponude za putovanja: " << endl;
	for (int i = 0; i < 6; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz, i svaki element niza prikazujemo uz pomoc metode za prikaz
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		int iMin = i; //kreiramo pomocnu promenljivu koja uzima trenutnu vrednost u nizu kao najmanju
		for (int j = i + 1; j < 6; j++) { //kreiramo dodatni brojac koji ide ispred prethodnog i kasnije poredi elemente sa njim
			if (*niz[j] < *niz[iMin]) { //poredimo brojac J i pomocnu promenljivu uz pomoc operatora<, zbog toga prilikom prosledjivanja imamo * jer je opearator definisan "bool operator<(Putovanje& putovanje)"
				iMin = j;
			}
		}
		if (iMin != i) { //ukoliko ima razlike u odnosu na pocetak vrsi se proces rotiranja
			Putovanje* pom = niz[i];
			niz[i] = niz[iMin];
			niz[iMin] = pom;
		}
	}

	cout << endl;
	cout << "Soritana ponuda putovanja (po ceni rastuce): " << endl;
	for (int i = 0; i < 6; i++) {
		niz[i]->prikaz(); //ponovo prolazimo kroz ceo niz i prikazujemo sve elemente niza, ovog puta urednjenog, uz pomoc metode za prikaz
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		delete niz[i]; //prolazimo kroz ceo niz i brisemo elemente smestene u dinamickoj zoni memorije
	}
	return 0;

}
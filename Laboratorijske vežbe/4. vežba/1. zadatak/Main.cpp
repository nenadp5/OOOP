#include "Kocka.h"
#include "Piramida.h"
#include <iostream>
using namespace std;
int main() {
	GeometrijskoTelo* niz[5]; //niz od pet pokazivaca na geometrijsko telo
	niz[0] = new Piramida(3, 5);
	niz[1] = new Kocka(3); //na neparnim pozicijama u nizu se kreiraju kocke
	niz[2] = new Piramida(4, 5); //na parnim pozicijama u nizu se kreiraju piramide
	niz[3] = new Kocka(4);
	niz[4] = new Piramida(5, 6);

	cout << endl;
	for (int i = 0; i < 5; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz i svaki element niza prosledjujemo metodi za prikaz
		cout << endl;
	}

	GeometrijskoTelo* Max = niz[0]; //kreiramo pomocnu promenljivu, koja uzima prvi element u nizu i njega smatramo za maksimalnim
	for (int i = 0; i < 5; i++) {
		if(*niz[i]>*Max){ //prolazimo kroz ceo niz, svaki element niza prosledjujemo operatoru> koji ga poredi sa maksimalnim, zato prilikom prosledjivanja imamo * pored naziva
			Max = niz[i];
		}
	}
	cout << endl;
	cout << "Najvece geometrijsko telo je: " << endl;
	Max->prikaz(); //pomocnu promenljivu prosledjujemo metodi za prikaz

	for (int i = 0; i < 5; i++) {
		delete niz[i]; //prolazimo kroz ceo niz i brisemo sve elemente
	}
	return 0;
}
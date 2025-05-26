#include "Kolekcija.h"
#include <iostream>
using namespace std;

Kolekcija::Kolekcija() {
	this->trBr = 0; //podrazumevani konstruktor koji postavlja vrednosti privatnih atributa na 0
}

void Kolekcija::dodaj(KompleksniBroj* broj) { //metoda koja dodaje kompleksni broj u niz
	if (this->trBr < 100) { //proveravamo da li ima mesta u nizu
		niz[trBr] = broj; //ukoliko ima mesta dodajemo prosledjeni kompleksni broj i povecavamo brojac
		trBr++;
	}
	else {
		cout << "Greska! Niz je popunjen! "; //ukoliko je niz popunjen onda ipisujemo poruku
	}
}

void Kolekcija::sort() { //standardna metoda za sortiranje koju smo imali dosta puta do sada
	for (int i = 0; i < trBr - 1; i++) {
		int iMin = i; //kreiramo promenljivu koja uzima vrednost trenutnog elementa kao najmanjeg
		for (int j = i + 1; j < trBr; j++) { //ispred trenutne promenljive prolazi brojac
			if (*niz[iMin] > *niz[j]) { //poredimo vrednosti trenutnog najmanjeg broja i brojaca koji ide ispred, poredjenje se obavlja uz pomoc operatora> i zbog toga prosledjujemo * kod vrednosti
				iMin = j; //izvrsi se zamena ukoliko je to potrebno
			}
		}
		if (iMin != i) { //ukoliko se novokreirana promenljiva razlikuje u odnosu na pocetak znaci da je doslo do izmena i onda je potrebno da se izvrsi sortiranje
			KompleksniBroj* pom = niz[iMin]; //kreiramo pomocnu promenljivu tipa KompleksniBroj koja pomaze u procesu rotacije
			niz[iMin] = niz[i]; //prilikom izmene, menjaju se svi prateci elementi jednog kompleksnog broja
			niz[i] = pom;

		}
	}
}

void Kolekcija::prikaz(){ //metoda za prikaz
	for (int i = 0; i < trBr; i++) {
		niz[i]->prikaz(); //ceo niz i svaki element tog niza prosledjujemo metodi za prikazivanje
		cout << endl;
	}
}
#include "Konkurs.h"
#include "Student.h"
#include <iostream>;
using namespace std;

Konkurs::Konkurs() {
	this->trBr = 0; //podrazumevani konstruktor koji postavlja vrednosti na 0
}

Konkurs::~Konkurs() {
	for (int i = 0; i < trBr; i++) {
		delete niz[i]; //destruktor koji brise svaki element niza posebno
	}
}

void Konkurs::dodajStudenta(Student* s) { //metoda koja dodaje prosledjenog studenta u niz, prosledjuje se pokazivac i zato imamo *
	if (trBr < 100) { //proveravamo zbog uslova
		niz[trBr] = s; //ukoliko ima mesta dodajemo studenta i povecavamo trenutni broj studenata
		trBr++;
	}
	else {
		cout << "Mesta su popunjena! " << endl; //u suprotnom ispisujemo poruku
	}
}

void Konkurs::sortiraj() {
	for (int i = 0; i < trBr - 1; i++) {
		int iMax = i; //pomocna promenljiva koja trenutnog elementa smatra maksimalnim
		for (int j = i + 1; j < trBr; j++) { //brojac koji ide ispred trenutne vrednost i vrsi poredjenje sa maksimalnom vrednoscu
			if (*niz[iMax]<*niz[j]) { //vrednosti se prosledjuju sa * jer ovde glavnu ulogu igra operator< (bool operator<(Student& s))
				iMax = j; //ukoliko naidje veci element onda se vrsi zamena
			}
		}
		if (iMax != i) { //ukoliko se vrednosti razlikuju od pocetnih onda se vrsi standardni proces rotacije
			Student* pom = niz[iMax];
			niz[iMax] = niz[i];
			niz[i] = pom;
		}
	}
}

void Konkurs::prikaz() {
	for (int i = 0; i < trBr; i++) {
		niz[i]->prikaz(); //metoda za prikaz, gde svakog studenta prosledjujemo metodi za prikaz iz klase "Student"
	}
}
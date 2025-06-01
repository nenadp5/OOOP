#include "FudbalskiKlub.h"
#include <iostream>
#include <cstring>
using namespace std;

FudbalskiKlub::FudbalskiKlub(const char* naziv, int* niz, int maxBr, int trBr) { //konstruktor koji postavlja prosledjene vrednosti
	int duzina = strlen(naziv) + 1; //brojimo koliko elemenata ce zauzeti naziv u dinamickoj zoni memorije
	this->naziv = new char[duzina]; //vrsimo dinamicku alokaciju
	strcpy_s(this->naziv, duzina, naziv); //upisujemo vrednost

	this->maxBr = maxBr; //dodeljujemo prosledjene vrednosti
	this->trBr = trBr;

	this->niz = new int[maxBr]; //kreiramo niz u dinamickoj zoni memorije
	for (int i = 0; i < this->trBr; i++) {
		this -> niz[i] = niz[i]; //upisuju se vrednosti redom u niz
	}
}

FudbalskiKlub::FudbalskiKlub() {
	this->maxBr = 0; //podrazumevani konstruktor koji postavlja vrednosti privatnih atributa na 0,NULL ili prazno
	this->trBr = 0;
	this->niz = NULL;

	this->naziv = new char[1];
	strcpy_s(this->naziv, 1, "");
}

FudbalskiKlub::FudbalskiKlub(const FudbalskiKlub& original) { //konstruktor za kopiranje
	int duzina = strlen(original.naziv) + 1;
	this->naziv = new char[duzina];
	strcpy_s(this->naziv, duzina, original.naziv);

	this->maxBr = original.maxBr; //klasicni konstruktor za kopiranje, koji kopira vrednosti prosledjenog Fudbalkog Kluba i dodeljuje drugom
	this->trBr = original.trBr;

	this->niz = new int[maxBr];
	for (int i = 0; i < this->trBr; i++) {
		this->niz[i] = original.niz[i];
	}
}

FudbalskiKlub::~FudbalskiKlub() {
	delete[]naziv; //destruktor koji brise elemente koji su smesteni u dinamickoj zoni memorije
	delete[]niz;
}

void FudbalskiKlub::prikaz() { //metoda za prikaz
	cout << "Fudbalski klub: " << this->naziv << endl; //ispisujemo naziv kluba
	cout << "Ostvario je sledeci niz rezultata (za pobedu se upisuje 3, neresen rezultat 1 i za poraz 0 bodova): ";
	for (int i = 0; i < this->trBr; i++) {
		cout << this->niz[i] << " "; //ispisujemo rezultate kluba redom
	}
	cout << endl;
	cout << "Klub je ukupno osvojio: " << ukupnoBodova() << " bodova" << endl; //pozivamo metodu koja racuna ukupan broj bodova koje je klub osvojio i to ispisujemo
	cout << "Maksimalni broj rezultata: " << maxBr << endl; //ispisujemo i ostale informacije
	cout << "Trenutni broj rezultata: " << trBr << endl;
}
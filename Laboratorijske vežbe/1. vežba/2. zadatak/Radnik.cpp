#include "Radnik.h"
#include <iostream>
#include <cstring>
using namespace std;
float Radnik::zaradaPoSatu; //definisemo staticki atribut klase

Radnik::Radnik(const char* ime, const char* prezime, float* niz, int maxBr, int trBr) {
	int duzina = strlen(ime) + 1; //brojimo koliko elemenata ce zauzeti parametar "ime" u memoriji
	this->ime = new char[duzina]; //vrsi se dinamicka alokacije, gde parametar "ime" zauzima onoliko mesta koliko je prethondo izbrojano
	strcpy_s(this->ime, duzina, ime); //kopiramo vrednosti

	duzina = strlen(prezime) + 1; //brojimo koliko elemenata ce zauzeti parametar "prezime" u memoriji
	this->prezime = new char[duzina]; //vrsi se dinamicka alokacije, gde parametar "prezime" zauzima onoliko mesta koliko je prethondo izbrojano
	strcpy_s(this->prezime, duzina, prezime); //kopiramo vrednosti

	this->maxBr = maxBr; //dodeljujemo prosledjene vrednosti
	this->trBr = trBr;

	this->niz = new float[maxBr]; //vrsi se dinamicka alokacija memorije za parametar niz
	for (int i = 0; i < this->trBr; i++) {
		this->niz[i] = niz[i]; //upisujemo vrednosti u niz
	}
}

Radnik::Radnik() { //podrazumevani konstruktor koji postavlja vrednosti atributa na 0, NULL ili prazno u zavisnosti od slucaja
	this->ime = new char[1];
	strcpy_s(this->ime, 1, "");
	this->prezime = new char[1];
	strcpy_s(this->prezime, 1, "");
	this->niz = NULL;
	this->maxBr = 0;
	this->trBr = 0;
}

Radnik::Radnik(const Radnik& original) { //konstruktor koji obavlja kopiranje, tako sto se novoformiranoj vrednosti dodele vrednosti prosledjenog elementa
	int duzina = strlen(original.ime) + 1;
	this->ime = new char[duzina];
	strcpy_s(this->ime, duzina, original.ime);

	duzina = strlen(original.prezime) + 1;
	this->prezime = new char[duzina];
	strcpy_s(this->prezime, duzina, original.prezime);

	this->maxBr = original.maxBr;
	this->trBr = original.trBr;

	this->niz = new float[maxBr];
	for (int i = 0; i < this->trBr; i++) {
		this->niz[i] = original.niz[i];
	}
}

Radnik::~Radnik() { //destruktor koji brise elemente koji su smesteni u dinamickoj zoni memorije
	delete[]ime;
	delete[]prezime;
	delete[]niz;
}

float Radnik::ukupnaZarada() { //metoda koja racuna ukupnu zaradu radnika
	float zarada = 0; //pomocna promenljiva
	for (int i = 0; i < this->trBr; i++) {
		zarada += niz[i] * Radnik::zaradaPoSatu; //prolazimo kroz ceo niz i mnozimo sate radnika sa statickim atributom (odnosno zaradom po satu)
	}
	return zarada; //vracamo realni tip promenljive
}

void Radnik::prikaz() { //metoda za ispis gde ispisujemo sve informacije vezane za radnika
	cout << "Radnik: " << this->ime << " " << this->prezime << endl;
	cout << "Koji ima za sada radnih sati u mesecu: ";
	for (int i = 0; i < trBr; i++) {
		cout << this->niz[i] << " ";
	}
	cout << endl;
	cout << "Ciji radni sat iznosi: " << Radnik::zaradaPoSatu << endl; //ispisujemo staticki atribut
	cout << "Od ukupno radnik dana u mesecu: " << this->maxBr << endl;
	cout << "Trenutno ima odradjenih: " << this->trBr << " dana" << endl;
	cout << "Njegova zarada iznosi: " << ukupnaZarada() << endl; //pozivamo metodu za racunanje zarade i ispisujemo njen rezultat
}


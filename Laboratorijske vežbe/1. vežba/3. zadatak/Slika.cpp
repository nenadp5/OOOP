#include <iostream>
#include "Slika.h"
using namespace std;

Slika::Slika(int* Rniz, int* Gniz, int* Bniz, int maxBr, int trBr) { //konstruktor koji postavlja vrednosti
	this->maxBr = maxBr; //postavljamo prosledjene vrednosti
	this->trBr = trBr;

	this->Rniz = new int[maxBr]; //obavlja se dinamicka alokacija niza
	for (int i = 0; i < trBr; i++) {
		this->Rniz[i] = Rniz[i]; //upisuju se elementi u niz
	}
	this->Gniz = new int[maxBr];  //obavlja se dinamicka alokacija niza
	for (int i = 0; i < trBr; i++) {
		this->Gniz[i] = Gniz[i];  //upisuju se elementi u niz
	}
	this->Bniz = new int[maxBr];  //obavlja se dinamicka alokacija niza
	for (int i = 0; i < trBr; i++) {
		this->Bniz[i] = Bniz[i];  //upisuju se elementi u niz
	}
}

Slika::Slika() { //podrazumevani konstruktor koji postavlja vrednosti na 0 ili NULL
	this->maxBr = 0;
	this->trBr = 0;
	this->Rniz = NULL;
	this->Gniz = NULL;
	this->Bniz = NULL;
}

Slika::Slika(const Slika& original) { //konstruktor koji obavlja kopiranje vrednosti prosledjenog elementa
	this->maxBr = original.maxBr;
	this->trBr = original.trBr;

	this->Rniz = new int[maxBr];
	for (int i = 0; i < trBr; i++) {
		this->Rniz[i] = original.Rniz[i];
	}
	this->Gniz = new int[maxBr];
	for (int i = 0; i < trBr; i++) {
		this->Gniz[i] = original.Gniz[i];
	}
	this->Bniz = new int[maxBr];
	for (int i = 0; i < trBr; i++) {
		this->Bniz[i] = original.Bniz[i];
	}
}

Slika::~Slika() { //destruktor koji brise elemente smestene u dinamickoj zoni memorije
	delete[]Rniz;
	delete[]Gniz;
	delete[]Bniz;
}

float Slika::RSrednje() { //metoda koja racuna srednju vrednost crvene boje
	float RSrednje = 0; //pomocna promenljiva
	for (int i = 0; i < this->trBr; i++) {
		RSrednje += Rniz[i]; //prolazimo kroz niz crvene boje i sumiramo elemente
	}
	return RSrednje / this->trBr; //povratna vrednost je tipa float
}

float Slika::GSrednje() { //metoda koja racuna srednju vrednost zelene boje
	float GSrednje = 0; //pomocna promenljiva
	for (int i = 0; i < this->trBr; i++) {
		GSrednje += Gniz[i]; //prolazimo kroz niz zelene boje i sumiramo elemente
	}
	return GSrednje / this->trBr; //povratna vrednost je tipa float
}

float Slika::BSrednje() { //metoda koja racuna srednju vrednost plave boje
	float BSrednje = 0; //pomocna promenljiva
	for (int i = 0; i < this->trBr; i++) {
		BSrednje += Bniz[i]; //prolazimo kroz niz plave boje i sumiramo elemente
	}
	return BSrednje / this->trBr; //povratna vrednost je tipa float
}

float Slika::prebaciUSivu() { //metoda za racunanje sive boje
	return 0.3 * RSrednje() + 0.59 * GSrednje() + 0.11 * BSrednje(); //povratna vrednost je tipa float, i dobijamo je po formuli koja je data u okviru zadatka
}

void Slika::prikaz() {
	cout << "Srednja vrednost unete crvene boje je: " << RSrednje() << endl; //ispisujemo srednje vrednosti boja, tako sto pozivamo metode za to u okviru linije koda gde je cout
	cout << "Srednja vrednost unete zelene boje je: " << GSrednje() << endl;
	cout << "Srednja vrednost unete plave boje je: " << BSrednje() << endl;
	cout << "Transformisana nijansa sive je: " << prebaciUSivu() << endl; //pozivamo metodu za racunanje sive i vrsimo njeno ispisivanje

}
#include "Putovanje.h"
#include <iostream> //ukljucujemo sve neophodne biblioteke za rad i header fajlove
#include <cstring>
using namespace std;

Putovanje::Putovanje(const char* naziv, float trajanje, float cenaSmestaja, float cenaPrevoza) {
	int duzina = strlen(naziv) + 1; //prebrojavamo koliko bajtova ce zauzeti promenljiva naziv, uz pomoc funkcije strlen, na kraju imamo +1 zbor "/0" karaktera na kraju stringa
	this->naziv = new char[duzina]; //vrsimo dinamicku alokaciju memorije
	strcpy_s(this->naziv, duzina, naziv); //dodeljujemo vrednosti

	this->trajanje = trajanje; //dodeljujemo vrednosti atributima
	this->cenaSmestaja = cenaSmestaja;
	this->cenaPrevoza = cenaPrevoza;
}

Putovanje::~Putovanje() {
	delete[]naziv; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
}

void Putovanje::prikaz() {
	cout << "Destinacija: " << this->naziv << endl; //ispisujemo sve neophodne atribute i pozivamo metodu za racunanje cene
	cout << "U trajanju od: " << this->trajanje << endl;
	cout << " Sa cenom smestaja: " << this->cenaSmestaja << " i cenom prevoza: " << this->cenaPrevoza << endl;
	cout << "Ukupno iznosi: " << cena() << " dinara" << endl;
}

bool Putovanje::operator<(Putovanje& putovanje) {
	return this->cena() < putovanje.cena();  //logicki operator koji vraca vrednost TRUE ili FALSE u zavisnosti od rezultata poredjenja
}

//ciste virtuelne funkcije (u ovom slucaju funkcija za racunanje cene) se ne definisu u okviru ovog CPP fajla
//vec imamo obavezu da ih definisemo u okviru svake izvedene klase
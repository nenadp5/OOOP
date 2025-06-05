#include "Radnik.h"
#include <iostream>
#include <cstring>
using namespace std;

Radnik::Radnik() { //podrazumevani konstruktor koji postavlja vrednosti na 0, NULL ili prazno u zavisnosti od slucaja
	this->cenaRadnogSata = 0;
	this->brSati = 0;
	this->ime = new char[1]; //vrsimo dinamicku alokaciju za jedan memorijski element
	strcpy_s(this->ime, 1, ""); //upisujemo praznu vrednost
}

Radnik::Radnik(const char* ime, float cenaRadnogSata, float brSati) {
	int duzina = strlen(ime) + 1; //kreiramo pomocnu promenljivu koja broji kolika je vrednost prosledjenog elementa "ime" u bajtovima kako bi kasnije mogla da se izvrsi dinamicka alokacija
	this->ime = new char[duzina]; //vrsimo dinamicku alokaciju za atribut "ime"
	strcpy_s(this->ime, duzina, ime); //dodeljujemo vrednosti

	this->cenaRadnogSata = cenaRadnogSata;
	this->brSati = brSati; //dodeljujemo vrednosti
}

Radnik::~Radnik() {
	delete[]ime; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
}

float Radnik::plata() {
	return this->cenaRadnogSata * this->brSati; //metoda za racunanje plate, povratna vrednost je tipa float
}

void Radnik::prikaz() {
	cout << "Radnik: " << this->ime << endl; //metoda za prikaz, gde pozivamo sve neophodne atribute i metode i vrsimo njihovo prikazivanje
	cout << "Ciji radni sat iznosi: " << this->cenaRadnogSata << endl;
	cout << "A koji ukupno ima: " << this->brSati << " radnih sati" << endl;
	cout << "Ima zaradu od: " << plata() << " dinara" << endl;
}

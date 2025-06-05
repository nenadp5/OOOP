#include "NagradjeniRadnik.h"
#include "Radnik.h"
#include <iostream>
using namespace std;

NagradjeniRadnik::NagradjeniRadnik() {
	this->bonus = 0; //konstruktor koji postavlja vrednost privatnih atributa na 0
}

NagradjeniRadnik::NagradjeniRadnik(const char* ime, float cenaRadnogSata, float brSati, float bonus) :Radnik(ime, cenaRadnogSata, brSati) {
	this->bonus = bonus; //konstruktor koji postavlja prosledjene vrednosti, koristimo i konstruktor klase "Radnik" da bi postavili vrednosti iz te klase
}

NagradjeniRadnik::~NagradjeniRadnik() {} //destruktor koji brise elemente iz dinamicke zone memorije, buduci da nema takvih elemenata u okviru ove klase, onda se obavlja ovakvo definisanje

float NagradjeniRadnik::plata() {
	return Radnik::plata() + this->bonus; //metoda za racunanje plate, pozivamo metodu iz klase "Radnik" i samo dodajemo bonus
}

void NagradjeniRadnik::prikaz() {
	cout << "Radnik: " << this->ime << endl; //metoda za prikaz vrednosti, gde pozivamo sve neophodne atribute i metode i vrsimo njihovo ispisivanje
	cout << "Ciji radni sat iznosi: " << this->cenaRadnogSata << endl;
	cout << "A koji ukupno ima: " << this->brSati << " radnih sati" << endl;
	cout << "Dok mu bonus iznosi: " << this->bonus << " dinara" << endl;
	cout << "Ima zaradu od: " << plata() << " dinara" << endl;
}
#include "Radnik.h"
#include <iostream>
#include <cstring> //ukljucujemo sve neophodne biblioteke
using namespace std;

Radnik::Radnik(const char* ime, const char* prezime) {
	int duzina = strlen(ime) + 1; //brojimo duzinu parametra "ime" u bajtovima uz pomoc funkcije strlen, na kraju imamo +1 zbog "/0" karaktera na kraju stringa
	this->ime = new char[duzina]; //vrsimo dinamicku alokaciju za atribut "ime", koji ce zauzeti onoliko mesta u memoriji kolika je vrednost promenljive "duzina"
	strcpy_s(this->ime, duzina, ime); //dodeljujemo vrednosti

	duzina = strlen(prezime) + 1; //brojimo duzinu parametra "prezime" u bajtovima uz pomoc funkcije strlen, na kraju imamo +1 zbog "/0" karaktera na kraju stringa
	this->prezime = new char[duzina]; //vrsimo dinamicku alokaciju za atribut "prezime", koji ce zauzeti onoliko mesta u memoriji kolika je vrednost promenljive "duzina"
	strcpy_s(this->prezime, duzina, prezime); //dodeljujemo vrednosti
}

Radnik::~Radnik() {
	delete[] ime; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
	delete[]prezime;
}

bool Radnik::operator>(Radnik& drugi) { //logicki operator koji vraca vrednost TRUE ili FALSE u zavisnosti od rezultata
	return this->IznosPlate() > drugi.IznosPlate(); //pozivamo metodu za racunanje plate za trenutni i prosledjeni objekat i vrsimo njihovo poredjenje
}
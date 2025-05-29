#include "Radnik.h" //ukljcujemo neophodne biblioteke
#include <iostream>
#include <cstring>
using namespace std;

Radnik::Radnik(const char* ime, const char* prezime, int jmbg, float plata, Sef* sef) { //konstruktor za postavljanje vrednosti
	int duzina = strlen(ime) + 1; //brojimo duzinu koliku ce prosledjeni element zauzeti prilikom dinamicke alokacije i to smestamo u pomocnu promenljivu
	this->ime = new char[duzina]; //vrsimo dinamicku alokaciju za parametar ime
	strcpy_s(this->ime, duzina, ime); //kopiramo vrednosti

	duzina = strlen(prezime) + 1; //brojimo duzinu koliku ce prosledjeni element zauzeti prilikom dinamicke alokacije i to smestamo u pomocnu promenljivu
	this->prezime = new char[duzina]; //vrsimo dinamicku alokaciju za parametar prezime
	strcpy_s(this->prezime, duzina, prezime); //kopiramo vrednosti

	this->jmbg = jmbg; //dodeljujemo ostale prosledjene vrednosti
	this->plata = plata;
	this->sef = sef;
}

Radnik::~Radnik() {
	delete[]ime; //destruktor koji brise elemente iz dinamicke zone memorije
	delete[]prezime;
}

bool Radnik::operator==(const Radnik& drugi) {
	return this->jmbg == drugi.jmbg; //operator koji vraca vrednost TRUE ili FALSE u zavisnosti od toga da li se JMBG tekuceg i prosledjenog elementa poklapaju
}

ostream& operator<<(ostream& izlaz, const Radnik& r) { //prijateljska operacija za izlaz i prikaz svih podataka
	izlaz << r.ime << " " << r.prezime << " " << r.jmbg << " " << r.plata << endl;
	return izlaz; //prilikom poziva prosledjujemo vrednost const jer ne treba da menja vrednost elementa
}
#include "Sef.h"
#include "Radnik.h"
#include <iostream>
#include <cstring>
using namespace std;

Sef::Sef(const char* ime, const char* prezime, int jmbg, float plata, const char* titula, Sef* sef) :Radnik(ime, prezime, jmbg, plata, sef) { //uzimamo vrednosti iz klase "Radnik" i dodajemo neophodne
	int duzina = strlen(titula) + 1; //brojimo koliko mesta ce zauzeti prosledjeni element u dinamickoj zoni
	this->titula = new char[duzina]; //vrsimo dinamicku alokaciju
	strcpy_s(this->titula, duzina, titula); //kopiramo elemente
}

Sef::~Sef() {
	delete[]titula; //destruktor koji brise elemente u dinamickoj zoni memorije
}

void Sef::postaviPlatuRadniku(Radnik& r, float novaPlata) {
	r.postaviPlatu(novaPlata); //pozivamo metodu za postavljanje plate i stavljamo novu platu prosledjenom radniku
}

ostream& operator<<(ostream& izlaz, const Sef& sef) {
	izlaz << (Radnik&)sef << " " << sef.titula << endl; 
	return izlaz; //(Radnik&)sef omogucava ispisivanje elemenata koji su prisutni kod bilo kojeg radnika, prilikom cega mi naknadno dodajemo titulu radnika
}
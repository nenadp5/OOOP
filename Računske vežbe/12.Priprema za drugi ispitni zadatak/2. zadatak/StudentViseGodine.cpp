#include "StudentViseGodine.h"
#include "Student.h"
#include <iostream>
using namespace std;

StudentViseGodine::StudentViseGodine(const char* ime, const char* prezime, int indeks, float prosecnaOcena, int godina, int brojIspita) :Student(ime, prezime, indeks) {
	this->prosecnaOcena = prosecnaOcena; //konstruktor za postavljanje vrednosti koji koristi i elemente iz klase "Student" i mi pored toga dodajemo neophodne
	this->godina = godina;
	this->brojIspita = brojIspita;
}

StudentViseGodine::~StudentViseGodine(){} //destruktor

float StudentViseGodine::brojBodova() {
	return 4 * prosecnaOcena + 2 * godina - 2 * brojIspita; //metoda za racunanje broja bodova, funkcija za racunanje je data u okviru teksta zadatka
}
#include "Brucos.h"
#include "Student.h"
#include <iostream>
using namespace std;

Brucos::Brucos(const char* ime, const char* prezime, int indeks, float prosecnaOcenaIzSrednje) :Student(ime, prezime, indeks) {
	this->prosecnaOcenaIzSrednje = prosecnaOcenaIzSrednje; //konstruktor za postavljanje vrednosti, koristimo vrednosti iz klase "Student" i dodajemo neophodne
}

Brucos::~Brucos(){} //destruktor

float Brucos::brojBodova() {
	return 8.0f * prosecnaOcenaIzSrednje; //racunamo broj bodova po formuli koja je data u tekstu zadatka
}
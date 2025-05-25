#include "StudentOsnovnihStudija.h"
#include <iostream>
using namespace std;

StudentOsnovnih::StudentOsnovnih() {
	this->godina = 0; //podrazumevani konstruktor koji postavlja vrednosti atributa na 0
}

StudentOsnovnih::StudentOsnovnih(const char* ime, const char* prezime, int indeks, int maxBrojIspita, int godina) :Student(ime, prezime, indeks, maxBrojIspita) {
	this->godina = godina; //konstruktor za dodelu vrednosti, gde koristimo elemente iz klase "Student.h" i smo dodajemo neophodan podatak vezan za godinu studija
}

StudentOsnovnih::~StudentOsnovnih(){} //destruktor

float StudentOsnovnih::brojIspitaGodisnje() { //metoda za racunanje broja ispita godisnje
	if (this->godina >= 2) {
		return (float)this->brojPolozenihIspita / (float)this->godina; //ukoliko je student presao u drugu godinu, onda racunamo tako sto broj polozenih ispita podelimo sa godinom studija
	}
	else {
		return 0.0f; //ukoliko nije presao onda ispisujemo 0
	}
}

void StudentOsnovnih::prikaz() {
	Student::prikaz(); //pozivamo metodu za prikaz iz klase "Student" i dodajemo informaciju koliko ispita je dao godisnje
	cout << "Ima prosecan broj polozenih ispita po godini: " << brojIspitaGodisnje() << endl;
}
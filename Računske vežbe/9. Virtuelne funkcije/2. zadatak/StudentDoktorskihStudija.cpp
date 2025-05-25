#include "StudentDoktorskihStudija.h" //ukljucujemo sve neophodne biblioteke za rad
#include <iostream>
#include <cstring>
using namespace std;

StudentDoktorskih::StudentDoktorskih() { //podrazumevani konstruktor
	this->oblastIstrazivanja = new char[1]; //kreiramo OblastIstrazivanja u dinamickoj zoni memorije i dajemo samo jedan prostor za smestanje praznog elementa
	strcpy_s(this->oblastIstrazivanja, 1, "");
}

StudentDoktorskih::StudentDoktorskih(const char* ime, const char* prezime, int indeks, int maxBrojIspita, const char* oblastIstrazivanja) :Student(ime, prezime, indeks, maxBrojIspita) {
	int duzina = strlen(oblastIstrazivanja) + 1; //konstruktor za postavljanje vrednosti, gde vecinu vrednosti koristimo iz klase "Student" dok naknadno vrsimo dinamicku alokaciju i smestanje vrednosti za oblast istrazivanja
	this->oblastIstrazivanja = new char[duzina];
	strcpy_s(this->oblastIstrazivanja, duzina, oblastIstrazivanja);
}

StudentDoktorskih::~StudentDoktorskih() {
	delete[]this->oblastIstrazivanja; //destruktor koji brise elemente koji su smesteni u dinamickoj zoni memorije
}

void StudentDoktorskih::postaviOblast(const char* oblastIstrazivanja) { //dodajemo oblast istrazivanja ukoliko to vec nije uradjeno preko konstruktora
	if (this->oblastIstrazivanja != NULL) {
		delete[]this->oblastIstrazivanja; //proveravamo da li je oblast istrazivanja prazna, ukoliko je zauzeta brisemo elemente
	}
	int duzina = strlen(oblastIstrazivanja) + 1; //racunamo koja velicina nam je potrebna za vrsenje dinamicke alokacije i potom obavljamo istu
	this->oblastIstrazivanja = new char[duzina];
	strcpy_s(this->oblastIstrazivanja, duzina, oblastIstrazivanja);
}

void StudentDoktorskih::prikaz() { //metoda za prikaz
	Student::prikaz(); //pozivamo metodu iz klase "Student" i dodajemo neophodnu informaciju vezanu za oblast istrazivanja
	cout << "Izabrao je naucnu oblast " << this->oblastIstrazivanja << endl;
}
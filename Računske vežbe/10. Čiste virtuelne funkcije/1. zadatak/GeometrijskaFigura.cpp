#include "GeometrijskaFigura.h"
#include <iostream>
#include <cstring>
using namespace std;

GeometrijskaFigura::GeometrijskaFigura(const char* naziv) { //konstruktor za postavljanje naziva figure
	int duzina = strlen(naziv) + 1; //brojimo koliko mesta ce zauzeti naziv u dinamickoj zoni memorije
	this->naziv = new char[duzina]; //vrsimo dinamicku alokaciju
	strcpy_s(this->naziv, duzina, naziv); //kopiramo i dodeljujemo vrednosti uz pomoc operacije za rad sa stringovima
}

GeometrijskaFigura::~GeometrijskaFigura() { //destruktor koji brise elemente koji su smesteni u dinamickoj zoni memorije
	delete[]naziv;
}

void GeometrijskaFigura::prikaz() { //metoda za prikaz svih podataka
	cout << "Naziv geometrijske figure: " << this->naziv << endl;
	cout << "Povrsina je: " << this->povrsina() << endl; //pozivamo metode za racunanje obima i povrsine
	cout << "Obim je: " << this->obim() << endl;
}

bool GeometrijskaFigura::operator>(GeometrijskaFigura& figura) { //logicka metoda koja vraca vrednost true ili false u zavisnosti od resenja
	return this->povrsina() > figura.povrsina();
}

/*da se primetiti da nismo definisali nigde ciste virtuelne funkcije za povrsinu i obim,
to je zato sto je neophodno da se one uvedu i definisu u podklasama bez obzira sto to nije trazeno u tekstu zadatka */
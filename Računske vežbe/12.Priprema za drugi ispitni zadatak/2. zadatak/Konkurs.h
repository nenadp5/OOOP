#pragma once
#include "Student.h"
class Konkurs { //klasa "Konkurs" koja nije izvedena iz bilo koje klase, vec samo koristi elemente iz klase "Student"
private:
	Student* niz[100]; //niz pokazivaca na studente
	int trBr;
public:
	Konkurs(); //podrazumevani konstruktor
	~Konkurs(); //destruktor
	
	void dodajStudenta(Student* s); //metoda za dodavanje studenata
	void sortiraj(); //metoda za sortiranje studenata na osnovu broja bodova
	void prikaz(); //metoda za prikaz
};
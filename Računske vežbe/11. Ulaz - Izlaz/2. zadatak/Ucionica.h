#pragma once
#include "Student.h" //ukljucujemo klasu "Student" jer koristimo neke elemente iz te klase
#include <iostream>
#include <fstream> //ukljucujemo metode za rad sa fajlovima i funkcijama istream i ostream
using namespace std;
class Ucionica {
private: //privatni atributi klase
	Student* niz; //niz pokazivaca na objekte klase "Student"
	int brEl; //broj elemenata niza

public:
	Ucionica(); //podrazumevani konstruktor
	Ucionica(int brEl); //konstruktor koji postavlja vrednosti
	~Ucionica(); //destruktor

	void ulazBin(const char* fajlPutanja); //metoda za rad sa binarnim fajlovima, omogucava ucitavanje podataka iz fajla, prosledjena vrednost je naziv samog fajla
	void izlazBin(const char* fajlPutanja); //metoda za rad sa binarnim fajlovima, omogucava ispisivanje podataka u fajl, prosledjena vrednost je naziv samog fajla

	friend ostream& operator<<(ostream& izlaz, const Ucionica& u); //prijateljski operator za ispis podataka
	friend istream& operator>>(istream& ulaz, Ucionica& u); //prijateljski operator za upis podataka
};
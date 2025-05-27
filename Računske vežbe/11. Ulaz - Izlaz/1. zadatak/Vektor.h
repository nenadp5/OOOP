#pragma once
#include <iostream> //ukljcujemo zbog prisustva funkcija istream i ostream
#include <fstream> //ukljucujemo biblioteku koja poseduje funkcije za rad sa fajlovima
using namespace std;
class Vektor { //kreiramo klasu "Vektor"
private: //privatni atributi
	int* niz; //niz celobrojnih elemenata u dinamickoj zoni memorije
	int brEl; //broj elemenata samog niza

public:
	Vektor(); //podrazumevani konstruktor
	Vektor(int brEl); //konstruktor koji postavlja vrednosti
	~Vektor(); //destruktor

	void ulazTxt(const char* fajlPutanja); //metoda za rad sa tekstualnim fajlom, ucitavanje podataka iz fajla, prosledjena vrednost je naziv fajla odakle se citaju podaci
	void izlazTxt(const char* fajlPutanja); //metoda za rad sa tekstualnim fajlom, upis podataka u fajl, prosledjena vrednost je naziv fajla gde se upisuju podaci

	void ulazBin(const char* fajlPutanja); //metoda za rad sa binarnim fajlom, ucitavanje podataka iz fajla, prosledjena vrednost je naziv fajla odakle se citaju podaci
	void izlazBin(const char* fajlPutanja); //metoda za rad sa binarnim fajlom, upis podataka u fajl, prosledjena vrednost je naziv fajla gde se upisuju podaci

	friend ostream& operator<<(ostream& izlaz, const Vektor& v); //prijateljski operator za ispis
	friend istream& operator>>(istream& ulaz, Vektor& v); //prijateljski operator za upis
};

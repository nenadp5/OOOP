#pragma once
#include "Film.h" //ukljucujemo header fajl "Film" jer koristimo elemente iz te klase
#include <iostream>
using namespace std;
class Bioskop {
private:
	Film* filmovi[20]; //niz pokazivaca na filmove (ima ih 20 jer se toliko filmova moze emitovati u toku dana)
	char* naziv; //naziv bioskopa koji smo smestili u dinamicku zonu memorije
	int trBr; //trenutni broj filmova

public:
	Bioskop(); //podrazumevani konstruktor
	Bioskop(const char* naziv); //konstruktor za postavljanje naziva
	~Bioskop(); //destruktor
	
	Bioskop& operator+(Film& film); //operator koji dodaje film u bioskop
	
	float prosecnoTrajanje(); //metoda za racunanje prosecnog trajanja filmova u bioskopu 
	void sort(); //metoda za sortiranje
	Film& najduzi() const; //metoda koja vraca najduzi film u bioskopu, povratna vrednost je Film pa je zato i koriscen u definisanju

	friend ostream& operator<< (ostream& izlaz, const Bioskop& b); //prijateljska operatorska funkcija za prikaz
};
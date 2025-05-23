#pragma once
#include "Automobil.h" //ukljucujemo i klasu "Automobil" jer koristimo elemente i metode iz te klase
#include <iostream>
using namespace std;
class Parking {
private: //privatni atributi klase Parking
	char adresa[30]; //nije receno da adresa treba da bude smestena u dinamickoj zoni, pa smo je ipak stavili u staticki deo memorije
	Automobil* Automobili[50]; //niz pokazivaca na objekte tipa automobil, ima ih ukupno 50 jer ima toliko mesta na parkingu
	int trBr;

public:
	Parking(); //podrazumevani konstruktor
	Parking(const char* adresa); //konstruktor koji postavlja adresu
	~Parking() //destruktor
	
	Parking& operator+=(Automobil& a); //operatorska funkcija za dodavanje automobila na parking
	int brojNovijih(int godina); //metoda za odredjivanje broja novijih automobila u odnosu na prosledjenu godinu
	
	Automobil* najskuplji() const; //metoda koja odredjuje najskuplji automobil, zato je i tipa Automobil* jer treba da vrati vrednost Automobila, a to smo realizovali uz pomoc pokazivaca

	friend ostream& operator<<(ostream& izlaz, const Parking& p); //operatorska funkcija za prikaz svih informacija o parkingu
};

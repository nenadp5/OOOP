#pragma once
#include "Lekar.h" //ukljucujemo sve neophodne biblioteke i header fajlove za rad
#include <iostream>
using namespace std;
class Klinika { //kreiramo klasu "Klinika" koja nije izvedena iz klase "Lekar" ali koristi njene elemente
private: //privatni atributi klase
	char naziv[20]; //naziv klinike smesten u statickoj zoni memorije
	int brLekara;
	Lekar* niz; //niz lekara, koji smo realizovali kao pokazivac na Lekare
public:
	Klinika(); //podrazumevani konstruktor
	virtual ~Klinika(); //virtuelni destruktor
	
	void ulazTxt(const char* fajlPutanja); //metoda za ucitavanje podataka iz tekstualnog fajla, prosledjuje se naziv fajla 
	void izlazTxt(const char* fajlPutanja); //metoda za upis podataka u tekstualni fajl, prosledjuje se naziv fajla
	void ulazBin(const char* fajlPutanja); //metoda za ucitavanje podataka iz binarnog fajla, prosledjeni parametar je naziv fajla
	void izlazBin(const char* fajlPutanja); //metoda za upis podataka u binarni fajla, prosledjuje se naziv fajla
	
	friend ostream& operator<<(ostream& izlaz, const Klinika& k); //prijateljska operatorska funkcija za prikaz podataka
	friend istream& operator>>(istream& ulaz, Klinika& k); //prijateljska operatorska funkcija za unos podataka
};
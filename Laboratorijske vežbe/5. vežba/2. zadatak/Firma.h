#pragma once
#include "Radnik.h"
#include <iostream>
#include <fstream> //ukljucujemo sve neophodne biblioteke i header fajlove za rad
using namespace std;
class Firma { //kreiramo klasu "Firma" koja nije izvedena iz klase "Radnik" ali koristi njene elemente
private: //privatni atributi klase
	char naziv[20]; //naziv firme smesten u statickoj zoni memorije
	int brRadnika;
	Radnik* niz; //niz radnika, koji smo realizovali kao pokazivac na radnike
public:
	Firma(); //podrazumevani konstruktor
	virtual ~Firma(); //virtuelni destruktor
	
	void ulazTxt(const char* fajlPutanja);  //metoda za ucitavanje podataka iz tekstualnog fajla, prosledjuje se naziv fajla
	void izlazTxt(const char* fajlPutanja); //metoda za upis podataka u tekstualni fajl, prosledjuje se naziv fajla
	void ulazBin(const char* fajlPutanja); //metoda za ucitavanje podataka iz binarnog fajla, prosledjeni parametar je naziv
	void izlazBin(const char* fajlPutanja); //metoda za upis podataka u binarni fajla, prosledjuje se naziv fajla

	friend ostream& operator<<(ostream& izlaz, const Firma& f); //prijateljska operatorska funkcija za prikaz podataka
	friend istream& operator>>(istream& ulaz, Firma& f); //prijateljska operatorska funkcija za unos podataka
};
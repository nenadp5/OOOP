#pragma once
#include "Proizvod.h" //ukljucujemo sve neophodne biblioteke i header fajlove za rad
#include <iostream>
#include <fstream>
using namespace std;
class Prodavnica { //kreiramo klasu "Prodavnica" koja nije izvedena iz klase "Proizvod" ali koristi njene elemente
private: //privatni atributi klase
	char nazivProdavnice[20]; //naziv prodavnice smesten u statickoj zoni memorije
	int brojProizvoda;
	Proizvod* niz; //niz proizvoda, koji smo realizovali kao pokazivac na proizvode
public:
	Prodavnica(); //podrazumevani konstruktor
	~Prodavnica(); //destruktor
	
	void ulazBin(const char* fajlPutanja); //metoda za ucitavanje podataka iz binarnog fajla, prosledjeni parametar je naziv fajla
	void izlazBin(const char* fajlPutanja); //metoda za upis podataka u binarni fajla, prosledjuje se naziv fajla
	void ulazTxt(const char* fajlPutanja); //metoda za ucitavanje podataka iz tekstualnog fajla, prosledjuje se naziv fajla
	void izlazTxt(const char* fajlPutanja); //metoda za upis podataka u tekstualni fajl, prosledjuje se naziv fajla
	
	friend ostream& operator<<(ostream& izlaz, const Prodavnica& p); //prijateljska operatorska funkcija za prikaz podataka
	friend istream& operator>>(istream& ulaz, Prodavnica& p); //prijateljska operatorska funkcija za unos podataka
};
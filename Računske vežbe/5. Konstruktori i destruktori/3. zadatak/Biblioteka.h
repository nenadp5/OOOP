#pragma once
#include "Knjiga.h" //moramo ukljuciti klasu Knjiga jer klasa Biblioteka poseduje neke elemente iz te klase
class Biblioteka {
private:
	Knjiga* niz[100]; //niz od 100 pokazivaca na knjige
	int trBr; //trenutni broj knjiga
public:
	Biblioteka(); //podrazumevani konstruktor
	~Biblioteka(); //destruktor
	void dodaj(Knjiga& k); //metoda za dodavanje knjiga u biblioteku
	void prikaz(); //metoda za prikaz
	void uredi(); //metoda za uredjivanje biblioteke
};
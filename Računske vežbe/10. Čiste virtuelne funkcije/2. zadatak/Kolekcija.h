#pragma once
#include "KompleksniBroj.h"
#include "DekartovKompleksniBroj.h"
#include "PolarniKompleksniBroj.h"
class Kolekcija { //kreiramo klasu "Kolekcija", koja nije izvedena iz ostalih klasa
private: //privatni atributi klase
	KompleksniBroj* niz[100]; //niz pokazivaca na kompleksne brojeve
	int trBr; //trenutni broj elemenata u nizu

public: //javni atributi klase
	Kolekcija(); //podrazumevani konstruktor

	void dodaj(KompleksniBroj* broj); //metoda koja dodaje kompleksni broj u niz, u pitanju je rad sa pokazivacima kako se ne bi pravile bespotrebne kopije
	void sort(); //metoda za sortiranje kompleksnih brojeva
	void prikaz(); //metoda za prikaz
};
#include "CrtaniFilm.h"
#include <iostream>
using namespace std;

CrtaniFilm::CrtaniFilm() { //podrazumevani konstruktor koji postavlja vrednosti privatnih atributa na podrazumevanu vrednost sto je u ovom slucaju 0
	this->brojDece = 0;
	this->popust = 0;
}

CrtaniFilm::CrtaniFilm(const char* naslov, int brojGledalaca, float cena, int brojDece, float popust) : Film(naslov,brojGledalaca,cena) {
	this->brojDece = brojDece; //konstruktor za postavljanje prosledjenih vrednosti, gde vrednosti za naslov, broj gledalaca i cenu uzimamo od klase Film i njenog konstruktora
	this->popust = popust;
}

CrtaniFilm::~CrtaniFilm(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije, ovde nemamo takve elemente pa shodno tome destruktor izgleda ovako

float CrtaniFilm::prihod() { //metoda koja racuna prihod
	return ((this->brojGledalaca-this->brojDece)*this->cena + (this->cena * (1 - this->popust)) * this->brojDece); //matematicka formula za racunanje prihoda kada imamo i decu koja su gledali crtani film
}

void CrtaniFilm::prikaz() { ///metoda za prikaz vrednosti
	cout << "Film pod nazivom: " << this->naslov << endl; //ispisujemo naziv filma
	cout << "Cija cena karte iznosi: " << this->cena << " pri cemu popust za decu iznosi: " << this->popust<< endl; //ispisujemo cenu i popust ukoliko ga ima
	cout << "Ostvario je prihod: " << prihod() << endl; //ispisujemo prihod tako sto pozivamo metodu za to
}
#include "Film.h" //ukljucujemo neophodne biblioteke za rad
#include <iostream>
#include <cstring> //ukljucujemo biblioteku za rad sa stringovima
using namespace std;

Film::Film(const char* naslov, int brojGledalaca, float cena) {
	this->naslov = new char[strlen(naslov) + 1]; //vrsimo dinamicku alokaciju za naslov, koja ce zauzeti onoliko mesta u memoriji koliko zauzima sam naslov, to smo postigli koriscenjem funkcije strlen
	strcpy_s(this->naslov, strlen(naslov) + 1, naslov); //vrsimo dodelu prosledjene vrednosti
	this->brojGledalaca = brojGledalaca; //dodeljujemo prosledjene vrednosti
	this->cena = cena;
}

Film::Film() { //podrazumevani konstruktor koji postavlja vrednosti na 0, NULL ili prazno u zavisnosti od tipa promenljive
	this->naslov = new char[1]; //vrsimo dinamicku alokaciju za samo jedan element
	strcpy_s(this->naslov, 1, ""); //upisujemo praznu vrednost
	this->brojGledalaca = 0; //upisujemo podrazumevanu vrednost koja je u ovom slucaju 0
	this->cena = 0;
}

Film::~Film() { //destruktor koji brise elemente koji su smesteni u dinamickoj zoni memorije
	delete[]naslov;
}

float Film::prihod() { //metoda koja racuna prikaz
	return (this->brojGledalaca * this->cena); //samo pomnozimo broj gledalaca sa cenom karte
}
#include "Automobil.h" //ukljucujemo neophodne biblioteke i header fajlove
#include <iostream>
#include <cstring>
using namespace std;

Automobil::Automobil(const char* naziv, int godina, float cena) { //konstruktor za postavljanje vrednosti
	strcpy_s(this->naziv, naziv); //nema potrebe za racunanjem duzine naziva, jer je smesten u staticki deo memorije
	this->godina = godina;
	this->cena = cena;
}

Automobil::~Automobil(){}//destruktor, iako nije receno u tekstu, nista ne skodi da imamo prisutan i destruktor

ostream& operator<<(ostream& izlaz, const Automobil& a) { //prijateljska operatorska funkcija za izlaz i prikaz svih podataka
	izlaz << a.naziv << " Godiste:" << a.godina << " Cena:" << a.cena << endl;
	return izlaz;
}
//da se primetiti da operatorska funkcija << (ostream& operator<<) uvek izgleda slicno, samo sto nekad unutar nje moze biti prisutna i neka petlja zavisno od zadatka, tako da ceo ovaj operator mozemo zapamtiti kao jedan sablon
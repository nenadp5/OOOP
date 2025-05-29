#pragma once
#include "Radnik.h"
#include "Sef.h"
class Firma {
private: //privatni atributi klase "Firma"
	Radnik* niz[100]; //niz radnih mesta
	int n; //broj radnih mesta

public:
	Firma(); //konstruktor koji postavlja vrednosti
	void dodajRadnika(Radnik& r); //metoda za dodavanje radnika
	Radnik* maxPlata(Sef& sef); //metoda koja nalazi radnika sa najvecom platom pod komandom prosledjenog sefa
	Radnik* direktor(); //metoda koja nalazi direktora
	float zbir(); //metoda koja racuna zbir svih plata
};

//kod metoda "maxPlata" i "direktor" trebamo imati sve informacije o dobijenim vrednosti (ime,prezime,jmbg...) i zbog toga nam je povratna vrednosti tipa Radnik*
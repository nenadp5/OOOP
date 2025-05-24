#include "Kamion.h"
#include <iostream>
using namespace std;

Kamion::Kamion(float nosivost) { //konstruktor koji postavlja vrednosti
	this->nosivost = nosivost;
	this->masaTereta = 0;
}

void Kamion::dodajTeret(float masa) { //metoda za dodavanje tereta
	if (this->masaTereta + masa < this->nosivost) { //proveravamo da li mozemo dodati tu trazenu masu
		cout << "Dodajemo zeljenu masu..." << endl;
		this->masaTereta += masa; //uvecavamo masu tereta i ispisujemo odgavarajucu poruku
		cout << "Trenutna tezina tereta je: " << this->masaTereta << endl;
	}
	else { //ukoliko ne mozemo da dodamo teret ispisujemo poruku
		cout << "Nije moguce dodati zeljenu masu jer prelazi granice nosivosti!";
	}
}

void Kamion::ukloniTeret(float masa) { //metoda za uklanjanje tereta
	if (this->masaTereta - masa > 0) { //proveravamo da li mozemo da uklonimo tu masu
		cout << "Uklanjamo masu tereta..." << endl;
		this->masaTereta -= masa; //uklanjamo tu masu i ispisujemo odgovarajucu poruku
		cout << "Trenutna tezina tereta je: " << this->masaTereta << endl;
	}
	else { //ukoliko uslovi nisu realni, onda ispisujemo poruku
		cout << "Nije moguce ukloniti trenutnu masu jer prelazi granice normalnih vrednosti ";
	}
}
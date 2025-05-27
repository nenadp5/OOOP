#include "Ucionica.h"
#include "Student.h"
#include <iostream>
#include <fstream> //ukljucujemo sve neophodne biblioteke i header fajlove
using namespace std;

Ucionica::Ucionica() {
	this->brEl = 0; //podrazumevani konstruktor koji postavlja vrednost atributa na 0
}

Ucionica::Ucionica(int brEl) {
	this->brEl = brEl; //konstruktor koji postavlja vrednosti
	this->niz = new Student[brEl]; //obavlja dinamicku alokaciju
}

Ucionica::~Ucionica() {
	delete[]niz; //destruktor koji brise elemente iz dinamicke zone memorije
}

void Ucionica::ulazBin(const char* fajlPutanja) { //metoda za ucitavanje podatak iz binarnog fajla
	ifstream ulaz(fajlPutanja, ios::binary); //otvaramo fajl za ucitavanje podataka (ifstream) i naglasavamo da je rec o binarnom fajlu
	if (ulaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		ulaz.read((char*)&brEl, sizeof(brEl)); //ucitavamo prvi element iz fajla, vrsimo transformaciju u char zato sto .read i .write uvek ocekuju promenljivu tipa char
		if (niz != NULL) {
			delete[]niz; //ukoliko niz vec poseduje neke elemente, obavlja se njihovo brisanje
		}
		niz = new Student[brEl]; //obavlja se dinamicka alokacija na osnovu procitanog elementa
		for (int i = 0; i < brEl; i++) {
			ulaz.read((char*)&niz[i], sizeof(niz[i])); //nakon toga se obavlja ucitavanje svih elemenata iz fajla i ponovo je prisutna transformacija u tip char
		}
	}
	ulaz.close(); //obavezno zatvaranje fajla
}

void Ucionica::izlazBin(const char* fajlPutanja) { //metoda za upis podataka u prosledjeni fajl
	ofstream izlaz(fajlPutanja, ios::binary); //otvaramo fajl za upis u njega (ofstream) i nagovestavamo da je rec o binarnom fajlu (ios::binary)
	if (izlaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		izlaz.write((char*)&brEl, sizeof(brEl)); //prvo se ispisuje broj elementa, prisutna je transformacija u format char, zato sto .read i .write uvek ocekuju taj format
		for (int i = 0; i < brEl; i++) {
			izlaz.write((char*)&niz[i], sizeof(niz[i])); //sledi ispisivanje svih elemenata u fajl
		}
	}
	izlaz.close();//i na kraju obavezno zatvaranje fajla
}

ostream& operator<<(ostream& izlaz, const Ucionica& u) { //prijateljska operacija za ispis podataka
	izlaz << u.brEl << endl; //prvo ispisujemo broj elemenata niza
	for (int i = 0; i < u.brEl; i++) {
		izlaz << u.niz[i] << endl; //nakon toga ispisujemo elemente niza
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Ucionica& u) { //prijateljska operacija za upis podataka
	ulaz >> u.brEl; //prvo ucitavamo broj elemenata niza
	if (u.niz != NULL) {
		delete[]u.niz; //nakon toga ukoliko je niz zauzet vrsimo njegovo brisanje
	}
	u.niz = new Student[u.brEl]; //kreiramo novi niz u dinamickoj zoni memorije
	for (int i = 0; i < u.brEl; i++) {
		ulaz >> u.niz[i]; //upisujemo sve elemente
	}
	return ulaz;
}
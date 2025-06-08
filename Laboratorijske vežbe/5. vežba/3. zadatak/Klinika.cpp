#include "Klinika.h"
#include <iostream>
#include <fstream>
#include <cstring> //ukljucujemo sve neophodne biblioteke za rad sa stringovima, fajlovima i standardnim ulazom i izlazom
using namespace std;

Klinika::Klinika() { //podrazumevani konstruktor koji postavlja vrednosti na 0, NULL ili prazno u zavisnosti od slucaja
	strcpy_s(this->naziv, "");
	this->niz = NULL;
	this->brLekara = 0;
}

Klinika::~Klinika() {
	delete[]niz; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
}

void Klinika::ulazTxt(const char* fajlPutanja) {
	ifstream ulaz(fajlPutanja); //otvaramo fajl za ucitavanje podataka iz tekstualnog fajla, sto nam omogucava funkcija "ifstream"
	if (ulaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		if (niz != NULL) {
			delete[]niz; //ukoliko je niz zauzet brisu se vrednosti odatle, kako bi mogle da se upisu nove
		}
		ulaz >> naziv; //ucitavamo naziv lekara
		ulaz >> brLekara; //ucitavamo broj lekara
		this->niz = new Lekar[brLekara]; //vrsimo dinamicku alokaciju za niz lekara
		for (int i = 0; i < brLekara; i++) {
			ulaz >> niz[i]; //prolazimo kroz ceo niz i ucitavamo sve elemente
		}
	}
	ulaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Klinika::izlazTxt(const char* fajlPutanja) {
	ofstream izlaz(fajlPutanja); //otvaramo fajl za upis podataka u tekstualni fajl, to nam omogucava funkcija "ofstream", prosledjeni element je sam naziv fajla
	izlaz << naziv << endl; //upisujemo sve elemente vezane za kliniku
	izlaz << brLekara << endl;
	for (int i = 0; i < brLekara; i++) {
		izlaz << niz[i]; //prolazimo kroz ceo niz i upisujemo sve podatke o lekarima u tekstualni fajl
	}
	izlaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Klinika::ulazBin(const char* fajlPutanja) {
	ifstream ulaz(fajlPutanja, ios::binary); //otvaramo fajl za ucitavanje podataka iz binarnog fajla, to smo postigli uz pomoc funkcije "ifstream" i nagovestaja "ios::binary" da se radi o binarnom fajlu
	if (ulaz) { //ukoliko je ulaz uspesno otvoren obavljaju se sledece funkcije
		if (niz != NULL) {
			delete[]niz; //ukoliko je parametar niz zauzet, vrsimo brisanje te vrednosti, radi kreiranja mesta za novi upis
		}
		ulaz.read((char*)&naziv, sizeof(naziv)); //ucitavamo podatak vezan za naziv klinike, imamo pretvaranje char* jer funkcija read/write uvek ocekuje parametar char
		ulaz.read((char*)&brLekara, sizeof(brLekara)); //imamo funkciju sizeof kako bi se zauzeo odgovarajuci broj mesta
		this->niz = new Lekar[brLekara]; //vrsimo dinamicku alokaciju za niz
		for (int i = 0; i < brLekara; i++) {
			ulaz.read((char*)&niz[i], sizeof(niz[i])); //prolazimo kroz ceo niz i ucitavamo sve elemetne iz binarnog fajla, takodje imamo i pretvaranje u tip char
		}
	}
	ulaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Klinika::izlazBin(const char* fajlPutanja) {
	ofstream izlaz(fajlPutanja, ios::binary); //otvaramo fajl za upisivanje podataka u binarni fajla, to smo postigli uz pomoc funkcije "ofstream" i nagovestaja "ios::binary" da se radi o binarnom fajlu
	izlaz.write((char*)&naziv, sizeof(naziv)); //upisujemo podatak vezan za naziv klinike, imamo pretvaranje char* jer funkcija read/write uvek ocekuje parametar char
	izlaz.write((char*)&brLekara, sizeof(brLekara));
	for (int i = 0; i < brLekara; i++) {
		izlaz.write((char*)&niz[i], sizeof(niz[i])); //prolazimo kroz ceo niz i upisujemo sve elemetne u binarni fajl, takodje imamo i pretvaranje u tip char
	}
	izlaz.close(); //zatvaramo prethodno otvoreni fajl
}

ostream& operator<<(ostream& izlaz, const Klinika& k) {
	izlaz << k.naziv << endl; //operator za prikaz podataka vezanih za kliniku, prosledjuje se sa parametrom const, jer ne treba da menja objekat
	izlaz << k.brLekara << endl;
	for (int i = 0; i < k.brLekara; i++) {
		izlaz << k.niz[i]; 
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Klinika& k) { //operator za unos podataka vezanih za kliniku, nemamo parametara const jer se vrse izmene objekta
	if (k.niz != NULL) {
		delete[]k.niz; //ukoliko je parametar niz zauzet, onda se vrsi brisanje sadrzaja tog parametra, kako bi se omogucio upis novih
	}
	ulaz >> k.naziv; //ucitavamo podatke redom
	ulaz >> k.brLekara;
	k.niz = new Lekar[k.brLekara]; //vrsimo dinamicku alokaciju za niz lekara
	for (int i = 0; i < k.brLekara; i++) {
		ulaz >> k.niz[i]; //prolazimo kroz ceo niz i ucitavamo sve podatke
	}
	return ulaz;
}
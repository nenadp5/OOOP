#include "Firma.h"
#include "Radnik.h"
#include <iostream>
#include <cstring>
#include <fstream> //ukljucujemo sve neophodne biblioteke za rad sa stringovima, fajlovima i standardnim ulazom i izlazom
using namespace std;

Firma::Firma() { //podrazumevani konstruktor koji postavlja vrednosti na 0, NULL ili prazno u zavisnosti od slucaja
	this->niz = NULL;
	this->brRadnika = 0;
	strcpy_s(this->naziv, "");
}

Firma::~Firma() {
	delete[]niz; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
}

void Firma::ulazBin(const char* fajlPutanja) {
	ifstream ulaz(fajlPutanja, ios::binary); //otvaramo fajl za ucitavanje podataka iz binarnog fajla, to smo postigli uz pomoc funkcije "ifstream" i nagovestaja "ios::binary" da se radi o binarnom fajlu
	if (ulaz) { //ukoliko je ulaz uspesno otvoren obavljaju se sledece funkcije
		if (this->niz != NULL) {
			delete[]niz;  //ukoliko je parametar niz zauzet, vrsimo brisanje te vrednosti, radi kreiranja mesta za novi upis
		}
		ulaz.read((char*)&naziv, sizeof(naziv));  //ucitavamo podatak vezan za naziv firme, imamo pretvaranje char* jer funkcija read/write uvek ocekuje parametar char
		ulaz.read((char*)&brRadnika, sizeof(brRadnika));  //imamo funkciju sizeof kako bi se zauzeo odgovarajuci broj mesta
		this->niz = new Radnik[brRadnika]; //vrsimo dinamicku alokaciju za niz
		for (int i = 0; i < brRadnika; i++) {
			ulaz.read((char*)&niz[i], sizeof(niz[i])); //prolazimo kroz ceo niz i ucitavamo sve elemetne iz binarnog fajla, takodje imamo i pretvaranje u tip char
		}
	}
	ulaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Firma::izlazBin(const char* fajlPutanja) {
	ofstream izlaz(fajlPutanja, ios::binary); //otvaramo fajl za upisivanje podataka u binarni fajla, to smo postigli uz pomoc funkcije "ofstream" i nagovestaja "ios::binary" da se radi o binarnom fajlu
	izlaz.write((char*)&naziv, sizeof(naziv));  //upisujemo podatak vezan za naziv firme, imamo pretvaranje char* jer funkcija read/write uvek ocekuje parametar char
	izlaz.write((char*)&brRadnika, sizeof(brRadnika));
	for (int i = 0; i < brRadnika; i++) {
		izlaz.write((char*)&niz[i], sizeof(niz[i])); //prolazimo kroz ceo niz i upisujemo sve elemetne u binarni fajl, takodje imamo i pretvaranje u tip char
	}
	izlaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Firma::ulazTxt(const char* fajlPutanja) {
	ifstream ulaz(fajlPutanja); //otvaramo fajl za ucitavanje podataka iz tekstualnog fajla, sto nam omogucava funkcija "ifstream"
	if (ulaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		if (niz != NULL) {
			delete[]niz; // ukoliko je niz zauzet brisu se vrednosti odatle, kako bi mogle da se upisu nove
		}
		ulaz >> naziv; //ucitavamo naziv firme
		ulaz >> brRadnika; //ucitavamo broj radnika
		this->niz = new Radnik[brRadnika]; //vrsimo dinamicku alokaciju za niz radnika
		for (int i = 0; i < brRadnika; i++) {
			ulaz >> niz[i]; //prolazimo kroz ceo niz i ucitavamo sve elemente
		}
	}
	ulaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Firma::izlazTxt(const char* fajlPutanja) {
	ofstream izlaz(fajlPutanja); //otvaramo fajl za upis podataka u tekstualni fajl, to nam omogucava funkcija "ofstream", prosledjeni element je sam naziv fajla
	izlaz << naziv << endl; //upisujemo sve elemente vezane za firmu
	izlaz << brRadnika << endl;
	for (int i = 0; i < brRadnika; i++) {
		izlaz << niz[i]; //prolazimo kroz ceo niz i upisujemo sve podatke o radnicima u tekstualni fajl
	}
	izlaz.close(); //zatvaramo prethodno otvoreni fajl
}

ostream& operator<<(ostream& izlaz, const Firma& f) {
	izlaz << f.naziv << endl; //operator za prikaz podataka vezanih za firmu, prosledjuje se sa parametrom const, jer ne treba da menja objekat
	izlaz << f.brRadnika << endl;
	for (int i = 0; i < f.brRadnika; i++) {
		izlaz << f.niz[i] << "";
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Firma& f) { //operator za unos podataka vezanih za firmu, nemamo parametara const jer se vrse izmene objekta
	ulaz >> f.naziv; //ucitavamo podatke redom
	ulaz >> f.brRadnika;
	f.niz = new Radnik[f.brRadnika]; //vrsimo dinamicku alokaciju za niz radnika
	for (int i = 0; i < f.brRadnika; i++) {
		ulaz >> f.niz[i]; //ucitavamo sve radnike redom
	}
	return ulaz;
}
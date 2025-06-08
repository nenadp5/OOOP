#include "Prodavnica.h"
#include "Proizvod.h"
#include <iostream>
#include <fstream>
#include <cstring> //ukljucujemo sve neophodne biblioteke za rad sa stringovima, fajlovima i standardnim ulazom i izlazom
using namespace std;

Prodavnica::Prodavnica() {
	this->niz = NULL; //podrazumevani konstruktor koji postavlja vrednosti na 0, NULL ili prazno u zavisnosti od slucaja
	strcpy_s(this->nazivProdavnice, "");
	this->brojProizvoda = 0;
}

Prodavnica::~Prodavnica() {
	delete[]niz; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
}

void Prodavnica::ulazBin(const char* fajlPutanja) {
	ifstream ulaz(fajlPutanja, ios::binary); //otvaramo fajl za ucitavanje podataka iz binarnog fajla, to smo postigli uz pomoc funkcije "ifstream" i nagovestaja "ios::binary" da se radi o binarnom fajlu
	if (ulaz) { //ukoliko je ulaz uspesno otvoren obavljaju se sledece funkcije
		if (this->niz != NULL) {
			delete[] niz; //ukoliko je parametar niz zauzet, vrsimo brisanje te vrednosti, radi kreiranja mesta za novi upis
		}
		ulaz.read((char*)&nazivProdavnice, sizeof(nazivProdavnice)); //ucitavamo podatak vezan za naziv prodavnice, imamo pretvaranje char* jer funkcija read/write uvek ocekuje parametar char
		ulaz.read((char*)&brojProizvoda, sizeof(brojProizvoda)); //imamo funkciju sizeof kako bi se zauzeo odgovarajuci broj mesta
		this->niz = new Proizvod[brojProizvoda]; //vrsimo dinamicku alokaciju za niz proizvoda
		for (int i = 0; i < brojProizvoda; i++) {
			ulaz.read((char*)&niz[i], sizeof(niz[i])); //prolazimo kroz ceo niz i ucitavamo sve elemetne iz binarnog fajla, takodje imamo i pretvaranje u tip char
		}
	}
	ulaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Prodavnica::izlazBin(const char* fajlPutanja) {
	ofstream izlaz(fajlPutanja, ios::binary); //otvaramo fajl za upisivanje podataka u binarni fajla, to smo postigli uz pomoc funkcije "ofstream" i nagovestaja "ios::binary" da se radi o binarnom fajlu
	if (izlaz) { //ukoliko je fajl uspesno otvoren vrsi se upis podataka
		izlaz.write((char*)&nazivProdavnice, sizeof(nazivProdavnice));  //upisujemo podatak vezan za naziv prodavnice, imamo pretvaranje char* jer funkcija read/write uvek ocekuje parametar char
		izlaz.write((char*)&brojProizvoda, sizeof(brojProizvoda));
		for (int i = 0; i < brojProizvoda; i++) {
			izlaz.write((char*)&niz[i], sizeof(niz[i])); //prolazimo kroz ceo niz i upisujemo sve elemetne u binarni fajl, takodje imamo i pretvaranje u tip char
		}
	}
	izlaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Prodavnica::ulazTxt(const char* fajlPutanja) {
	ifstream ulaz(fajlPutanja); //otvaramo fajl za ucitavanje podataka iz tekstualnog fajla, sto nam omogucava funkcija "ifstream"
	if (ulaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		if (this->niz != NULL) {
			delete[]niz; //ukoliko je niz zauzet brisu se vrednosti odatle, kako bi mogle da se upisu nove
		}
		ulaz >> nazivProdavnice; //ucitavamo naziv prodavnice
		ulaz >> brojProizvoda; //ucitavamo broj proizvoda
		this->niz = new Proizvod[brojProizvoda]; //vrsimo dinamicku alokaciju za niz lekara
		for (int i = 0; i < brojProizvoda; i++) {
			ulaz >> niz[i]; //prolazimo kroz ceo niz i ucitavamo elemente
		}
	}
	ulaz.close(); //zatvaramo prethodno otvoreni fajl
}

void Prodavnica::izlazTxt(const char* fajlPutanja) {
	ofstream izlaz(fajlPutanja); //otvaramo fajl za upis podataka u tekstualni fajl, to nam omogucava funkcija "ofstream", prosledjeni element je sam naziv fajla
	if (izlaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		izlaz << nazivProdavnice << endl; //upisujemo sve elemente vezane za prodavnicu
		izlaz << brojProizvoda << endl;
		for (int i = 0; i < brojProizvoda; i++) {
			izlaz << niz[i]; //prolazimo kroz ceo niz i upisujemo sve podatke o proizvodima u tekstualni fajl
		}
	}
	izlaz.close();
}

ostream& operator<<(ostream& izlaz, const Prodavnica& p) {
	izlaz << p.nazivProdavnice << endl; //operator za prikaz podataka vezanih za kliniku, prosledjuje se sa parametrom const, jer ne treba da menja objekat
	izlaz << p.brojProizvoda << endl;
	for (int i = 0; i < p.brojProizvoda; i++) {
		izlaz << p.niz[i] << endl;
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Prodavnica& p) {
	ulaz >> p.nazivProdavnice; //operator za unos podataka vezanih za kliniku, nemamo parametara const jer se vrse izmene objekta
	ulaz >> p.brojProizvoda;
	if (p.niz != NULL) {
		delete[]p.niz; //ukoliko je parametar niz zauzet, onda se vrsi brisanje sadrzaja tog parametra, kako bi se omogucio upis novih
	}
	p.niz = new Proizvod[p.brojProizvoda]; //vrsimo dinamicku alokaciju za niz proizvoda
	for (int i = 0; i < p.brojProizvoda; i++) {
		ulaz >> p.niz[i]; //prolazimo kroz ceo niz i ucitavamo podatke
	}
	return ulaz;
}
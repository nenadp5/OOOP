#include "FudbalskiKlub.h"
#include <iostream>
#include <cstring>
using namespace std;

FudbalskiKlub::FudbalskiKlub(const char* naziv, int maxBr, int trBr,int* niz) {
	int duzina = strlen(naziv) + 1; //kreiramo pomocnu promenljivu, koja broji koliko mesta u memoriji ce zauzeti promenljiva naziv, to se postize uz pomoc funkcije "strlen", na kraju imamo +1 zbog "/0" karaktera na kraju niza
	this->naziv = new char[duzina]; //vrsimo dinamicku alokaciju memorije
	strcpy_s(this->naziv, duzina, naziv); //kopiramo prosledjene vrednosti

	this->maxBr = maxBr; //dodeljujemo prosledjene vrednosti privatnim atributima
	this->trBr = trBr;

	this->niz = new int[this->maxBr]; //vrsimo dinamicku alokaciju memorije za promenljivu niz
	for (int i = 0; i < this->trBr; i++) {
		this->niz[i] = niz[i]; //prolazimo kroz ceo niz i upisujemo elemente u njega
	}
}

FudbalskiKlub::FudbalskiKlub() {
	this->naziv = new char[1]; //podrazumevani konstruktor koji postavlja vrednosti privatnih atributa na 0, NULL ili prazno u zavisnosti od tipa promenljive
	strcpy_s(this->naziv, 1, "");
	this->niz = NULL;
	this->trBr = 0;
	this->maxBr = 0;
}

FudbalskiKlub::~FudbalskiKlub() {
	delete[]naziv; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
	delete[]niz;
}

FudbalskiKlub& FudbalskiKlub::operator=(const FudbalskiKlub& drugi) { //kada imamo & u deklaraciji "FudbalskiKlub& operator=" to znaci da se izmene vrse direktno u memoriji
	if (this != &drugi) { //proveravamo da li se trenutni i prosledjeni objekat razlikuju, i u zavisnosti od toga se obavljaju sledece operacije
		if (this->naziv != NULL) {
			delete[]naziv; //ukoliko je atribut "naziv" vec popunjen, brise se njegova vrednost, da bi mogla da se smesti nova
		}
		if (this->niz != NULL) {
			delete[]niz; //ukoliko je atribut "niz" vec popunjen, brise se njegova vrednost, da bi mogla da se smesti nova
		}
		int duzina = strlen(drugi.naziv) + 1; //ponovo brojimo koliko ce elementa biti zauzeto
		this->naziv = new char[duzina]; //vrsimo dinamicku alokaciju
		strcpy_s(this->naziv, duzina, drugi.naziv); //vrsimo dodelu vrednosti

		this->maxBr = drugi.maxBr; //dodela vrednosti trenutnom elementu od strane prosledjenog elementa
		this->trBr = drugi.trBr;

		this->niz = new int[this->maxBr]; //ponovo se vrsi dinamicka alokacija za niz
		for (int i = 0; i < this->trBr; i++) {
			this->niz[i] = drugi.niz[i]; //upisujemo elemente u niz
		}
	}
	return *this; //povratna vrednost je azurirani trenutni objekat
}

FudbalskiKlub& FudbalskiKlub::operator+=(int rezultat) { //operator za dodavanje rezultata u niz
	if( this->trBr <= this->maxBr) { //ukoliko ima mesta u nizu, odnosnu ukoliko je trenutni broj manji od maksimalnog onda se upisuju vrednosti
		this->niz[this->trBr] = rezultat; //upisujemo prosledjeni element u niz
		this->trBr++; //povecavamo trenutni broj elemenata nakon upisa
	}
	else {
		cout << "Greska! Prekoracili ste broj maksimalnih bodova! " << endl; //ukoliko prekoracimo opseg ispisuje se poruka
	}
	return *this; //povratna vrednost je azurirani trenutni objekat
}

bool FudbalskiKlub::operator<(FudbalskiKlub& drugi) {
	return (this->brojBodova() < drugi.brojBodova()); //povratna vrednost je TRUE ili FALSE u zavisnosti od uslova, odnosno od toga da li prosledjeni objekat ima vise bodova od trenutnog
}

ostream& operator<<(ostream& izlaz, const FudbalskiKlub& klub) { //operator za prikaz informacija o fudbalskom klubu, prosledjujemo sa parametrom const da ne bi menjalo vrednosti
	izlaz << klub.naziv << endl;
	izlaz << "Sa maksimalnim brojem rezultata: " << klub.maxBr << endl; //samo ispisujemo sve informacije o prosledjenom objektu
	izlaz << "Koji trenutno ima " << klub.trBr << " rezultata u nizu" << endl;
	izlaz << "I njihov niz rezultata izgeda: ";
	for (int i = 0; i < klub.trBr; i++) {
		izlaz << klub.niz[i] << " ";
	}
	izlaz << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, FudbalskiKlub& klub) { //operator za unos vrednosti
	if (klub.naziv != NULL) {
		delete[]klub.naziv; //proveravamo da li je atribut "naziv" slobodan, ukoliko nije brisemo vrednosti koje su tu smestene
	}
	if (klub.niz != NULL) {
		delete[]klub.niz; //proveravamo da li je atribut "niz" slobodan, ukoliko nije brisemo vrednosti koje su tu smestene
	}
	char naziv[100]; //kreiramo pomocnu promenljivu za naziv
	cout << "Unesite naziv kluba: ";
	cin >> naziv; //unosimo vrednost u novoformiranu promenljivu
	int duzina = strlen(naziv) + 1; //prebrojavamo kolika je vrednost pomocne promenljive u memoriji, da bi kasnije mogli da izvrsimo dinamicku alokaciju
	klub.naziv = new char[duzina]; //vrsimo dinamicku alokaciju atributa prosledjenog objekta
	strcpy_s(klub.naziv,duzina,naziv); //kopiramo vrednost iz pomocne promenljive u atribut
	cout << "Unesite maksimalni broj rezultata kluba: ";
	ulaz >> klub.maxBr; //unosimo direktno vrednost atributa
	cout << "Unesite trenutni broj rezultata kluba: ";
	ulaz >> klub.trBr; //unosimo direktno vrednost atributa
	klub.niz = new int[klub.maxBr]; //vrsimo dinamicku alokaciju niza prosledjenog objekta
	cout << "Unesi niz rezutata kluba ((za pobedu se upisuje 3, neresen rezultat 1 i za poraz 0 bodova): ";
	for (int i = 0; i < klub.trBr; i++) {
		ulaz >> klub.niz[i]; //prolazimo kroz ceo niz i upisujemo podatke direktno
	}
	return ulaz;
}
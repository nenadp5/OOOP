#include "Vektor.h"
#include <iostream>
using namespace std;

Vektor::Vektor(int trBr) { //konstruktor za postavljanje vrednosti
	this->trBr = trBr;
	this->niz = new float[this->trBr]; //odmah kreiramo i niz u dinamickoj zoni memorije
}

Vektor::Vektor(const Vektor& original) { //konstruktor za kopiranje
	this->trBr = original.trBr; 
	this->niz = new float[this->trBr]; 
	for (int i = 0; i < this->trBr; i++) {
		this->niz[i] = original.niz[i]; //kopiramo svaki element prosledjenog vektora
	}
}

Vektor::Vektor() { //podrazumevani konstruktor
	this->trBr = 0; //postavlja vrednost privatnih atributa na 0 ili NULL ukoliko je u pitanju niz
	this->niz = NULL;
}

Vektor::~Vektor() { //destruktor
	delete[]niz; //brise sve elemente koji su zauzeti u procesu dinamicke alokacije
}

Vektor Vektor::operator+(const Vektor& v) { //operator za sabiranje dva vektora
	Vektor zbir(this->trBr); //kreiramo nov pomocni vektor "ZBIR" koji ima dimenziju prvog prosledjenog vektora
	if (this->trBr != v.trBr) { //proveravamo da li su dva prosledjena vektora istih dimenzija, to je jedan od matematickih uslova kako bi zadatak ispravno radio
		cout << "Greska, nije moguce obaviti sabiranje, jer vektori nisu iste duzine! "; //ukoliko su razliticih dimenzija, onda ne mogu da se saberu
	}
	else {
		for (int i = 0; i < this->trBr; i++) {
			zbir.niz[i] = this->niz[i] + v.niz[i]; //ukoliko su istih dimenzija, prolazimo kroz oba vektora i sabiramo svake elemnte, potom te rezultate smestamo u novoformirani vektor "zbir"
		}
	}
	return zbir; //vracamo novi vektor koji je nastao u ovoj klasi
}

Vektor Vektor::operator+(float skalar) { //konstruktor za sabiranje vektora i skalarne vrednosti
	Vektor zbir(*this); //kreiramo novi vektor od trenutnog prosledjenog vektora
	for (int i = 0; i < this->trBr; i++) {
		zbir.niz[i] = this->niz[i] + skalar; //sabiramo vektor i skalar i potom tu vrednost zapisujemo u novoformirani vektor 
	}
	return zbir; //vracamo novoformirani vektor
}

Vektor& Vektor::operator++() { //operator za prefiksno inkrementiranje
	for (int i = 0; i < this->trBr; i++) {
		niz[i]++; //prolazimo kroz ceo vektor (odnosno kroz sve elemente niza) i uvecavamo ih
	}
	return *this; //povratna vrednost je izmenjen vektor
}

Vektor Vektor::operator++(int n) { //operator za postfiksno inkrementiranje, uvek se definise na ovaj nacin sa parametrom n koji se nigde ne koristi
	Vektor kopija(*this); //kreiramo novi vektor od prosledjenog
	for (int i = 0; i < trBr; i++) {
		niz[i]++; //uvecavamo vrednost prosledjenog vektora
	}
	return kopija; //kao povratnu vrednost imamo novoformirani vektor koji nema uvecane vrednosti
}

Vektor& Vektor::operator=(const Vektor& v) { //operator za dodelu vrednosti
	if (this != &v) { //ukoliko se vektori razlikuju obavljaju se sledece operacije
		if (this != NULL) { //prvo proveravamo da li je niz prazan, ukoliko nije brisemo sve elemente
			delete[]niz;
		}
		this->trBr = v.trBr;// onda sledi dodela vrednosti trenutnom vektoru od strane prosledjenog
		this->niz = new float[this->trBr]; 
		for (int i = 0; i < this->trBr; i++) {
			this->niz[i] = v.niz[i];
		}
	}
	return *this; //povratna vrednost je taj izmenjeni niz
}

Vektor operator+(float broj,const Vektor& v) { //prijateljska operacija koja sabira sakalar sa prosledjenim vektorom
	Vektor zbir(v.trBr); //kreiramo novi vektor od prosledjenog vektora
	for (int i = 0; i < v.trBr; i++) {
		zbir.niz[i] = v.niz[i] + broj; //svaki elemnt vektora sabiramo sa prosledjenim brojem
	}
	return zbir; //povratna vrednost je novoformirani vektor, odnosno rezultat prethodnog sabiranja
}

ostream& operator<<(ostream& izlaz, const Vektor& v) { //prijateljska operacija za prikaz(operator<<), imamo parametar const kod prosledjenog elementa, jer prilikom prikaza ne treba menjati nikakve vrednosti
	for (int i = 0; i < v.trBr; i++) {
		izlaz << v.niz[i] << " "; //uvek se ovako zapisuje proces ispisa vrednosti
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Vektor& v) { //prijateljska operacija za unos(operator>>),nemamo parametar const jer se prosledjeni element menja zbog unosa vrednosti
	for (int i = 0; i < v.trBr; i++) {
		ulaz >> v.niz[i];
	}
	return ulaz;
}

/*Objasnjenje:
- Kada imamo zapis formata "Vektor& Vektor::operator++()" to znaci da ce nam vrednosti koju dobijemo na kraju biti direktno prosledjena (*this),
i ovde se uglavnom radi direktno sa memorijom jer nam to omogucava operator &;
- Kada imamo zapis "Vektor Vektor::operator+(const Vektor& v)" to zanci da vrednost koju dobijemo na kraju trebamo da prosledimo konstruktoru za kreiranje,
i da se ovde moze baratati i sa kopijama;

Korisna fora: kada kod operatora imamo neki prosledjeni vektor, onda kod kreiranja novog vektora u okviru klase koristimo njegov broj elemenata (tipa "Vektor zbir(v.trBr)),
dok kada nemamo prosledjeni vektor onda koristimo taj trenutni (tipa "Vektor zbir(*this)); */
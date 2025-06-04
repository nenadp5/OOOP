#pragma once
#include <iostream>
using namespace std;
class FudbalskiKlub { //kreiramo klasu "FudbalskiKlub"
private:
	char* naziv; //naziv kluba smesten u dinamickoj zoni memorije
	int* niz; //niz rezultata smesten u dinamickoj zoni memorije
	int maxBr; //maksimalni broj rezultata, odnosno dimenzija niza
	int trBr; //trenutni broj rezultata, odnosno trenutni broj elemenata u nizu

public:
	FudbalskiKlub(const char* naziv, int maxBr, int trBr, int* niz); //konstruktor za postavljanje vrednosti
	FudbalskiKlub(); //podrazumevani konstruktor
	~FudbalskiKlub(); //destruktor

	int brojBodova() { //inline metoda koja racuna broj bodova
		int brojBodova = 0; //kreiramo pomocnu promenljivu
		for (int i = 0; i < trBr; i++) {
			brojBodova += niz[i]; //prolazimo kroz ceo niz i sumiramo elemente
		}
		return brojBodova; //povratna vrednost nam je ukupan broj bodova tipa float 
	}

	FudbalskiKlub& operator=(const FudbalskiKlub& drugi); //operator koji uzima vrednosti jednog kluba od drugog
	FudbalskiKlub& operator+=(int rezultat); //operator za dodavanje prosledjenog rezultata u niz
	bool operator<(FudbalskiKlub& drugi); //logicki operator za poredjenje dva kluba na osnovu broj bodova

	friend ostream& operator<<(ostream& izlaz, const FudbalskiKlub& klub); //prijateljska operatorska funkcija za izlaz, odnosno prikaz rezultata
	friend istream& operator>>(istream& ulaz, FudbalskiKlub& klub); //prijateljska operatorska funkcija za unos podataka

};
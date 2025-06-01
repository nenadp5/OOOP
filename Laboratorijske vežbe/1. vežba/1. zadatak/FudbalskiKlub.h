#pragma once
#include <iostream>
using namespace std;
class FudbalskiKlub { //kreiramo klasu "FudbalskiKlub"
private: //privatni atributi klase
	char* naziv; //naziv kluba smesten u dinamickoj zoni memorije
	int* niz; //niz celobrojnih rezultata kluba koji je smesten u dinamickoj zoni memorije
	int maxBr; //maksimalni broj rezultata, odnosno broj elemenata niza
	int trBr; //trenutni broj elemenata u nizu

public:
	FudbalskiKlub(const char* naziv, int* niz, int maxBr, int trBr); //konstruktor za postavljanje vrednosti
	FudbalskiKlub(); //podrazumevani konstruktor
	FudbalskiKlub(const FudbalskiKlub& original); //konstruktor za kopiranje
	~FudbalskiKlub(); //destrutkor

	int ukupnoBodova() { //inline metoda za vracanje ukupnog broja bodova
		int sum = 0; //kreiramo pomocnu promenljivu
		for (int i = 0; i < trBr; i++) {
			sum += niz[i]; //prolazimo kroz niz i sabiramo elemente u njemu
		}
		return sum; //povratna vrednost nam je celobrojni tip podatka
	}

	void prikaz(); //metoda za prikaz
};
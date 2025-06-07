#pragma once
class Putovanje { //kreiramo klasu "Putovanje" koja je osnovna klasa
protected: //zasticeni atributi klase
	char* naziv; //naziv smo stavili u dinamickoj zoni memorije, iako nije trazeno u zadatku
	float trajanje; //atributi trajanje, cena smestaja i cena prevoza su smesteni u staticki deo memorije
	float cenaSmestaja;
	float cenaPrevoza;
	virtual float cena() = 0; //cista virtuelna funkcija za racunanje cene

public:
	Putovanje(const char* naziv, float trajanje, float cenaSmestaja, float cenaPrevoza); //konstruktor za postavljanje vrednosti
	virtual ~Putovanje(); //virtuelni destruktor
	void prikaz(); //metoda za prikaz podataka
	bool operator<(Putovanje& putovanje); //operator koji poredi dva objekta na osnovu cene
};
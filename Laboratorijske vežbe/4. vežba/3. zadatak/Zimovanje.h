#pragma once
#include "Putovanje.h"
class Zimovanje :public Putovanje { //kreiramo klasu "Zimovanje" koja je izvedena iz klase "Putovanje"
private:
	float cenaSkiKarte; //privatni atribut klase
protected:
	float cena(); //zasticena cista virtuelna funkcija iz klase "Putovanje" koja mora i ovde biti definisana
public:
	Zimovanje(const char* naziv, float trajanje, float cenaSmestaja, float cenaPrevoza, float cenaSkiKarte); //konstruktor koji postavlja vrednosti
	~Zimovanje(); //destruktor
};
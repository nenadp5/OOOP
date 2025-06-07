#pragma once
#include "Putovanje.h"
class Letovanje : public Putovanje { //kreiramo klasu "Letovanje" koja je izvedena iz klase "Putovanje"
private:
	float cenaTrajekta; //privatni atribut klase
protected:
	float cena(); //zasticena cista virtuelna fukcija iz klase "Putovanje" koja mora i ovde biti definisana
public:
	Letovanje(const char* naziv, float trajanje, float cenaSmestaja, float cenaPrevoza, float cenaTrajekta); //konstruktor koji postavlja vrednosti
	~Letovanje(); //destruktor
};
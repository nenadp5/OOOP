#pragma once
#include "Radnik.h"
class NagradjeniRadnik :public Radnik { //pravimo klasu "NagradjeniRadnik" koja je izvedena iz klase "Radnik"
private:
	float bonus; //privatni atribut klase

public:
	NagradjeniRadnik(); //podrazumevani konstruktor
	NagradjeniRadnik(const char* ime, float cenaRadnogSata, float brSati, float bonus); //konstruktor za postavljanje vrednosti
	~NagradjeniRadnik(); //virtuelni destruktor
	float plata(); //metoda za racunanje plate
	void prikaz(); //metoda za prikaz vrednosti
};
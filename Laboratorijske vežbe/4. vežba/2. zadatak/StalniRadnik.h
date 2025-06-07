#pragma once
#include "Radnik.h"
class StalniRadnik :public Radnik { //kreiramo klasu "StalniRadnik" koja je izvedena iz klase "Radnik"
private: //privatni atributi klase
	float plata; //plata i bonus smesteni u dinamickoj zoni memorije
	float bonus;
	float IznosPlate(); //metoda za racunanje plate iz klase "Radnik"
public:
	StalniRadnik(const char* ime, const char* prezime, float plata, float bonus); //konstruktor za postavljanje vrednosti
	~StalniRadnik(); //destruktor
	void prikaz(); //metoda za prikaz
};
//metoda za platu i prikaz su ciste virtuelne metode iz klase "Radnik" i one moraju biti definisane u okviru ove klase
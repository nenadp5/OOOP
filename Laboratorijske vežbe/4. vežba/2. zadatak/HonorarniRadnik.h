#pragma once
#include "Radnik.h"
class HonorarniRadnik :public Radnik { //kreiramo klasu "HonorarniRadnik" izvedenu iz klase "Radnik"
private: //privatni atributi klase
	float brSati; //broj sati i cena sata smesteni u statickoj zoni memorije
	float cenaSata;
	float IznosPlate(); //metoda za racunanje plate
public:
	HonorarniRadnik(const char* ime, const char* prezime, float brSati, float cenaSata); //konstruktor za postavljanje vrednosti
	~HonorarniRadnik(); //destruktor
	void prikaz(); //metoda za prikaz
};
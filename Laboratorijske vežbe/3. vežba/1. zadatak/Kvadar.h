#pragma once
#include "Pravougaonik.h"
class Kvadar :public Pravougaonik { //kreiramo klasu "Kvadar" koja je izvedena iz klase "Pravougaonik" pa shodno tome moze koristiti njene elemente
private:
	float h; //privatni atribut visina

public:
	Kvadar(); //podrazumevani konstruktor
	Kvadar(float a, float b, float h); //konstruktor koji postavlja vrednosti
	float povrsina(); //metoda za racunanje povrsine
	float zapremina(); //metoda za racunanje zapremine
	void prikaz(); //metoda za prikaz
};
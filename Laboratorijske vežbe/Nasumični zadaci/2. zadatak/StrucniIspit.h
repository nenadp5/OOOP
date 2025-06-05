#pragma once
#include "Ispit.h"
class StrucniIspit :public Ispit { //kreiramo klasu SturcniIspit izvedenu iz klase Ispit
private:
	float labPoeni; //privatni atributi klase
public:
	StrucniIspit(); //podrazumevani konstruktor
	StrucniIspit(const char* naziv, float pismeni, float usmeni, float labPoeni); //konstruktor za postavljanje vrednosti
	~StrucniIspit(); //destruktor
	int ocena(); //metoda za racunanje ocene
	void prikaz(); //metoda za prikaz
};
#pragma once
#include "Krug.h" //ukljucujemo header fajl "Krug.h" jer je klasa "Valjak" izvedena iz klase "Krug"
class Valjak :public Krug { //ovako se definise kad je neka klasa izvedena iz druge
private: //privatni atributi klase "Valjak"
	float h;

public: //javni atributi klase "Valjak"
	Valjak(float r, float h); //konstruktor za postavljanje vrednosti
	Valjak(const Valjak& original); //konstruktor za kopiranje
	~Valjak();
	float povrsina(); //metoda za racunanje povrsine
	float zapremina(); //metoda za racunanje zapremine
	void prikaz(); //metoda za prikaz vrednosti
};
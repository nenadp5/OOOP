#pragma once
#include "GeometrijskoTelo.h"
class Piramida :public GeometrijskoTelo { //kreiramo klasu "Piramida" koja je izvedena iz klase "GeometrijskoTelo"
private: //privatni atributi klase
	float a; //dimenzija baze i visina su smesteni u staticki deo memorije
	float h;
public: //javni atributi klase
	Piramida(float a, float h); //konstruktor za postavljanje vrednosti
	~Piramida(); //destruktor
	float zapremina(); //metoda za racunanje zapremine
	float povrsina(); //metoda za racunanje povrsine
	void prikaz(); //metoda za prikaz podataka
};
//metode za prikaz,povrsinu i zapreminu su ciste virtuelne metode iz klase "GeometrijskoTelo" i zbog toga moraju da se i ovde definisu
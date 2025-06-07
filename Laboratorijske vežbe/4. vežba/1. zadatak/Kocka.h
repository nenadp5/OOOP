#pragma once
#include "GeometrijskoTelo.h"
class Kocka :public GeometrijskoTelo { //kreiramo klasu "Kocka" koja je izvedena iz klase "GeometrijskoTelo"
private: //privatni atributi klase
	float a; //stranica kocke
public: //javni atributi klase
	Kocka(float a); //konstruktor koji postavlja vrednosti
	~Kocka(); //destruktor
	float zapremina(); //metoda za racunanje zapremine
	float povrsina(); //metoda za racunanje povrsine
	void prikaz(); //metoda za prikaz podataka
};
//metode za prikaz,povrsinu i zapreminu su ciste virtuelne metode iz klase "GeometrijskoTelo" i zbog toga moraju da se i ovde definisu
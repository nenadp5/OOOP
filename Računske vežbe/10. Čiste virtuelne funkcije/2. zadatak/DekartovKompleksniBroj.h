#pragma once
#include "KompleksniBroj.h"
class DekartovKompleksniBroj :public KompleksniBroj { //kreiramo klasu "DekartovKompleksniBroj" koja je izvedena iz klase "KompleksniBroj"
private: //privatni atribut klase "DekartovKompleksniBroj"
	float im;
	float re;

public: //javni atributi
	DekartovKompleksniBroj(float re, float im); //konstruktor koji postavlja vrednosti
	
	float moduo(); //ciste virtuelne funkcije iz klase "KompleksniBroj" koji moraju biti i ovde deklarisane
	void prikaz();
};
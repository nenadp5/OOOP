#pragma once
#include "KompleksniBroj.h"
class PolarniKompleksniBroj :public KompleksniBroj { //kreiramo klasu "PolarniKompleksniBroj" koja je izvedena iz klase "KompleksniBroj" i shodno tome mora imati deklarisane ciste virtuelne funkcije iz te klase
private: //privatni atributi klase
	float mod;
	float ugao;

public: //javni atributi
	PolarniKompleksniBroj(float mod, float ugao); //Konstruktor koji postavlja vrednosti
	
	float moduo(); //ciste virtuelne funkcije iz klase "KompleksniBroj" koje se i ovde deklarisu
	void prikaz();
};
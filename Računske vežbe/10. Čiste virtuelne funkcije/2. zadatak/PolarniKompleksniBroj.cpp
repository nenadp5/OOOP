#include "PolarniKompleksniBroj.h"
#include <iostream>
using namespace std;

PolarniKompleksniBroj::PolarniKompleksniBroj(float mod, float ugao) {
	this->mod = mod; //standardni konstruktor za dodelu vrednosti
	this->ugao = ugao; //prosledjene vrednosti se dodeljuju privatnim atributima
}

float PolarniKompleksniBroj::moduo() { //cista virtuelna funkcija iz klase "KompleksniBroj" koja se ovde definise sta obavlja
	return this->mod; //buduci da je jedan od privatnih atributa moduo samog broja, nema potrebe za matematickim racunanjem, vec samo vracamo tu vrednost
}

void PolarniKompleksniBroj::prikaz() { //cista virtuelna funkcija iz klase "KompleksniBroj" koja se ovde definise, sta treba da obavlja za ovu klasu
	cout << this->mod << "e^i" << this->ugao << endl; //samo ispisujemo privatne atribute sa predznakom e^i
}
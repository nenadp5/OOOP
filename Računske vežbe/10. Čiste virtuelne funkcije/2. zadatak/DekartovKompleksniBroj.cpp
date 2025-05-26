#include "DekartovKompleksniBroj.h"
#include <iostream>
#include <cmath>
using namespace std;

DekartovKompleksniBroj::DekartovKompleksniBroj(float re, float im) {
	this->re = re; //standardni konstruktor za dodelu vrednosti, gde se privatnim atributima dodeljuju vrednosti prosledjenih elemenata
	this->im = im;
}

float DekartovKompleksniBroj::moduo() { //cista virtuelna funkcija iz klase "KompleksniBroj" koja racuna moduo kompleksnog broja, koja ovde biva definsana
	return sqrt(this->re * this->re + this->im * this->im); //koristimo matematicku funkciju iz biblioteke "cmath"
}

void DekartovKompleksniBroj::prikaz() {  //cista virtuelna funkcija za prikaz podataka iz klase "KompleksniBroj" koja ovde biva definisana sta obavlja
	if (this->im >= 0) { //ovde se vrsi proverava samo radi pravilnog ispisa
		cout << this->re << "+j" << this->im << endl; //ipisujemo relani deo i imaginarni sa predznakom j
	}
	else {
		cout << this->re << "-j" << -this->im << endl;
	}
}

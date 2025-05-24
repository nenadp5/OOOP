#include "Krug.h"
#include <iostream>
using namespace std;

Krug::Krug() { //podrazumevani konstruktor koji postavlja vrednosti parametara na 0
	this->r = 0;
}

Krug::Krug(double r) { //konstruktor koji postavlja vrednosti atributa
	this->r = r;
}

Krug::~Krug() {} //destruktor, buduci da nemamo nista u dinamickoj zoni memorije onda se ovako zapisuje

double Krug::Povrsina() {
	return r * r * PI; //matematicka funkcija za racunanje povrsine
}

double Krug::Obim() {
	return 2 * r * PI; //matematicka funckija za racunanje obima
}

void Krug::prikaz() {
	cout << "Poluprecnik kruga je: " << this->r << endl; //prikaz svih neophodnih vrednosti
	cout << "Obim kruga je: " << Obim() << endl;
	cout << "Povrsina kruga je: " << Povrsina() << endl;
}
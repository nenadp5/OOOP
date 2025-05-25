#include "Krug.h"
#include <iostream>
using namespace std;

Krug::Krug(float r) { //konstruktor za postavljanje vrednosti
	this->r = r;
}

Krug::Krug(const Krug& original) { //konstruktor za kopiranje
	this->r = original.r;
}

Krug::~Krug(){}//destruktor

float Krug::povrsina() {
	return this->r * this->r * PI; //matematicka funkcija za racunanje povrsine kruga
}

void Krug::prikaz() { //virtuelna metoda za prikaz, koja se definise isto kao obicna metoda
	cout << "Poluprecnik kruga je: " << this->r << endl;
	cout << "Povrsina kruga je: " << povrsina() << endl; //kako bi prikazali povrsinu pozivamo metodu za racunanje povrsine
}
#include "Pravougaonik.h" //ukljucujemo neophodne biblioteke za rad
#include <iostream>
using namespace std;

Pravougaonik::Pravougaonik() {
	this->a = 0; //podrazumevani konstruktor koji postavlja vrednosti na 0
	this->b = 0;
}

Pravougaonik::Pravougaonik(float a, float b) {
	this->a = a; //konstruktor koji postavlja vrednosti atributa
	this->b = b;
}

float Pravougaonik::povrsina() {
	return this->a * this->b; //metoda za racunanje povrsine, gde nam je povratna vrednost tipa float
}

void Pravougaonik::prikaz() {
	cout << "Pravougaonik sa stranicama A=" << this->a << " B=" << this->b << endl; //ispisujemo dimenzije pravougaonika
	cout << "Ima povrsinu: " << povrsina() << endl; //pozivamo metodu za povrsinu i ispisujemo njen rezultat
}
#include "Kvadar.h"
#include "Pravougaonik.h"
#include <iostream>
using namespace std;

Kvadar::Kvadar() {
	this->h = 0; //podrazumevani konstruktor koji postavlja podrazumevane vrednosti, odnosno 0, NULL ili prazno u zavisnosti od slucaja
}

Kvadar::Kvadar(float a, float b, float h):Pravougaonik(a,b) {
	this->h = h; //konstruktor koji postavlja vrednosti, koristimo i elemente iz klase "Pravougaonik" kako ne bi ponovo vrsili dodelu 
}

float Kvadar::povrsina() {
	return 2 * (a * b + a * h + b * h); //metoda za racunanje povrsine kvadra po matematickoj formuli
}

float Kvadar::zapremina() {
	return a * b * h; //metoda za racunanje zapremine kvadra po matematickoj formuli
}

void Kvadar::prikaz() {
	cout << "Kvadar sa stranicama A=" << this->a << " B=" << this->b << " i visinom H=" << this->h << endl;
	cout << "Ima povrsinu: " << povrsina() << endl; //metoda za prikaz gde pozivamo sve elemente i metode kako bi se ispisale njihove vrednosti
	cout << "Ima zapreminu: " << zapremina() << endl;
}
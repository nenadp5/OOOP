#include <iostream>
#include "Valjak.h"
using namespace std;

Valjak::Valjak(float r, float h) :Krug(r) { //konstruktor za postavljanje vrednosti, gde koristimo vrednost poluprecnika iz klase "Krug"
	this->h = h;
}

Valjak::Valjak(const Valjak& original) :Krug(original) { //konstruktor za kopiranje, gde koristimo vrednosti iz klase "Krug"
	this->h = original.h;
}

Valjak::~Valjak() //destruktor

float Valjak::povrsina() { //metoda za racunanje povrsine valjka
	return 2 * Krug::povrsina() + 2 * this->r * this->h * PI; //matematicka formula za racunanje povrsine valjka, prilikom racunanja koristimo i metode iz klase "Krug"
}

float Valjak::zapremina() { //metoda za racunanje zapremine valjka
	return Krug::povrsina()*this->h; //matematicka formula za racunanje zapremine, takodje koristimo metodu za povrsinu iz klase "Krug"
}

void Valjak::prikaz() {
	Krug::prikaz(); //koristimo metodu za prikaz iz klase "Krug"
	cout << "Povrsina valjka je: " << povrsina() << endl; //dodajemo neophodne informacije za ispravan ispis o valjku
	cout << "Zapremina valjka je: " << zapremina() << endl;
}
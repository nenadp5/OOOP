#include "Piramida.h"
#include "GeometrijskoTelo.h"
#include <iostream>
using namespace std;
Piramida::Piramida(float a, float h) {
	this->a = a; //konstruktor koji postavlja vrednosti
	this->h = h;
}

Piramida::~Piramida(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije

float Piramida::zapremina() {
	return (this->a * this->a * this->h) / 3; //metoda za racunanje zapremine, po matematickoj formuli, povratna vrednost je tipa float
}

float Piramida::povrsina() {
	float baza = this->a * this->a; //pomocna promenljiva za racunanje povrsine baze
	float omotac = 4 * (this->a * this->h) / 2; //pomocna promenljiva za racunanje povrsine omotaca
	return baza + omotac; //na kraju saberemo pomocne promenljive i dobijemo rezultat koji je tipa float
}

void Piramida::prikaz() {
	cout << "Piramida sa dimenzijom baze: " << this->a << " i visinom: " << this->h << endl;
	cout << "Ima povrsinu: " << povrsina() << endl; //pozivamo sve neophodne metode i podatke i vrsimo njihov prikaz
	cout << "Ima zapreminu: " << zapremina() << endl;
}
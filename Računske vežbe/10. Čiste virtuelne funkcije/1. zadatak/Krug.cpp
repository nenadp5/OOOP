#include "Krug.h"
#include "GeometrijskaFigura.h"
#include <iostream>
using namespace std;

Krug::Krug(float r) :GeometrijskaFigura ("Krug") { //metoda za dodelu vrednosti, takodje iz klase "GeometrijskaFigura" uzimamo naziv same geometrijske figure
	this->r = r;
}

void Krug::prikaz() { //predefinisana metoda za prikaz
	GeometrijskaFigura::prikaz(); //pozivamo metodu za prikaz iz klase "GeometrijskaFigura"
	cout << "Poluprecnik kruga je: " << this->r <<endl; //dodajemo neophodne informacije
}

float Krug::povrsina() { //metoda za povrsinu, koja je bila definisana kao cista virtuelna u okviru klase "GeometrijskaFigura"
	return this->r * this->r * PI; //matematicka funkcija za racunanje povrsine kruga
}

float Krug::obim() { //metoda za obim, koja je bila definisana kao cista virtuelna u okviru klase "GeometrijskaFigura"
	return 2 * this->r * PI; //matematicka funkcija za racunanje obima kruga
}
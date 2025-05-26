#include "Kvadrat.h"
#include "GeometrijskaFigura.h"
#include <iostream>
using namespace std;

Kvadrat::Kvadrat(float a) :GeometrijskaFigura("Kvadrat") {
	this->a = a; //konstruktor za postavljanje vrednosti, gde koristimo naziv geometrijske figure iz klase "GeometrijskaFigura" i njenog konstruktora za postavljanje
}

void Kvadrat::prikaz() { //predefinisana metoda za prikaz vrednosti
	GeometrijskaFigura::prikaz(); //pozivamo metodu iz klase "GeometrijskaFigura"
	cout << "Stranica kvadrata je: " << this->a<<endl; //i dodajemo ostale neophodne informacije
}

float Kvadrat::povrsina() { //definisemo metodu za povrsinu
	return this->a * this->a; //matematicka funkcija za racunanje povrsine kvadrata
}

float Kvadrat::obim() { //definisemo metodu za obim
	return 4 * this->a; //matematicka funkcija za racunanje obima kvadrata
}
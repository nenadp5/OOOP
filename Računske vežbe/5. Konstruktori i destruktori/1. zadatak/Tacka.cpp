#include "Tacka.h"
#include <iostream>
using namespace std;

Tacka::Tacka(float x, float y) { //konstruktor za postavljanje vrednosti
	this->x = x; //sam konstruktor se vizuelno ne razlikuje u kodu toliko od metode, ali u pozadini ima skroz drugaciju primenu, sto je objasnjeno u teorijskom delu
	this->y = y;
}

Tacka::Tacka(Tacka& original) { //konstruktor za kopiranje, koji gotovo uvek ovako izgleda
	this->x = original.x; //obavlja se kopiranje vrednosti prosledjenog elementa u privatne atribute
	this->y = original.y;
}

Tacka::Tacka(){ //podrazumevani konstruktor 
	this->x = 0; //postavlja vrednost svih privatnih atributa na 0, ili NULL ukoliko je neki niz u pitanju
	this->y = 0;
}

Tacka::~Tacka() {} //destruktor koji oslobadja memoriju ukoliko je zastupljena dinamicka alokacija nekih promenljivih

void Tacka::pomeri(float pomX, float pomY) { //metoda za pomeranje
	this->x += pomX; //privatni atribut se pomera za odredjenu vrednost, tako sto se samo uveca
	this->y += pomY;
}

float Tacka:: rastojanje(const Tacka& druga) { //metoda za rastojanje
	return sqrt(powf(this->x - druga.x, 2) + powf(this->y - druga.y, 2)); //obavlja se racunanje rastojanja po matematickoj formuli
}
//prvi prosledjeni element i njegovi parametri su obelezeni sa this->, dok se druga prosledjena promenljiva i njegovi elementi predstavlaju sa druga.x i druga.y
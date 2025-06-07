#include "StalniRadnik.h"
#include "Radnik.h"
#include <iostream>
using namespace std;

StalniRadnik::StalniRadnik(const char* ime, const char* prezime, float plata, float bonus) :Radnik(ime, prezime) {
	this->plata = plata; //konstruktor za postavljanje vrednosti, gde koristimo i konstruktor iz klase "Radnik" i njegove elemente
	this->bonus = bonus;
}

StalniRadnik::~StalniRadnik(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije

float StalniRadnik::IznosPlate() {
	return this->plata + this->bonus; //metoda koja racuna platu radniku, bez obzira sto je u privatnom delu klase, njoj se sasvim normalno pristupa
}

void StalniRadnik::prikaz() { //metoda za prikaz
	cout << "Radnik: " << this->ime << " " << this->prezime <<"je stalni radnik." << endl;
	cout << "Prima platu: " << IznosPlate() << endl; //ispisujemo ime i prezime radnika, i pozivamo metodu za racunanje plate
}
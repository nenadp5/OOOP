#include "HonorarniRadnik.h"
#include "Radnik.h"
#include <iostream>
using namespace std;

HonorarniRadnik::HonorarniRadnik(const char* ime, const char* prezime, float brSati, float cenaSata) :Radnik(ime, prezime) {
	this->brSati = brSati; //konstruktor za postavljanje vrednosti, gde koristimo i konstruktor iz klase "Radnik" i njegove elemente
	this->cenaSata = cenaSata;
}

HonorarniRadnik::~HonorarniRadnik(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije

float HonorarniRadnik::IznosPlate() {
	return this->brSati * this->cenaSata; //metoda koja racuna platu honorarnog radnika
}

void HonorarniRadnik::prikaz() {
	cout << "Radnik: " << this->ime << " " << this->prezime << "je honorarni radnik." << endl;
	cout << "Prima platu: " << IznosPlate() << endl; //ispisujemo ime, prezime i platu radnika 
}
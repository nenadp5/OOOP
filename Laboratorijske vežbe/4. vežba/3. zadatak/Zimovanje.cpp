#include "Zimovanje.h"
#include "Putovanje.h"
#include <iostream>
using namespace std;

Zimovanje::Zimovanje(const char* naziv, float trajanje, float cenaSmestaja, float cenaPrevoza, float cenaSkiKarte) :Putovanje(naziv, trajanje, cenaSmestaja, cenaPrevoza) {
	this->cenaSkiKarte = cenaSkiKarte; //koristimo elemente i konstruktor iz klase "Putovanje" za postavljanje vrednosti, i naknadno dodajemo dodelu vrednosti elementu koji fali
}

Zimovanje::~Zimovanje() {} //destruktor koji brise elemente smestene u dinamickoj zoni memorije, buduci da takvih nema u ovoj klasi onda se on definise na ovakav nacin

float Zimovanje::cena() {
	return  trajanje * cenaSmestaja + cenaPrevoza + cenaSkiKarte; //metoda koja racuna cenu putovanja po formuli zadatoj u tekstu zadatka
}

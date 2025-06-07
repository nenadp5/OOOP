#include "Letovanje.h"
#include "Putovanje.h"
#include <iostream>
using namespace std;

Letovanje::Letovanje(const char* naziv, float trajanje, float cenaSmestaja, float cenaPrevoza, float cenaTrajekta) :Putovanje(naziv, trajanje, cenaSmestaja, cenaPrevoza) {
	this->cenaTrajekta = cenaTrajekta; //koristimo elemente i konstruktor iz klase "Putovanje" za postavljanje vrednosti, i naknadno dodajemo dodelu vrednosti elementu koji fali
}

Letovanje::~Letovanje(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije, buduci da takvih nema u ovoj klasi onda se on definise na ovakav nacin

float Letovanje::cena() {
	return  trajanje * cenaSmestaja + cenaPrevoza + cenaTrajekta; //metoda koja racuna cenu putovanja po formuli zadatoj u tekstu zadatka
}
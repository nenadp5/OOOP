#include "PlaviKrug.h"
#include <iostream>
using namespace std;

PlaviKrug::PlaviKrug(){} //podrazumevani konstruktor, buduci da nema privatnih atributa zapisujemo ga na ovaj nacin

PlaviKrug::PlaviKrug(double r, int blue) :ObojeniKrug(r, 0, 0, blue) {} //konstruktor za postavljanje vrednosti, gde sve neophodne vrednosti uzimamo iz klase "ObojeniKrug"

PlaviKrug::~PlaviKrug() {} //destruktor
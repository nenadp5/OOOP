#include "GeometrijskoTelo.h"
#include <iostream> //ukljucujemo neophodne biblioteke za rad
using namespace std;

bool GeometrijskoTelo::operator>(GeometrijskoTelo& telo) {
	return this->zapremina() > telo.zapremina(); //trenutni i prosledjeni objekat prosledjujemo metodi za racunanje zapremine
} //povratna vrednost je TRUE ili FALSE u zavisnosti od resenja
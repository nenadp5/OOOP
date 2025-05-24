#include "ObojeniKrug.h"
#include <iostream>
using namespace std;

ObojeniKrug::ObojeniKrug() { //podrazumevani konstruktor koji postavlja vrednosti na 0
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

ObojeniKrug::ObojeniKrug(double r, int red, int green, int blue) :Krug(r) { //konstruktor koji postavlja vrednosti, koristimo vrednost za poluprecnik iz klase "Krug"
	this->red = red;
	this->green = green;
	this->blue = blue;
}

ObojeniKrug::~ObojeniKrug(){} //destruktor
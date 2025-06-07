#include "Kocka.h"
#include "GeometrijskoTelo.h"
#include <iostream>
using namespace std;
Kocka::Kocka(float a) {
	this->a = a; //konstruktor koji postavlja vrednosti
}

Kocka::~Kocka(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije, buduci da nema takvih elemenata njegova definicija izgleda ovako

float Kocka::povrsina() {
	return 6 * this->a; //metoda za racunanje povrsine kocke po matematickoj formuli, povratna vrednost je tipa float
}

float Kocka::zapremina() {
	return a * a * a; //metoda za racunanje zapremine kocke po matematickoj formuli
}

void Kocka::prikaz() {
	cout << "Kocka cija je stranica: " << this->a << endl; //pozivamo sve neophodne metode i vrsimo njihov prikaz
	cout << "Ima povrsinu: " << povrsina() << endl;
	cout << "Ima zapreminu: " << zapremina() << endl;
}
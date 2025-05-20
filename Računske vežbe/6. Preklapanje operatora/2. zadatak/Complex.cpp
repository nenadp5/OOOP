#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex(double r, double i) {
	re = r; //standardni konstruktor za postavljanje vrednosti
	im = i; //ovde ne moramo da koristimo this-> jer prosledjeni parametri imaju razlicito ime
}

Complex::Complex(const Complex& original) {
	this->re = original.re; //konstruktor za kopiranje, koji se realizuje na isti nacin kao u prethodnim primerima
	this->im = original.im;
}

Complex::Complex() {
	this->re = 0; //podrazumevani konstruktor koji postavlja vrednosti elemenata na nula
	this->im = 0;
}

Complex::~Complex(){} //destruktor, koji iako se ne trazi u zadataku nije lose da bude prisutan

void Complex::prikaz() { //metoda za prikaz
	if (this->im > 0) { //zbog pravilnog ispisa, proveravamo da li je imaginarni deo broja pozitivan
		cout << this->re << "+i" << this->im; //ukoliko je broj pozitivan samo dodajemo "+i" ispred imaginarnog dela
	}
	else {
		cout << this->re << "-i" << -(this->im); //ukoliko je broj negativan dodajemo "-i" ispred imaginarnog dela i imaginarnom delu menjamo znak 
	}
}

float Complex::moduo() const {
	return sqrt(re * re + im * im); //metoda za racunanje modua kompleksnog broja uz pomoc matematicke funkcije iz biblioteke cmath
}

Complex Complex::operator+(const Complex& desni) { //operator za sabiranje dva kompleksna broja
	double i = this->im + desni.im; //sabiramo imaginarne delove trenutnog i prosledjenog kompleksnog broja i to smestamo u pomocnu promenljivu
	double r = this->re + desni.re; //sabiramo realne delove trenutnog i prosledjenog kompleksnog broja i dobijeni rezultat smestamo u pomocnu promenljivu
	return Complex(r, i); //povratna vrednost je novi kompleksni broj nastao uz pomoc konstruktora i gore pomocnih promenljivih
}

Complex Complex::operator*(const Complex& desni) { //operator za mnozenje
	double r = (this->re * desni.re) - (this->im * desni.im); //obavljamo matematicko mnozenje za realni deo kompleksnog broja i to smestamo u pomocnu promenljivu
	double i = (this->im * desni.re) + (this->re * desni.im); //obavljamo matematicko mnozenje za imaginarni deo kompleksnog broja i to smestamo u pomocnu promenljivu
	return Complex(r, i); //povratna vrednost je novi kompleksni broj nastao uz pomoc konstruktora i gore pomocnih promenljivih
}

Complex& Complex::operator=(const Complex& desni) {
	if (this != &desni) { //proveravamo da li su prosledjeni i trenutni kompleksni broj razliciti
		this->re = desni.re; //ukoliko su razliciti vrsi se dodela vrednosti
		this->im = desni.im;
	}
	return *this; //potom se prosledjuje novi element ili stari ukoliko se nisu razlikovali
}

Complex& Complex::operator++() { //prefiksni operator za inkrementiranje
	this->re += 1; //uvecava vrednost imaginarnog i realnog dela kompleksnog broja
	this->im += 1;
	return *this; //vraca uvecanu vrednost trenutnog broja
}

Complex Complex::operator++(int n) { //postfiksni operator za inkrementiranje, koji se uvek ovako definise, sa parametrom koji se nigde ne koristi
	Complex kopija(*this); //kreiramo novi kompleksni broj "KOPIJA" od prosledjenog kompeksnog broja
	this->re += 1; //uvecavamo vrednost prosledjenog kompleksnog broja, a ne KOPIJE
	this->im += 1;
	return kopija; //vracamo kopiju sto znaci da se nije vratio uvecani broj trenutnog kompleksnog broja, to ce se obavaiti u bilo kojoj sledecog operaciji, sto i jeste poenta postfiksnog inkrementiranja
}

bool Complex::operator<(const Complex& desni) { //logicka metoda koja odredjuje koji kompleksni broj je veci
	return this->moduo() < desni.moduo(); //odredimo modue broja kako bi smo zakljucili koji kompleksni broj je veci
}

bool Complex::operator>(const Complex& desni) { //logicka metoda koja odredjuje koji broj je veci
	return this->moduo() > desni.moduo();
}

bool Complex::operator==(const Complex& desni) { //logicka metoda koja odredjuje da li su kompleksni brojevi jednaki
	return (this->re == desni.re && this->im == desni.im);
}

/*Objasnjenje:
- Kada imamo zapis formata "Complex& Complex::operator++()" to znaci da ce nam vrednosti koju dobijemo na kraju biti direktno prosledjena (*this),
i ovde se uglavnom radi direktno sa memorijom jer nam to omogucava operator &;
- Kada imamo zapis "Complex Complex::operator+(const Complex& desni)" to zanci da vrednost koju dobijemo na kraju trebamo da prosledimo konstruktoru za kreiranje,
i da se ovde moze baratati i sa kopijama;
- Kada imamo "Complex(const Complex& original)", ovo const sprecava menjanje originalnog objekta;
- Kada imamo "float Complex::moduo() const", ovo const znaci da metoda ne menja objekat.
*/
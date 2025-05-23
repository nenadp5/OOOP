#include "Parking.h"
#include "Automobil.h"
#include <iostream>
using namespace std;
int main() {
	Parking PARKING("Venac"); //kreiramo parking uz pomoc konstruktora za postavljanje vrednosti
	Automobil A1("Mercedes", 2019, 90900); //kreiramo automobile uz pomoc konstruktora za postavljanje njihovih vrednosti
	Automobil A2("Audi", 2017, 70800);
	Automobil A3("Fiat", 2005, 2000);
	Automobil A4("Dacia", 2015, 12000);
	((((PARKING += A1) += A2) += A3) += A4); //dodajemo automobile na parking uz pomoc operatora+= iz klase parking
	cout << endl;
	cout << PARKING;
	cout << endl;
	
	cout << "Broj automobila novijih od 9 godina je: " << PARKING.brojNovijih(2016); //koristimo metodu za odredjivanje broja novijih vozila, tako sto godinu prosledimo direktno iz programa
	return 0;
}
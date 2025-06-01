#include "Radnik.h"
#include <iostream>
using namespace std;
int main() {
	Radnik::zaradaPoSatu = 300; //dodeljujemo vrednost statickom atributu
	const char* ime = "Petar"; //kreiramo pomocne promenljive koje kasnije prosledjujemo konstruktoru
	const char* prezime = "Petrovic";
	float niz[] = { 8,8.2,7.6,4,9.4,11 };
	int maxBr = 20;
	int trBr = 6;

	Radnik R1(ime, prezime, niz, maxBr, trBr); //kreiramo promenljivu tipa Radnik uz pomoc konstruktora kojem prosledjujemo prethodno kreirane promenljive
	cout << "Informacije o radniku: " << endl;
	R1.prikaz(); //pozivamo metodu za prikaz
	cout << endl;

	// novog radnika mozemo kreirati i na sledeci nacin: "Radnik R2("Petar", "Petrovic", niz, 20, 6);"
	
	Radnik Kopija(R1); //kreiramo novu promenljivu tipa Radnik, koja nastaje tako sto konstruktoru za kopiranje prosledimo prethodno kreiranu promenljivu tipa Radnik
	cout << "Informacije o kopiranom radniku: " << endl;
	Kopija.prikaz(); //pozivamo metodu za prikaz
	cout << endl;

	return 0;
}
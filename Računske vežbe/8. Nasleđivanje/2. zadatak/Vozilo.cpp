#include "Vozilo.h"
#include <iostream>
using namespace std;

void Vozilo::povecajDotokGoriva() { //metoda za povecavanje dotoka goriva
	cout << "Povecavam dotok goriva..." << endl; //samo ispisujemo poruku da smo povecali dotok goriva
}

void Vozilo::aktivirajSistemKocenja() { //metoda za aktiviranje sistema kocenja
	cout << "Aktiviram sistem kocenja..." << endl; //samo ispisujemo poruku da smo aktivirali sistem
}

Vozilo::Vozilo() { //podrazumevani konstruktor koji postavlja podrazumevane vrednosti
	this->brzina = 0;
	this->stanjeRezervoara = 100; //stavljamo da je podrazumevana vrednost 100, jer rezervoar ne moze da bude prazan
}

void Vozilo::ubrzaj() {//metoda za ubrzavanje
	this->povecajDotokGoriva(); //pozivamo zasticenu metodu koja povecava dotok goriva
	brzina++; //povecavamo brzinu
	cout << "Ubrzavamo, trenutna brzina je: " << brzina << endl; //ispisujemo vrednost uvecane brzine
}

void Vozilo::uspori() { //metoda za usporavanje
	this->aktivirajSistemKocenja();  //pozivamo zasticenu metodu koja aktivira sistem kocenja
	brzina--; //smanjujemo brzinu
	cout << "Usporavamo, trenutna brzina je: " << brzina << endl; //ispisujemo vrednost smanjene brzine
}
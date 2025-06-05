#include "StrucniIspit.h"
#include "Ispit.h"
#include <iostream>
#include <cstring>
using namespace std;

StrucniIspit::StrucniIspit() {
	labPoeni = 0; //postavljamo vrednost privatnih atributa na 0
}

StrucniIspit::StrucniIspit(const char* naziv, float pismeni, float usmeni, float labPoeni) :Ispit(naziv, pismeni, usmeni) {
	this->labPoeni = labPoeni; //koristimo elemente iz klase Ispit i njenog konstruktora za odredjene elemente, dok neke mi postavljamo sami
}

StrucniIspit::~StrucniIspit(){} //destruktor koji brise elemente smestene u dinamickoj zoni memorije, u ovom slucaju nemamo takvih elemenata pa ce destruktor ovako izgledati

int StrucniIspit::ocena() {
	int ocena = 0; //metoda za racunanje ocene slicna kao prethodna
	ocena = (int)roundf((this->labPoeni + this->pismeni + this->usmeni) / 10); //samo dodajemo i vrednost poena sa Lab vezbi i ostatak je isti kao za metodu u osnovnoj klasi
	if (ocena < 5) {
		ocena = 5;
	}
	return ocena;
}

void StrucniIspit::prikaz() { //metoda za prikaz
	cout << "Ispit: " << this->naziv << endl; //ispisujemo naziv
	cout << "Broj poena na pismenom: " << this->pismeni << endl; //ispisujemo broj poena
	cout << "Broj poena na usmenom: " << this->usmeni << endl;
	cout << "Broj poena na laboratorijskim vezbama: " << this->labPoeni << endl;
	cout << "Ocena: " << ocena() << endl; //prilikom ispisa pozivamo metodu za racunanje ocene i nju ispisujemo
}
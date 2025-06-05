#include "Ispit.h"
#include <iostream>
#include <cstring>
using namespace std;

Ispit::Ispit(const char* naziv, float pismeni, float usmeni) { 
	int duzina = strlen(naziv) + 1; //kreiramo pomocnu promenljivu koja broji koliko mesta ce zauzeti parametar naziv u dinamickoj zoni memorije
	this->naziv = new char[duzina]; //vrsi se dinamicka alokacije, gde se zauzima onoliko mesta u memoriji koliko pomocna promenljiva ima vrednost
	strcpy_s(this->naziv, duzina, naziv); //dodeljujemo vrednost uz pomoc funkcije strcpy

	this->pismeni = pismeni; //klasicno dodeljivanje vrednosti
	this->usmeni = usmeni;
}

Ispit::Ispit() {
	this->naziv = new char[1]; //vrsimo dinamicku alokaciju za jedno mesto u memoriji
	strcpy_s(this->naziv, 1, ""); //upisujemo prazan element
	this->pismeni = 0; //upisujemo podrazumevane vrednosti u ostale elemente sto je u ovom slucaju 0
	this->usmeni = 0;
}

Ispit::~Ispit() {
	delete[]naziv; //brise se element smesten u dinamickoj zoni memorije
}

int Ispit::ocena() {
	int ocena = 0; //kreiramo pomocnu promenljivu u koju cemo smestiti ocenu
	ocena = (int)roundf((this->pismeni + this->usmeni) / 10); //primenjujemo matematicku formulu za racunanje ocene, funckija (int)roundf nam sluzi da zaokruzimo broj na celobrojni tip podataka
	if (ocena < 5) {
		ocena = 5; //ukoliko je ocena manja od 5, onda ce imati vrednost 5 jer je to najmanja ocena na fakultetu
	}
	return ocena; //povratna vrednost nam je ocena
}



#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(const char* ime, const char* prezime, int indeks) { //konstruktor za postavljanje vrednosti
	int duzina = strlen(ime) + 1; //racunamo koliko ce mesta prosledjeni element zauzeti u memoriji
	this->ime = new char[duzina]; //vrsimo dinamicku alokaciju
	strcpy_s(this->ime, duzina, ime); //dodeljujemo vrednosti 

	duzina = strlen(prezime) + 1; //racunamo koliko ce mesta prosledjeni element zauzeti u memoriji
	this->prezime = new char[duzina]; //obavlja se proces dinamicke alokacije
	strcpy_s(this->prezime, duzina, prezime); //dodeljujemo vrednosti

	this->indeks = indeks; //dodeljujemo vrednosti
}

Student::~Student() {
	delete[]ime; //destruktor koji brise elemente koji su zauzeti prilikom dinamicke alokacije
	delete[]prezime;
}

void Student::prikaz() {
	cout << indeks << " " << ime << " " << prezime <<" " << brojBodova() << endl; //metoda za ispis vrednosti, takodje se i ispisuje broj poena zbog poziva metode
}

bool Student::operator<(Student& s) { //logicki operator koji poredi studente na osnovu broja bodova
	return this->brojBodova() < s.brojBodova(); //logicki operator koji vraca vrednost TRUE ili FALSE u zavisnosti od uslova
}

//cisto virtuelna funkcija se ne definise u okviru ovog fajla, vec u okviru CPP fajlova za podklase koje su izvedene iz klase "Student"
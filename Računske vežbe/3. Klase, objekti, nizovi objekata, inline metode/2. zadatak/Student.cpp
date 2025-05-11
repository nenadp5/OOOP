#include "Student.h"
#include <iostream>
#include <cmath>
using namespace std;

void Student::unos() { //metoda za unos svih informacija vezanih za studenta, nemamo prosledjeni element jer direktno radimo sa atributima uz pomoc this->
	cout << "Unesi ime studenta: ";
	cin >> this->ime;
	cout << "Unesi prezime studenta: ";
	cin >> this->prezime;
	cout << "Unesi broj indeksa studenta: ";
	cin >> this->indeks;
	cout << "Unesi broj poena na pismenom delu ispita (0-50): ";
	cin >> this->pismeni;
	cout << "Unesi broj poena na usmenom delu ispita (0-50): ";
	cin >> this->usmeni;
}

void Student::prikaz() { //metoda za prikaz informacija o studentu
	cout << indeks << " " << ime << " " << prezime << " " << ocena(); //ocena() predstavlja metodu koja je definisana u nastavku
}

int Student::ocena() { //metoda za racunanje ocene
	int ocena = (int)roundf((this->pismeni + this->usmeni) / 10); //roundf predstavlja matematicku funkciju koja omogucava zaokruzivanje brojeva
	if (ocena < 5) {
		ocena = 5;
	}
	return ocena;
}
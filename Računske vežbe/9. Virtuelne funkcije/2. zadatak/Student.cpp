#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() { //podrazumevani konstruktor
	strcpy_s(this->ime, ""); //postavljamo vrednosti atributa na prazno, NULL ili 0 u zavisnosti od slucaja
	strcpy_s(this->prezime, ""); //ukoliko je formata char onda ide prazno, ukoliko je niz onda ide NULL i ukoliko je int/float onda ide 0
	this->indeks = 0;
	this->ocene = NULL;
	this->brojPolozenihIspita = 0;
	this->maxBrojIspita = 0;
}

Student::Student(const char* ime, const char* prezime, int indeks, int maxBrojIspita) { //konstruktor za postavljanje vrednosti
	strcpy_s(this->ime, ime); //dodeljujemo vrednosti imena i prezimena uz pomoc funckije iz biblioteke "cstring" koja omogucava rad sa stringovima
	strcpy_s(this->prezime, prezime);
	this->indeks = indeks;
	this->ocene = new int[maxBrojIspita]; //maxBrojIspita predstavlja kapacitet niza jer je tako receno u zadatku, pa na osnovu njega odredjujemo koliko mesta ce zauzeti u memoriji
	this->brojPolozenihIspita = 0; //broj polozenih ispita ne prosledjujemo konstruktoru, vec postavljamo na 0 jer ce se on svakako menjati u okviru sledecih metoda
}

Student::~Student() { //destruktor, koji brise elemente u dinamickoj zoni memorije
	delete[]ocene;
}

void Student::dodajOcenu(int ocena){ //metoda za upisivanje ocene u niz
	this->ocene[brojPolozenihIspita++] = ocena; //kao sto sam rekao broj polozenih ispita se menja, kako upisemo koju ocenu u niz ocena
}

float Student::prosecnaOcena() { //metoda za racunanje prosecne ocene studenta
	float suma = 0; //pomocna promenljiva za sumu
	for (int i = 0; i < this->brojPolozenihIspita; i++) { //vrednost brojaca ide od 0 do broja polozenih ispita, a ne do kapaciteta niza, jer bi racun bio pogresan
		suma += this->ocene[i];
	}
	if (this->brojPolozenihIspita != 0) { //ukoliko ima polozenih ispita, onda vraca odgovarajucu vrednost, dok ukoliko nema polozenih ispita onda vraca 0
		return suma / (float)this->brojPolozenihIspita; //vrsimo transformaciju broja polozenih ispita iz int u float kako bi kompajler bolje funkcionisao
	}
	else {
		return 0.0f;
	}
}

void Student::prikaz(){ //virtuelna metoda za prikaz
	cout << indeks << " " << ime << " " << prezime << " Sa prosecnom ocenom: " << prosecnaOcena() << endl;
}

#include "Student.h"
#include <iostream>
#include <fstream>
#include <cstring> //ukljucujemo sve neophodne biblioteke za rad sa stringovima i fajlovima
using namespace std;

Student::Student() { //podrazumevani konstruktor koji postavlja vrednost parametara na prazno ili 0
	strcpy_s(this->ime, "");
	strcpy_s(this->prezime, "");
	this->indeks = 0;
}

Student::Student(const char* ime, const char* prezime, int indeks) {
	strcpy_s(this->ime, 20, ime); //konstruktor koji postavlja vrednost prosledjenih atributa
	strcpy_s(this->prezime, 20, prezime);
	this->indeks = indeks;
}

void Student::ulazBin(ifstream& ulaz) { //metoda za ucitavanje podataka iz binarnog fajla
	ulaz.read(ime, 20 * sizeof(ime)); //ucitavamo svaki podatak posebno
	ulaz.read(prezime, 20 * sizeof(prezime));
	ulaz.read((char*)&indeks, sizeof(indeks));
}

void Student::izlazBin(ofstream& izlaz) { //metoda za upis podataka u binarni fajl
	izlaz.write(ime, 20 * sizeof(ime)); //upisujemo svaki podataka posebno
	izlaz.write(prezime, 20 * sizeof(prezime));
	izlaz.write((char*)&indeks, sizeof(indeks));
}

ostream& operator<<(ostream& izlaz, const Student& s) { //operator za prikaz podataka na izlazu
	izlaz << s.indeks << " " << s.ime << " " << s.prezime << endl; //ispisuje sve vrednosti o studentu
	return izlaz; //prosledjujemo zajedno sa parametrom const, jer ne treba da menja objekat
}

istream& operator>>(istream& ulaz, Student& s) { //operator za upis podataka
	ulaz >> s.indeks >> s.ime >> s.prezime; //upisuje sve podatke redom
	return ulaz; //ne prosledjujemo sa parametrom const jer se vrednosti prilikom svakog upisa menjaju
}
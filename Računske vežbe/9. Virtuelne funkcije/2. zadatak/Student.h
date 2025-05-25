#pragma once
class Student {
protected: //zasticeni atributi klase "Student"
	char ime[30]; //nije receno da ime i prezime studenta treba da bude u dinamickoj zoni, pa smo shodno tome stavili da bude u statickoj zoni
	char prezime[30];
	int indeks;
	int* ocene; //niz ocena u dinamickoj zoni memorije
	int maxBrojIspita;
	int brojPolozenihIspita;

public:
	Student(); //podrazumevani konstruktor
	Student(const char* ime, const char* prezime, int indeks, int maxBrojIspita); //konstruktor za postavljanje vrednosti
	virtual ~Student(); //virtuelni destruktor

	void dodajOcenu(int ocena); //metoda za dodavanje ocena u niz
	float prosecnaOcena(); //metoda za racunanje prosecne ocene
	virtual void prikaz(); //virtuelna metoda za prikaz
};

//Virtuelne metode su one koje izvedena klasa moze da promeni, a da se i dalje mogu pozivati preko pokazivaca na osnovnu klasu.
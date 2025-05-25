#pragma once
#include "Student.h" //ukljucujemo header "Student.h" jer je "StudentOsnovnihStudija" izvedem iz te klase
class StudentOsnovnih :public Student {
private:
	int godina; //privatni atribut klase "StudentOsnovih"

public:
	StudentOsnovnih(); //podrazumevani konstruktor
	StudentOsnovnih(const char* ime, const char* prezime, int indeks, int maxBrojIspita, int godina); //konstruktor za postavljanje vrednosti
	~StudentOsnovnih(); //destruktor

	float brojIspitaGodisnje(); //metoda za izracunavanje koliko ispita je student polozio godisnje
	
	void upis() { //inline metoda za upis u sledecu godinu
		if (this->godina < 4) { //buduci da je u pitanju student osnovnih studija, maksimalni broj godina je 4, i mi samo vrsimo povecanje godine
			this->godina++;
		}
	}
	void prikaz(); //metoda za prikaz
};
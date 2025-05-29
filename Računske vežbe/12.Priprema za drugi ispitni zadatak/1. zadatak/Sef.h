#pragma once
#include "Radnik.h"
class Sef :public Radnik { //ukljucujemo klasu "Radnik" jer je klasa "Sef" izvedena iz te klase
private:
	char* titula; //radno mesto sefa smesteno u dinamickoj zoni memorije

public:
	Sef(const char* ime, const char* prezime, int jmbg, float plata, const char* titula, Sef* sef = NULL); //konstruktor koji postavlja vrednosti
	~Sef(); //destruktor
	void postaviPlatuRadniku(Radnik& r, float novaPlata); //metoda koja postavlja platu prosledjenom radniku
	friend ostream& operator<<(ostream& izlaz, const Sef& sef); //prijateljska operatorska funkcija za prikaz podataka
};

//kod konstruktora za postavljanje vrednosti,dodelili smo podrazumevanu vrednost NULL za parametar Sef, to znaci da ne mora svaki zaposleni da ima svog sefa (sto je upravo slucaj sa direktorom)
#pragma once
#include <iostream>
using namespace std;
class Slika {
private:
	float* nizR; //niz za crvenu boju smesten u dinamickoj zoni memorije
	float* nizG; //niz za zelenu boju smesten u dinamickoj zoni memorije
	float* nizB; //niz za plavu boju smesten u dinamickoj zoni memorije
	int maxBr; //maksimalni broj boja, odnosno dimenzija niza
	int trBr; //trenutni broj boja, odnosno trenutni broj vrednosti u nizu
public:
	Slika(int maxBr, int trBr, float* nizR, float* nizG, float* nizB); //konstruktor za postavljanje vrednosti
	Slika(); //podrazumevani konstruktor
	Slika(const Slika& original); //konstruktor za kopiranje
	~Slika(); //destruktor

	float srednjeR() const; //metoda za racunanje srednje vrednosti crvene boje
	float srednjeG() const; //metoda za racunanje srednje vrednosti zelene boje
	float srednjeB() const; //metoda za racunanje srednje vrednosti plave boje
	float prebaciUSivu() const; //metoda koja racuna nijansu sive

	Slika& operator=(const Slika& druga); //operator za dodelu vrednosti trenutnom objektu od strane prosledjenog objekta
	Slika& operator++(); //prefiksni operator za uvecanje vrednosti
	Slika operator--(int n); //postfiksni operator za smanjenje vrednosti

	Slika operator+(const Slika& druga); //operator koji sabira trenutni objekat sa prosledjenim
	friend ostream& operator<<(ostream& izlaz, const Slika& s); //pijateljska operatorska funkcija za prikaz podataka na izlazu
};
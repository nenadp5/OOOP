#pragma once
#include <iostream>
using namespace std;
class Radnik { //kreiramo klasu "Radnik"
private: //privatni atributi klase
	char* ime; //ime radnika smesteno u dinamickoj zoni memorije
	char* prezime; //prezime radnika smesteno u dinamickoj zoni memorije
	float* niz; //niz radnih sati smesten u dinamickoj zoni memorije
	int maxBr; //maksimalni broj radnih dana u nizu, odnosno dimenzija niza
	int trBr; //trenutni broj elemenata u nizu
	float cenaPoSatu;
public:
	Radnik(const char* ime, const char* prezime, int maxBr, int trBr, float cenaPoSatu, float* niz); //konstruktor za postavljanje vrednosti
	Radnik(); //podrazumevani konstruktor
	Radnik(const Radnik& original); //konstruktor za kopiranje
	~Radnik(); //destruktor

	float zarada() const; //metoda za racunanje zarade svakog radnika

	Radnik& operator=(const Radnik& drugi); //operator dodele vrednosti drugom objektu tipa "Radnik"
	Radnik operator++(int n); //postfiksni operator za uvecanje vrednosti zarade po satu
	Radnik& operator--(); //prefiksni operator za smanjenje vrednosti zarade po satu
	Radnik& operator+=(float sat); //operator za dodelu vrednosti u niz

	friend bool operator>(const Radnik& prvi,const Radnik& drugi); //prijateljska operatorska funkcija za poredjenje dva radnika na osnovu toga ko ima vecu zaradu
	friend ostream& operator<<(ostream& izlaz, const Radnik& radnik); //prijateljska operatorska funkcija za prikaz rezultata
	friend istream& operator>>(istream& ulaz, Radnik& radnik); //prijateljska operatorska funkcija za unos podataka
};
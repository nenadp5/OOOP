#pragma once
#include <iostream> //moramo ukljuciti biblioteku "iostream" i u okviru klase kako bi smo mogli iskoristiti operacije istream i ostream
using namespace std;
class Vektor {
private: //privatni atributi klase Vektor
	int trBr;
	float* niz;

public: //javni atributi klase Vektor
	Vektor(int trBr); //Konstruktor za postavljanje vrednosti
	Vektor(const Vektor& original); //Konstruktor za kopiranje
	Vektor(); //podrazumevani konstruktor
	~Vektor(); //destruktor

	Vektor operator+(const Vektor& v); //operator za sabiranje dva vektora
	Vektor operator+(float skalar); //operator za sabiranje vektora sa skalarnom vrednoscu

	Vektor& operator++(); //operator za prefiksno inkrementiranje
	Vektor operator++(int n); //operator za postfiksno inkrementiranje
	Vektor& operator=(const Vektor& v); //operator za dodelu vrednosti drugog vektora

	friend Vektor operator+(float broj, const Vektor& v); //prijateljska operatorska funkcija koja omogucava da se saberu skalar i vektor

	friend ostream& operator<<(ostream& izlaz, const Vektor& v); //prijateljska operatorska funkcija za prikaz (izlaz)
	friend istream& operator>>(istream& ulaz, Vektor& v); //prijateljska operatorska funkcija za unos vrednosti
};
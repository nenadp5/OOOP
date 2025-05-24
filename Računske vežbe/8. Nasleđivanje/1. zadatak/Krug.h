#pragma once
#define PI 3.14; //definisemo konstantu koju cemo cesto koristiti
class Krug {
private: //privatni atributi klase 
	double r;

public: //javni atributi klase
	Krug(); //podrazumevani konstruktor
	Krug(double r); //konstruktor koji postavlja vrednosti
	~Krug(); //destruktor

	double Povrsina(); //metoda za racunanje povrsine
	double Obim(); //metoda za racunanje obima
	void prikaz(); //metoda za prikaz
};
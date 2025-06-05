#pragma once
class Radnik { //kreiramo osnovnu klasu "Radnik"
protected: //zasticeni atributi klase
	char* ime; //parametar ime koji ce biti smesten u dinamickoj zoni memorije
	float cenaRadnogSata;
	float brSati;

public: //javni atributi klase
	Radnik(); //podrazumevani konstruktor
	Radnik(const char* ime, float cenaRadnogSata, float brSati); //konstruktor koji postavlja vrednosti
	virtual ~Radnik(); //virtuelni destruktor
	virtual float plata(); //virtuelna metoda za racunanje plate
	virtual void prikaz(); //virtuelna metoda za prikaz
};
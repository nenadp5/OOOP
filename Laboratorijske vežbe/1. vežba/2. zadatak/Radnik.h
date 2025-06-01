#pragma once
class Radnik { //kreiramo klasu Radnik
private: //privatni atributi klase Radnik
	char* ime; //ime radnika smesteno u dinamickoj zoni memorije
	char* prezime; //prezime radnika smesteno u dinamickoj zoni memorije
	float* niz; //niz realnih vrednosti smesten u dinamickoj zoni memorije 
	int maxBr; //celoborojna vrednost koja predstavlja dimenzije niza
	int trBr; //celobrojna vrednost koja predstavlja trenutni broj elemenata niza

public:
	static float zaradaPoSatu; //javni staticki atribut
	Radnik(const char* ime, const char* prezime, float* niz, int maxBr, int trBr); //konstruktor za postavljanje vrednosti
	Radnik(); //podrazumevani konstruktor
	Radnik(const Radnik& original); //konstruktor za kopiranje
	~Radnik(); //destruktor
	
	void prikaz(); //metoda za prikaz
	float ukupnaZarada(); //metoda koja racuna ukupnu zaradu
};
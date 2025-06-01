#pragma once
class Slika { //kreiramo klasu "Slika"
private: //privatni atributi klase
	int* Rniz; //celobrojni niz, u dinamickoj zoni memorije, koji predstavlja crvenu boju
	int* Gniz; //celobrojni niz, u dinamickoj zoni memorije, koji predstavlja zelenu boju
	int* Bniz; //celobrojni niz, u dinamickoj zoni memorije, koji predstavlja plavu boju
	int maxBr; //maksimalni broj elemenata koji predstavlja dimenziju niza
	int trBr; //trenutni broj elemenata u nizu

public:
	Slika(int* Rniz, int* Gniz, int* Bniz, int maxBr, int trBr); //konstruktor koji postavlja vrednosti
	Slika(); //podrazumevani konstruktor
	Slika(const Slika& original); //konstruktor za kopiranje
	~Slika(); //destruktor

	float RSrednje(); //metoda za nalazenje srednje vrednosti za crvenu boju
	float GSrednje(); //metoda za nalazenje srednje vrednosti za zelenu boju
	float BSrednje(); //metoda za nalazenje srednje vrednosti za plava boju

	float prebaciUSivu(); //metoda koja racuna vrednost sive boje
	void prikaz(); //metoda za prikaz
};
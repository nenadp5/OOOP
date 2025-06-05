#pragma once
class Ispit { //kreiramo klasu "Ispit"
protected: //zasticeni atributi klase
	char* naziv; //naziv koji je smesten u dinamickoj zoni memorije
	float pismeni; //ostali elementi koji su smesteni u dinamickoj zoni memorije
	float usmeni;
public:
	Ispit(const char* naziv, float pismeni, float usmeni); //konstrutkor koji postavlja vrednosti
	Ispit(); //podrazumevani konstruktor
	virtual ~Ispit(); //virtuelni destruktor
	virtual int ocena(); //virtuelna metoda za racunanje ocene
	virtual void prikaz() = 0; //cista virtuelna funckija za prikaz podataka
};
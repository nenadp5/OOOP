#pragma once
class Film { //kreiramo klasu Film
protected: //zasticeni atributi klase
	char* naslov; //naslov koji ce biti smesten u dinamickoj zoni memorije
	int brojGledalaca; //broj gledalaca i cena smesteni u statickoj zoni memorije
	float cena;
public:
	Film(const char* naslov,int brojGledalaca,float cena); //konstruktor koji postavlja vrednosti
	Film(); //podrazumevani konstruktor
	virtual ~Film(); //virtuelni destruktor
	virtual float prihod(); //virtuelna metoda za racunanje prihoda
	virtual void prikaz() = 0; //cista virtuelna funkcija za prikaz svih poadataka
};
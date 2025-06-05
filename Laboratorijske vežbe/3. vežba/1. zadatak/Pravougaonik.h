#pragma once
class Pravougaonik { //kreiramo klasu "Pravougaonik" koja je osnovna klasa i nije izvedena 
protected: //zasticeni atributi klase
	float a; //stranice pravougaonika koje su smestene u dinamickoj zoni memorije
	float b;

public: //javni atributi klase
	Pravougaonik(); //podrazumevani konstruktor
	Pravougaonik(float a, float b); //konstruktor za postavljanje vrednosti
	virtual float povrsina(); //virtuelna metoda za racunanje povrsine
	virtual void prikaz(); //virtuelna metoda za prikaz vrednosti
};
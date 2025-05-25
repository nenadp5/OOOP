#pragma once
#define PI 3.14; //definisemo promenljivu koju cemo cesto koristiti
class Krug {
protected: //zasticeni atributi klase "Krug"
	float r;

public: //javni atributi klase "Krug"
	Krug(float r); //konstruktor koji postavlja vrednosti
	Krug(const Krug& original); //konstruktor za kopiranje
	~Krug(); //destruktor
	float povrsina(); //metoda za racunanje povrsine
	virtual void prikaz(); //virtuelna metoda za prikaz
};

//Virtuelne metode su one koje izvedena klasa moze da promeni, a da se i dalje mogu pozivati preko pokazivaca na osnovnu klasu.
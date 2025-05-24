#pragma once
#include "Krug.h" //ukljucujemo header fajl "Krug" jer je klasa "ObojeniKrug" izvedena iz klase "Krug"
#include <iostream>
using namespace std;
class ObojeniKrug :public Krug { //na ovaj nacin se obavlja definisanje kada je jedna klasa izvedena od druge
private: //privatni atributi klase "ObojeniKrug"
	int red;
	int green;
	int blue;

public: //javni atributi klase
	ObojeniKrug(); //podrazumevani konstruktor
	ObojeniKrug(double r, int red, int green, int blue); //konstruktor koji postavlja vrednosti, iako nemamo u privatnim atributima r, mozemo ga koristiti zato sto je prisutan u klasi "Krug" od koje je izvedena ova klasa
	~ObojeniKrug(); //destruktor
	
	void prikaz() { //inline metoda za prikaz
		Krug::prikaz(); //pozivamo metodu za prikaz iz klase "Krug" i dodajemo jos neophodnih informacija
		cout << "Boje su: " << endl;
		cout << "Crvena: " << this->red << " Zelena: " << this->green << " Plava: " << this->blue;
		cout << endl << endl;;
	}
};

/* Najbolji nacin za shvatanje nasladjivanje je da zamislis kako u stvarnom svetu stvari mogu biti podvrste drugih stvari (Pas -> Sisar -> Zivotinja),
i kako svaka "dete" kategorija nasledjuje opste osobine svojih "roditelja". Koriscenjem nasledjivanja, optimizujemo kod i nema potrebe da dva puta pisemo iste stvari.*/
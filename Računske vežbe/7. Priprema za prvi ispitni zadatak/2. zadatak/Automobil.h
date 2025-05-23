#pragma once
#include <iostream> //ukljucujemo ovu biblioteku kako bismo mogli da koristimo istream i ostream operatore
using namespace std;
class Automobil {
private: //privatni atributi klase Automobil
	char naziv[30]; //nije receno da naziv bude smesten u dinamickoj zoni memorije, pa smo ga shodno tome smestili u staticki deo
	int godina;
	float cena;

public:
	
	Automobil(const char* naziv, int godina, float cena); //konstruktor koji postavlja sve vrednosti
	~Automobil(); //destruktor

	int vratiGodinu() { //inline metoda za vracanje godine proizvodnje automobila
		return this->godina;
	}

	float vratiCenu() { //inline metoda za vracanje cene automobila
		return this->cena;
	}

	friend ostream& operator<<(ostream& izlaz, const Automobil& a); //prijateljska operatorska funkcija za prikaz
};

//u tekstu zadatka nije receno koji su privatni i javni atributi klase "Automobil", to trebamo sami da odredimo na osnovu elemenata koje smo koristili u klasi "Parking" 
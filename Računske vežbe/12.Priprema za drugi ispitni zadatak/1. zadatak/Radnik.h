#pragma once
#include <iostream> //ukljucujemo biblioteku za rad sa standardnim ulazom i izlazom
using namespace std;
class Sef; //ukljucujemo klasu "Sef"

class Radnik {
private: //privatni atributi klase "Radnik"
	char* ime; //ime i prezime radnika koje je smesteno u dinamickoj zoni memorije
	char* prezime;
	int jmbg;
	float plata; 
	Sef* sef; //pokazivac na element klase "Sef" koji omogucava postavljanje Sefa tom radniku

public:
	Radnik(const char* ime, const char* prezime, int jmbg, float plata, Sef* sef); //konstruktor koji postavlja vrednosti
	virtual ~Radnik(); //virtuelni destruktor

	friend ostream& operator<<(ostream& izlaz, const Radnik& r); //prijateljska operatorska funkcija za prikaz svih podataka
	bool operator==(const Radnik& drugi); //operator koji proverava da li su JMBG brojevi prosledjenog i trenutnog radnika isti, ovo nam je korisno zbor kasnije provere oko sefa

	void postaviPlatu(float plata) {
		this->plata = plata;  //inline metoda za postavljanje plate
	}

	float vratiPlatu() {
		return plata; //inline metoda koja vraca platu
	}

	void postaviSefa(Sef* sef) {
		this->sef = sef; //inline metoda koja postavlja sefa
	}

	Sef* vratiSefa() {
		return this->sef; //inline metoda koja vraca sefa, vracenja promenljiva je tipa Sef i zato u inicijalizaciji imamo Sef*
	}
};
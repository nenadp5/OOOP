#include "Parking.h"
#include <iostream>
#include <cstring>
using namespace std;

Parking::Parking() { //podrazumevani konstruktor koji postavlja vrednosti svih atributa na 0 ili prazno ukoliko je u pitanju string
	this -> trBr = 0;
	strcpy_s(this->adresa, 30, " ");
}

Parking::Parking(const char* adresa) { //konstruktor za postavljanje vrednosti
	strcpy_s(this->adresa, 30, adresa); //nema potrebe za prethodnim racunanjem duzine, jer je sve smesteno u statickoj zoni memorije
	this->trBr = 0;
}

Parking::~Parking(){} //iako nije receno u tekstru, nista ne skodi da za svaki slucaj imamo prisutan destruktor

Parking& Parking::operator+=(Automobil& a) { //operator za dodavanje automobila na parking, imamo prisutan operator &, kako ne bi nastajale bespotrebne kopije objekata, vec se izmene vrsile direktno u memoriji
	if (trBr < 50) { //proveravamo da li ima mesta na parkingu na osnovu trenutnog broja
		Automobili[trBr] = &a; //ukoliko ima mesta, dodajemo automobil (odnosno sve informacije za njega, celu jednu memorijsku celinu uz pomoc &) i uvecavamo broj zauzetih mesta
		trBr++;
	}
	else {
		cout << "Greska! Parking je pun"; //ukoliko je sve popunjeno, ispisujemo poruku
	}
	return *this; //povratna vrednost nam je *this, odnosno pokazivac na Parking
}

Automobil* Parking::najskuplji() const{ //odredjujemo najskuplji automobil na parkingu
	Automobil *najskuplji = Automobili[0]; //kreiramo pomocnu promenljivu u koju smestamo prvi element iz niza i njega smatramo najskupljim
	for (int i = 0; i < this->trBr; i++) {
		if (Automobili[i]->vratiCenu() > najskuplji->vratiCenu()) { //prolazimo kroz ceo niz automobila, svaki automobil prosledjujemo metodi iz klase "Automobil" koja omogucava vracanje cene i vrsimo njihovo poredjenje
			najskuplji = Automobili[i]; //kada naidje skuplji automobil od prethodnog, onda se vrsi zamena
		}
	}
	return najskuplji; //vracamo najskuplji automobil i uz pomoc * iz definicije sve njegove propratne vrednosti
}

int Parking::brojNovijih(int godina) { //metoda za odredjivanje broja novijih automobila, u odnosu na prosledjenu godinu
	int broj = 0; //kreiramo pomocnu promenljivu u koju smestamo broj novijih vozila
	for (int i = 0; i < this->trBr; i++) { //prolazimo kroz ceo niz automobila
		if (Automobili[i]->vratiGodinu() > godina) { //prilikom prolaska svaki automobil prosledjujemo metodi iz klase "Automobil" koja vraca godinu nastanka automobila
			broj++; //uvecavamo brojac kada naidje automobil sa novijim godistem
		}
	}
	return broj; //povratna vrednost je broj novijih automobila
}

ostream& operator<<(ostream& izlaz, const Parking& p) { //prijateljska operatorska funkcija za prikaz svih informacija o parkingu
	izlaz << "Parking na adresi: " << p.adresa << endl << "Sa brojem vozila: " << p.trBr << endl;;
	for (int i = 0; i < p.trBr; i++) { //imamo dodatu petlju kako bi mogli da prikazemo i sve automobile koji su na parkingu
		izlaz << *p.Automobili[i]; //vrednosti niza se prosledjuju operatoru za prikaz iz klase "Automobil", zbog toga i prosledjujemo sa zvezdicom
	}
	izlaz << "Gde je najskuplji automobil: " << *p.najskuplji(); //ponovo se dobijena vrednost prosledjuje operatoru za prikaz iz klase "Automobil" i zato prosledjujemo sa zvezdicom
	return izlaz;
}
#include "Biblioteka.h"
#include "Knjiga.h"
#include <iostream>
using namespace std;

Biblioteka::Biblioteka() { //podrazumevani konstruktor koji postavlja vrednost privatnih atributa na 0
	this->trBr = 0;
}

Biblioteka::~Biblioteka(){} //iako nije receno u tekstru zadatka, moramo uvek imati destruktor

void Biblioteka::dodaj(Knjiga& k) { //metoda za dodavanje knjiga, prosledjuje joj se cela promenljiva tipa Knjiga
	if (trBr < 100) { //proveravamo da li je biblioteka puna
		niz[trBr] = &k; //ukoliko nije dodajemo prosledjenu knjigu u biblioteku i povecavamo trenutni broj knjiga
		trBr++;
	}
	else {
		cout << "Popunjena je biblioteka! "; //ukoliko je ispunjena samo ispisujemo poruku
	}
}

void Biblioteka::prikaz() { //metoda za prikaz knjiga koje su u biblioteci
	for (int i = 0; i < trBr; i++) {
		niz[i]->prikaz(); //prosledjujemo element u niz (odnosno knjigu) metodi za prikaz (ta metoda je smestena u klasi Knjiga), koristimo -> jer je svaka knjiga pokazivackog tipa
		cout << endl;
	}
}

void Biblioteka::uredi() { //metoda koja uredjuje knjige u biblioteci po imenu autora
	for (int i = 0; i < trBr - 1; i++) {
		int iMin = i; //trenutni element se smatra najmanjim
		for (int j = i + 1; j < trBr; j++) { //uvodimo dodatni brojac koji ide korak ispred trenutnog elementa i prolazi kroz ceo niz
			if (strcmp(niz[iMin]->vratiAutora(), niz[j]->vratiAutora()) > 0) { //uz pomoc metode za vracanje imena autora iz klase knjiga, u kombinaciji sa funkcijom strcmp poredimo vrednosti trenutnog najmanjeg elementa i elementa posle njega
				iMin = j; //ukoliko se razlikuju vrsi se dodela vrednosti
			}
		}
		if (iMin != i) { //kada se iMin razlikuje od trenutnog, odnosno ukoliko se desila promena u toku prethodne provere vrsi se zamena
			Knjiga* tmp = niz[iMin]; //kreiramo novu promenljivu tipa Knjiga koja ce poprimiti elemente minimalnog clana
			niz[iMin] = niz[i]; //nakon toga sledi proces zamene elemenata kao sto je uvek do sada radjeno
			niz[i] = tmp;
		}
	}
}
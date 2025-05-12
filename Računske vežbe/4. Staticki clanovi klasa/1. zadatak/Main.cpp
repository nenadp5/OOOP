#include <iostream>
#include "Proizvod.h"
using namespace std;

int main() {
	Proizvod niz[100]; //kreiramo niz u koji smestamo maksimalno 100 elemenata tipa Proizvod
	int n;
	cout << "Unesi koliko proizvoda ima: ";
	cin >> n;
	
	float pdv; //kreiramo pomocnu promenljivu za PDV
	cout << "Unesi koliko iznosi PDV: ";
	cin >> pdv;
	Proizvod::postaviPDV(pdv); //pozivamo metodu za postavljanje cene PDV, buduci da je u pitanju staticka metoda ona se poziva na ovakav nacin
	
	for (int i = 0; i < n; i++) {
		char pomNaziv[20]; //kreiramo pomocne promenljive za naziv i cenu koje kasnije prosledjujemo odgovarajucim metodama
		float pomCena;
		cout << "Unesi naziv proizvoda: ";
		cin >> pomNaziv;
		cout << "Unesi cenu proizoda: ";
		cin >> pomCena;
		niz[i].postaviNaziv(pomNaziv); //prosledjujemo svaki element niza metodi za postavljanje naziva i cene
		niz[i].postaviCenu(pomCena);
	}
	float ukupnaCena = 0; //kreiramo pomocnu promenljivu za ukupnu cenu svih proizvoda
	for (int i = 0; i < n; i++) {
		ukupnaCena += niz[i].cenaSaPDV(); //svaki element niza prosledjujemo metodi za racunanje ukupne cene zajedno sa PDV
	}
	cout << endl;
	cout << "Ukupna cena svih proizvoda je: " << ukupnaCena << endl;
	
	return 0;
}
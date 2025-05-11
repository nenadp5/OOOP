#include "Tacka.h"
#include <iostream>
using namespace std;
int main() {
	Tacka niz[100]; //kreiramo niz tacaka u statickoj zoni memorije
	float pomX, pomY; //pomocne promenljive
	int n;
	cout << "Unesi koliko tacaka ima vas niz: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "Unesi X koordinatu trenutne tacke: ";
		cin >> pomX;
		cout << "Unesi Y koordinatu trenutne tacke: ";
		cin >> pomY;
		niz[i].postaviX(pomX); //unosimo X i Y koordinatu za svaku tacku u nizu, jer svaki element niza zapravo predstavlja tacku
		niz[i].postaviY(pomY);
	}

	float duzina=0; //pomocna promenljiva za duzinu
	for (int i = 0; i < n - 1; i++) { //kod odredjivanja duzine idemo od prve do predzadnje tacke, zato sto zadnja tacka nema nisakim da se upari
		duzina += niz[i].rastojanje(niz[i + 1]); //metoda za racunanje rastojanje, kojoj prosledjujemo tacku i sledecu tacku u odnosu na prethodnu prosledjenu
	}

	cout << endl;
	cout << "Duzina izlomenljene linije unetih tacaka je: " << duzina;
	return 0;
}
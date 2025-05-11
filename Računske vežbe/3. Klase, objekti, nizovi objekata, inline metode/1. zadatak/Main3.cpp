#include <iostream>
#include "Tacka.h"
using namespace std;
int main() {
	float pomX, pomY;
	int n;
	Tacka* niz; //kreiramo promenljivu niz koja je tipa Tacka i koja ce kasnije biti smestena u dinamickoj zoni memorije
	
	cout << "Unesi koliko tacaka ima vas niz: ";
	cin >> n;
	niz = new Tacka[n]; //niz se smesta u dinamicku zonu memorije i zauzima onoliko mesta koliko ima tacaka u nizu
	
	for (int i = 0; i < n; i++) {
		cout << "Unesi X koordinatu trenutne tacke: ";
		cin >> pomX;
		cout << "Unesi Y koordinatu trenutne tacke: ";
		cin >> pomY;
		niz[i].postaviX(pomX); //metoda za postavljanje vrednosti
		niz[i].postaviY(pomY); //koristimo tacku (.) jer niz[i] predstavlja objekat u statickoj zoni memorije, bez obzira sto je niz u dinamickoj zoni memorije
	}

	float duzina = 0;
	for (int i = 0; i < n - 1; i++) { //kod odredjivanja duzine idemo od prve do predzadnje tacke, zato sto zadnja tacka nema nisakim da se upari
		duzina += niz[i].rastojanje(niz[i + 1]); //metoda za racunanje rastojanje, kojoj prosledjujemo tacku i sledecu tacku u odnosu na prethodnu prosledjenu
	}
	cout << endl;
	cout << "Duzina izlomljene linije nastala od unetih tacaka je: " << duzina;
	
	delete[]niz; //oslobadjamo memoriju koja je zauzeta dinamickom alokacijom za niz
	return 0;
}
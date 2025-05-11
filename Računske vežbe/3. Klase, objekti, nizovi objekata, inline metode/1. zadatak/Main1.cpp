#include <iostream>
#include "Tacka.h"
using namespace std;
int main() {
	Tacka t1; //kreiramo promenljivu tipa Tacka u statickoj zoni memorije
	float pomX, pomY; //kreiramo pomocne promenljive koje ce nam kasnije koristiti za unos parametara
	cout << "Unesi X koordinatu prve tacke: ";
	cin >> pomX;
	cout << "Unesi Y koordinatu prve tacke: ";
	cin >> pomY;
	t1.postaviX(pomX); //koristimo metode za postavljanje koordinate prve tacke
	t1.postaviY(pomY); //buduci da se radi o statickoj zoni memorije onda se za pristup metodama koristi tacka (.)

	Tacka* t2 = new Tacka; //kreiramo promenljivu tipa Tacka u dinamickoj zoni memorije, koja ce zauzimati onoliko mesta koliko zauzima promenljiva tipa Tacka
	cout << "Unesi X koordinatu druge tacke: ";
	cin >> pomX;
	cout << "Unesi Y koordinatu druge tacke: ";
	cin >> pomY;
	t2->postaviX(pomX); //koristimo metode za postavljanje koordinate druge tacke
	t2->postaviY(pomY); //buduci da se radi o dinamickoj zoni memorije onda se za pristup metodama koristi operator strelica (->)

	t1.pomeri(1, 0); //metoda za pomeranje tacke (staticka memorija, pa se shodno tome koristi tacka)
	t2->pomeri(0, 1); //metoda za pomeranje tacke(dinamicka memorija, pa se shodno tome koristi ->)

	cout << endl;
	float distanca;
	distanca = t2->rastojanje(t1); //kreirali smo dodatnu promenljivu za racunanje distance i primenili odgovarajucu metodu
	cout << "Rastojanje izmedju unetih tacaka je: " << distanca;

	delete t2; //oslobadjanje memorijskog prostora koje je zauzeto dinamickom alokacijom za tacku t2
	return 0;
}
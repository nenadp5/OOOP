#include "FudbalskiKlub.h"
#include <iostream>
using namespace std;
int main() {
	const char* naziv = "Partizan"; //kreiramo pomocne promenljive u koje mi upisujemo vrednosti
	int niz[] = { 3,3,1,0 }; //kasnije ove promenljive prosledjujemo konstruktoru
	int maxBr = 6;
	int trBr = 4;

	FudbalskiKlub F1(naziv, niz, maxBr, trBr); //kreiramo promenljivu tipa FudbalskiKlub i odmah pozivamo konstruktor za dodelu vrednosti
	cout << endl << "Podaci o orignalnom klubu: " << endl;
	F1.prikaz(); //pozivamo metodu za prikaz

	FudbalskiKlub Kopija(F1); //Kreiramo novu promenljivu tipa FudbalskiKlub tako sto pozovemo konstruktor za kopiranje i prosledjujemo originalni fudbalski klub
	cout << endl << "Podaci o kopiji kluba: " << endl;
	Kopija.prikaz(); //pozivamo metodu za prikaz, koja prikazuje informacije

	return 0;
}
#include "FudbalskiKlub.h"
#include <iostream>
using namespace std;
int main() {

	FudbalskiKlub F1; //kreiramo promenljive tipa "FudbalskiKlub"
	FudbalskiKlub F2;
	cout << "Unesi elemente prvog fudbalskog kluba: " << endl;
	cin >> F1; //uz pomoc operatora>> vrsimo unos vrednosti
	cout << endl;
	cout << "Unesi elemente drugog fudbalskog kluba: " << endl;
	cin >> F2; //uz pomoc operatora>> vrsimo unos vrednosti bez potrebe da prethodno imamo bilo kakve pomocne promenljive

	F1 += 3; //uz pomoc operatora+= dodajemo vrednosti u niz
	F1 += 1;
	F1 += 0;
	F2 += 1;
	F2 += 1;
	F2 += 1;
	

	cout << endl;
	if (F1 < F2) { //pozivamo logicki operator koji odredjuje koji klub ima vise bodova
		cout << "Bolji fudbalski klub je: ";
		cout << F2; //uz pomoc operatora<< vrsimo prikaz vrednosti u svega jednoj liniji koda
	}
	else {
		cout << "Bolji fudbalski klub je: ";
		cout << F1;
	}

	return 0;
}
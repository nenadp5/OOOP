#include "Vektor.h"
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	Vektor V1; //kreiramo promenljivu tipa vektor
	cin >> V1; //unosimo vrednosti vektora
	cout << V1;
	cout << endl;

	V1.izlazBin("Vektor1.bin"); //unete vrednosti vektora upisujemo u binarni fajl uz pomoc metode za rad sa binarnim fajlovima
	V1.izlazTxt("Vektor1.txt"); //unete vrednosti vektora upisujemo u tekstualni fajl uz pomoc metode za rad sa tekstualnim fajlovima

	Vektor V2; //kreiramo novu promenljivu tipa vektor
	V2.ulazTxt("Vektor1.txt"); //vrednosti za novu promenljivu ucitavamo iz tekstualnog fajla, u koji smo prethodno upisali elemente
	cout << V2; //prikazujemo elemente vektora
	cout << endl;
	V2.izlazBin("Vektor2.bin"); //potom vrednosti vektora V2 upisujemo u novi binarni fajl uz pomoc metode za rad sa binarnim fajlovima

	Vektor V3; //kreiramo novu promenljivu tipa vektor 
	V3.ulazBin("Vektor2.bin"); //ucitavamo vrednosti iz binarnog fajl
	V3.izlazTxt("Vektor3.txt"); //ucitane vrednosti odmah upisujemo u novi tekstualni fajl

	return 0;
}

/* Dakle prvo rucno unesemo vrednosti za vektor V1, nakon toga te vrednosti upisemo u binarni i tekstualni fajl
Vrednosti za vektor V2 cemo ucitati iz fajla "Vektor1" gde su prethodno smesteni elementi vektora V1, potom te ucitane vrednosti smestamo u binari fajl "Vektor2"
V3 dobija vrednosti iz fajla "Vektor2" i odmah ih upisuje u fajl "Vektor3". Dakle na kraju ce biti upisane iste vrednosti unetih elemata u sve fajlove.
Neophodno je imati vec kreirane fajlove!
*/
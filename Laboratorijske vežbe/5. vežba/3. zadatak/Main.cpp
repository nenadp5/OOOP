#include "Klinika.h"
#include "Lekar.h"
#include <iostream>
using namespace std;
int main() {
	Klinika K1; //kreiramo prvu promenljivu tipa "Klinika"
	K1.ulazTxt("Klinika1.txt"); //ucitavamo podatke iz unapred pripremljenog tekstualnog fajla
	K1.izlazBin("Klinika1.bin"); //prethodno ucitane podatke upisujemo u binarni fajl

	Klinika K2; //kreiramo drugu promenljivu tipa "Klinika"
	K2.ulazBin("Klinika1.bin"); //ucitavamo podatke iz prethodnog binarnog fajla
	K2.izlazTxt("Klinika2.txt"); //ispisujemo podatke u novi tekstualni fajl

	return 0;
}

/* Na kraju bi trebalo da fajl "Klinika1.txt" i "Klinika2.txt" imaju isti sadrzaj
Neophodno je da fajlovi imaju isti naziv kao i u okviru main programa i da budu unapred kreirani!*/
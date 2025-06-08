#include "Firma.h"
#include "Radnik.h"
#include <iostream>
using namespace std;
int main() {
	Firma F1; //kreiramo prvu promenljivu tipa "Firma"
	F1.ulazTxt("Firma1.txt"); //ucitavamo podatke iz unapred pripremljenog tekstualnog fajla
	F1.izlazBin("Firma1.bin"); //prethodno ucitane podatke upisujemo u binarni fajl

	Firma F2; //kreiramo drugu promenljivu tipa "Firma"
	F2.ulazBin("Firma1.bin"); //ucitavamo podatke iz prethodnog binarnog fajla
	F2.izlazTxt("Firma2.txt"); //ispisujemo podatke u novi tekstualni fajl
	return 0;
}

/* Na kraju bi trebalo da fajl "Firma1.txt" i "Firma2.txt" imaju isti sadrzaj
Neophodno je da fajlovi imaju isti naziv kao i u okviru main programa i da budu unapred kreirani!*/
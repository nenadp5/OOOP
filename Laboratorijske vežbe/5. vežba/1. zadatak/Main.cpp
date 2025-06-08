#include "Prodavnica.h"
#include "Proizvod.h"
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	Prodavnica P1; //kreiramo prvu promenljivu tipa "Prodavnica"
	P1.ulazTxt("PrvaProdavnica.txt"); //ucitavamo podatke iz unapred pripremljenog tekstualnog fajla
	P1.izlazBin("PrvaProdavnica.bin"); //prethodno ucitane podatke upisujemo u binarni fajl

	Prodavnica P2; //kreiramo drugu promenljivu tipa "Prodavnica"
	P2.ulazBin("PrvaProdavnica.bin"); //ucitavamo podatke iz prethodnog binarnog fajla
	P2.izlazTxt("DrugaProdavnica.txt"); //ispisujemo podatke u novi tekstualni fajl

	return 0;
}

/* Na kraju bi trebalo da fajl "PrvaProdavnica.txt" i "DrugaProdavnica.txt" imaju isti sadrzaj
Neophodno je da fajlovi imaju isti naziv kao i u okviru main programa i da budu unapred kreirani!*/
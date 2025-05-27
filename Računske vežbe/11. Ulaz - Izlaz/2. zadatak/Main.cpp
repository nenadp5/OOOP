#include "Ucionica.h"
#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	Ucionica U1; //kreiramo promenljivu tipa ucionica
	
	ifstream ulazTxt("Ucionica1.txt"); //otvaramo tekstualni fajl direktno
	if (ulazTxt) { 
		ulazTxt >> U1; //ukoliko je fajl uspesno otvoren onda se uz pomoc operatora za upis upisuju podaci
	}
	ulazTxt.close(); //zatvaramo fajl
	cout << U1 << endl; //prikazujemo upisane podatke na monitor
	U1.izlazBin("Ucionica.bin"); //pozivamo metodu za upis u binarni fajl

	Ucionica U2; //kreiramo novu promenljivu tipa ucionica
	U2.ulazBin("Ucionica.bin"); //ucitavamo podatke iz binarnog fajla
	ofstream izlazTxt("Ucionica2.txt"); //direktno otvaramo novi tekstualni fajl
	if (izlazTxt) {
		izlazTxt << U2; //vrsimo upis elemenata u novootvoreni tekstualni fajl
	}
	izlazTxt.close(); //zatvaramo fajl

	return 0;
}

//kao rezultat, u svim fajlovima treba da budu isti podaci
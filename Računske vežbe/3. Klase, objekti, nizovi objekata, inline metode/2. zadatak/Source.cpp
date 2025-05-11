#include <iostream>
#include "Student.h"
using namespace std;
int main() {
	int n, i;
	Student niz[100]; //kreiramo niz tipa Student u statickoj zoni memorije
	
	cout << "Unesi koliko je studenata u pitanju: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		niz[i].unos(); //uz pomoc metode omogucavamo unos svih informacija za svakog studenta posebno
	}
	cout << endl;
	
	cout << "Niz studenata izlgeda: " << endl;
	for (i = 0; i < n; i++) {
		niz[i].prikaz();  //uz pomoc metode prikazuju nam se sve informacije o svakom studentu
		cout << endl;
	}

	Student* max = &niz[0]; //smatramo da je prvi student u nizu najbolji, pa novonastaloj promenljivoj prosledjujemo memorijsku lokaciju prvog studenta
	for (i = 1; i < n; i++) {
		if (niz[i].ocena() > max->ocena()) { //poredimo svakog sledeceg studenta sa najboljim studentom, tako sto prosledjujemo studenta metodi ocena() na analizu, buduci da je max pokazivac metodi za ocenu pristupamo uz pomoc strelice (->)
			max = &niz[i]; //kada naidje bolji student, promenljiva max pamti tu memorijsku lokaciju i sve podatke koji su na njoj smesteni
		}
	}
	cout << endl;
	cout << "Najbolji student je: ";
	max->prikaz(); //ispisujemo najboljeg studenta, buduci da je max pokazivac onda je neophodno da metodi pristupimo uz pomoc stelice
	
	return 0;
}
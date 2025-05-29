#include <iostream>
#include "Student.h"
#include "Brucos.h"
#include "StudentViseGodine.h"
#include "Konkurs.h"
using namespace std;
int main() {
	int akcija; //kreiramo promenljivu koja nam predstavlja uslov u okviru while petlje
	cout << "Unesi neku od sledecih vrednosti: 0 - Izlaz / 1 - Brucos / 2 - Student vise godine ";
	cin >> akcija;
	Konkurs K; //kreiramo promenljivu tipa Konkurs
	while (akcija != 0) {
		char ime[20];
		char prezime[20];
		int indeks;
		float ocene;
		if (akcija == 1) { //ukoliko unesemo 1, onda unosimo podatke o brucosu
			cout << "Unesi podatke o brucosu (ime,prezime,indeks,prosecna ocena iz srednje skole): ";
			cin >> ime >> prezime >> indeks >> ocene; //kreirali smo pomocne promenljive u koje smestamo vrednosti za brucosa
			Student* B = new Brucos(ime, prezime, indeks, ocene); //kreiramo studenta u dinamickoj zoni memorije, i odmah pozivamo odgovarajuceg konstruktora za postavljanje vrednosti
			K.dodajStudenta(B); //dodajemo studenta u niz uz pomoc metode
		}
		else if (akcija == 2) { //ukoliko unesemo 2, onda unosimo podatke o starijem studentu
			cout << "Unesi podatke o starijem studentu (ime,prezime,indeks,prosecna ocena,godina studija, broj zaostalih ispita): ";
			int godina; //kreiramo dodatne promenljive koje su vezane za starijeg studenta 
			int ostaliIspiti;
			cin >> ime >> prezime >> indeks >> ocene >> godina >> ostaliIspiti; //unosimo vrednosti za studenta
			Student* S = new StudentViseGodine(ime, prezime, indeks, ocene, godina, ostaliIspiti); //kreiramo studenta u dinamickoj zoni memorije i pozivamo odgovarajuci konstruktor
			K.dodajStudenta(S); //dodajemo studenta u konkurs
		}
		cout << "Unesi neku od sledecih vrednosti: 0 - Izlaz / 1 - Brucos / 2 - Student vise godine ";
		cin >> akcija; //ponovo unosimo vrednost koja nam predstavlja uslov kod while petlje
	}
	cout << endl;
	K.prikaz(); //pozivamo metodu za prikaz, gde se prikazuju uneti elementi
	cout << endl;
	K.sortiraj(); //pozivamo metodu za sortiranje
	cout << endl;
	K.prikaz(); //pozivamo metodu za sortiranje, gde se prikazuju sortirani elementi

	return 0;
}
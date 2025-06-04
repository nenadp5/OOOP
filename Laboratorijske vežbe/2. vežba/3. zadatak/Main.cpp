#include "Slika.h"
#include <iostream>
using namespace std;
int main() {
	float niz1[] = { 120,125,130,135,150 }; //kreiramo pomocne nizove za boje
	float niz2[] = { 150,155,160,165,170 }; //moramo kreirati dodatne promenljive jer se samo ovako direktno u okviru programa mogu uneti vrednosti
	float niz3[] = { 180,190,200,222,255 };
	Slika S1(10, 5, niz1, niz2, niz3); //kreiramo promenljivu tipa "Slika" uz pomoc konstruktora i prosledjujemo odgovarajuce vrednosti

	float niz4[] = { 122,129,133,140,146 }; //kreiramo pomocne nizove za boje
	float niz5[] = { 153,162,163,166,177 };
	float niz6[] = { 186,192,210,220,250 };
	Slika S2(10, 5, niz4, niz5, niz6); //kreiramo promenljivu tipa "Slika" uz pomoc konsturktora i prosledjujemo odgovarajuce vrednosti

	cout << endl << "Informacije o prvoj slici: " << endl;
	cout << S1; //koristimo operator za prikaz vrednosti
	cout << endl << "Informacije o drugoj slici: " << endl;
	cout << S2;
	cout << endl;

	cout << "Uvecavamo vrednosti za prvu sliku... Prikaz: " << endl;
	++S1; //koristimo prefiksni operator za povecanje vrednosti niza
	cout << S1; //koristimo operator za prikaz i ispisujemo uvecanu vrednost prvog parametra

	cout << endl;
	cout << "Sabiramo vrednosti uvecanje prve slike i osnovne druge slike: " << endl;
	Slika S3 = S1 + S2; //kreiramo novu promenljivu tipa "Slika" koja nastaje sabiranjem prve i druge slike uz pomoc operatora+
	cout << S3; //uz pomoc operatora<< ispisujemo vrednosti nove slike

	return 0;
}
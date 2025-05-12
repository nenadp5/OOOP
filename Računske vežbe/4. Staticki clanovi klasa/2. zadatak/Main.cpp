#include <iostream>
#include "Vozilo.h"
using namespace std;
int main() {
	Vozilo::postaviOgranicenje(); //postavljamo vrednosti za staticke atribute, buduci da nista ne prosledjujemo, oni poprimaju vrednosti koje su definisane u okviru klase
	
	Vozilo V1; //kreiramo promenljivu tipa Vozilo
	V1.postaviNaziv("Audi"); //postavljamo naziv i brzinu uz pomoc definisanih metoda
	V1.postaviBrzinu(100);
	cout << "Vozilo " << V1.vratiNaziv() << " je provelo na putu " << V1.ukupnoVreme(10, 30, 100) << endl; //prosledjujemo metodi "ukupnoVreme" kilometrazu koliko je automobil presao na putevima, ne moramo sve tri vrednosti da prosledimo, mozemo neku i da izostavimo

	Vozilo V2; //kreiramo drugu promenljivu takodje tipa Vozilo
	V2.postaviNaziv("Mercedes");
	V2.postaviBrzinu(); //buduci da nismo nista prosledili, maksimalna brzina se postavlja na onu koja je definisana u okviru klase a to je 220
	cout << "Vozilo " << V2.vratiNaziv() << " je provelo na putu " << V2.ukupnoVreme(10, 30, 100) << endl;
	//ponovo ponavljam, za metodu "ukupnoVreme" ne moramo sve vrednosti da prosledimo, mozda se vozilo nije kretalo autoputem pa ce onde linija koda izgledati "V2.ukupnoVreme(10, 30)" , za poslednju vrednost bice dodeljena ona koja je definisana u okviru klase, a to je 0
	return 0;
}
#include <iostream>
#include "Lekar.h"
using namespace std;

ostream& operator<<(ostream& izlaz, const Lekar& l) {
	izlaz << l.ime << " "; //prolazimo kroz celu klasu i ispisujemo njene elemente
	izlaz << l.plata << " "; //imamo prisutno const jer prilikom ispisa ne treba da se menjaju vrednosti
	izlaz << l.brSati << " ";
	izlaz << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Lekar& l) {
	ulaz >> l.ime; //operator koji omogucava unos podataka
	ulaz >> l.plata; //nemamo parametar const jer se vrse izmene objekta
	ulaz >> l.brSati;
	return ulaz;
}
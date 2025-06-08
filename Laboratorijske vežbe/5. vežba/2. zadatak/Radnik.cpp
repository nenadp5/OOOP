#include "Radnik.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& izlaz, const Radnik& radnik) {
	izlaz << radnik.ime << " " << radnik.prezime << " " << radnik.JMBG << " " << radnik.plata << endl;
	return izlaz; //prolazimo kroz celu klasu i ispisujemo njene elemente
} //imamo prisutno const jer prilikom ispisa ne treba da se menjaju vrednosti

istream& operator>>(istream& ulaz, Radnik& radnik) {
	ulaz >> radnik.ime;
	ulaz >> radnik.prezime; //operator koji omogucava unos podataka
	ulaz >> radnik.JMBG; //nemamo parametar const jer se vrse izmene objekta
	ulaz >> radnik.plata;
	return ulaz;
}
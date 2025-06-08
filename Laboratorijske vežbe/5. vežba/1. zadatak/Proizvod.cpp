#include "Proizvod.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& izlaz, const Proizvod& pr) {
	izlaz << pr.naziv << " " << pr.cena << " " << pr.kod << endl;
	return izlaz; //prolazimo kroz celu klasu i ispisujemo njene elemente
}  //imamo prisutno const jer prilikom ispisa ne treba da se menjaju vrednosti

istream& operator>>(istream& ulaz, Proizvod& pr) {
	ulaz >> pr.naziv; //operator koji omogucava unos podataka
	ulaz >> pr.cena; //nemamo parametar const jer se vrse izmene objekta
	ulaz >> pr.kod;
	return ulaz;
}
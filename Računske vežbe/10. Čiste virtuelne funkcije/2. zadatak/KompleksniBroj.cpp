#include "KompleksniBroj.h"
#include <iostream>
using namespace std;

bool KompleksniBroj::operator>(KompleksniBroj& broj) { 
	return this->moduo() > broj.moduo(); //logicki operator koji vraca vrednost TRUE ili FALSE u zavisnosti od uslova
} //ukoliko je moduo trenutnog broja veci od prosledjenog onda vraca vrednost TRUE, dok u suprotnom vraca FALSE

/*da se primetiti da nismo definisali nigde ciste virtuelne funkcije za moduo i prikaz,
to je zato sto je neophodno da se one uvedu i definisu u podklasama bez obzira sto to nije trazeno u tekstu zadatka */
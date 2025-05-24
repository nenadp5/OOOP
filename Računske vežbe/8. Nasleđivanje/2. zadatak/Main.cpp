#include "Kamion.h"
#include "Avion.h"
#include "Vozilo.h"
#include <iostream>
using namespace std;
int main() {
	Avion A(12000); //kreiramo promenljivu tipa "Avion" i dodajemo joj maksimalnu visinu leta
	A.ubrzaj(); //pozivamo metodu iz klase "Vozilo" ovo mozemo ovako uraditi jer je klasa "Avion" izvedena iz klase "Vozilo"
	A.povecajVisinu(); //pozivamo metodu iz klase "Avion"
	A.uspori();
	A.smanjiVisinu();
	cout << endl;

	Kamion K(3000); //kreiramo promenljivu tipa "Kamion" i dodeljujemo vrednost nosivosti
	K.dodajTeret(1000); //pozivamo metodu iz klase "Kamion" koja omogucava dodavanje tereta
	K.ubrzaj(); //pozivamo metodu iz klase "Vozilo" ovo mozemo ovako uraditi jer je klasa "Kamion" izvedena iz klase "Vozilo"
	K.uspori();
	K.ukloniTeret(400);
	cout << endl;

	return 0;
}
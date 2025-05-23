#include "Bioskop.h" //ukljucujemo sve neophodne biblioteke i header fajlove
#include "Film.h"
#include <iostream>
using namespace std;
int main() {
	Bioskop B("Delta Planet"); //kreiramo promenljivu tipa bioskop uz pomoc odgovarajuceg konstruktora
	Film F1("Poslednji", 21, 30,120);
	Film F2("Prvi", 12, 10, 150); //kreiramo promenljive tipa film uz pomoc njihovih konstruktora
	Film F3("Srednji", 16, 15, 140);
	
	B + F1 + F2 + F3; //dodajemo filmove u bioskop uz pomoc operatora+ iz klase Bioskop
	cout << endl;
	cout << B; //obavljamo prikaz svih vrednosti za bioskop uz pomoc operatora<< iz klase Bioskop
	cout << endl << endl;
	cout << "Uredjen bioskop na osnovu vremena pocetka projekcije: " << endl;;
	B.sort(); //pozivamo metodu za sortiranje i ponovo ispisujemo sve o bioskopu
	cout << B;
	cout << endl << endl;;
	cout << "Prosecno trajanje filma u bioskopu je: "<<B.prosecnoTrajanje(); //ispisujemo prosecno trajanje filma koje smo dobili tako sto smo pozvali metodu namenjenu za to
	return 0;

}
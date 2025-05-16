#include "Knjiga.h"
#include <iostream>
using namespace std;
int main() {
	char naslov[40], autor[40], zemlja[4]; //kreiramo pomocne promenljive koje kasnije prosledjujemo konstruktorima prilikom kreiranja promenljivih tipa knjiga
	int godina, izdanje;
	cout << "Unesi naslov knjige: ";
	cin >> naslov;
	cout << "Unesi ime autora: ";
	cin >> autor;
	cout << "Unesi zemlju porekla knjige: ";
	cin >> zemlja;
	cout << "Unesi godinu nastanka knjige: ";
	cin >> godina;
	cout << "Unesi broj izdanja knjige: ";
	cin >> izdanje;

	Knjiga k1(naslov, autor, godina, zemlja, izdanje);
	k1.prikaz(); //prosledjujemo promenljivu tipa knjiga metodi za prikaz
	cout << endl;
	
	if (k1.podZastitom() > 0) { //zbog logickih uslova stavljamo da mora da bude vece od 0, kako bi vrednost bila TRUE
		cout << "Knjiga je pod zastitom";
	}

	Knjiga novak2 = k1.narednoIzdanje();
	novak2.prikaz(); //novonastalu knjigu prosledjujemo metodi za prikaz

	return 0;
}
/* Objasnjenje za "Knjiga novak2 = k1.narednoIzdanje()" 
Kreirali smo novu promenljivu "novak2" koja je tipa klase Knjiga
Ona nastaje tako sto metodi "narednoIzdanje" prosledimo sve vrednosti promenljive k1 gde ta metoda vrsi izmene u vidu
godine izdanja, broja izdanja i vraca promenjene vrednosti nazad ka novok2 */
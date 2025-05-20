#include <iostream>
#include "Complex.h"
using namespace std;
int main() {
	double r, i; //kreiramo pomocne elemente koje kasnije prosledjujemo konstruktoru za kreiranje
	cout << "Unesi realni deo prvog kompleksnog broja: ";
	cin >> r;
	cout << "Unesi imaginarni deo prvog kompleksnog broja: ";
	cin >> i;
	Complex A(r, i); //kreiramo prvi kompleksni broj
	cout << "Unesi realni deo drugog kompleksnog broja: ";
	cin >> r;
	cout << "Unesi imaginarni deo drugog kompleksnog broja: ";
	cin >> i;
	Complex B(r, i); //kreiramo drugi kompleksni broj
	cout << endl;

	Complex zbir = A + B; //kreiramo novi kompleksni broj koji nastaje kao zbir prethodna dva uz pomoc operatora za sabiranje
	cout << "Zbir ova dva kompleksa broja je: ";
	zbir.prikaz(); //novi kompleksni broj prosledjujemo metodi za prikaz
	cout << endl;

	Complex proizvod = A * B; //kreiramo novi kompleksni broj koji nastaje kao proizvod prethodna dva uz pomoc operatora za sabiranje
	cout << "Prozivod ova dva kompleksa broja je: ";
	proizvod.prikaz(); //novi kompleksni broj prosledjujemo metodi za prikaz
	cout << endl;

	if (A > B) {
		cout << "Prvi kompleksni broj je veci od drugog!";
	}
	else if (A < B) {
		cout << "Drugi kompleksni broj je veci od prvog!";
	}
	else if (A == B) {
		cout << "Brojevi su jednaki!";
	}
	cout << endl;

	cout << "Moduo prvog kompleksnog broja: " << A.moduo() << endl;
	cout << "Moduo drugog kompleksnog broja: " << B.moduo() << endl;
	cout << "Inkrementiranje (prefiksno) prvog kompleksnog broja: ";
	(++A).prikaz(); //prefiksno inkrementiranje
	cout << endl;
	cout << "Inkrementiranje (postfiksno) prvog kompleksnog broja: ";
	(A++).prikaz(); //postfiksno inkrementiranje, kod ovog ispisa nista se nece razlikovati od prethodnog
	cout << endl;
	cout << "Sledeci prikaz prvog kompleksnog broja: ";
	A.prikaz(); //dok ce se ovde vec prikazati promena koja je nastala kod postfiksnog inkrementiranja
	cout << endl;


	A = B;
	cout << "Dodeljena vrednost je: ";
	A.prikaz();
	return 0;
}
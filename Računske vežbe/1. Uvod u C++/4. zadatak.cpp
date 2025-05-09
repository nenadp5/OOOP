#include <iostream>
using namespace std;
int main() {
	int A; //kreiranje celobrojne promenljive u statičkoj zoni memorije
	cout << "Unesi vrednost broja A: ";
	cin >> A; //unos vrednosti promenljive A

	int* B; //kreiranje celobrojne promenljive u dinamičkoj zoni memorije
	B = new int; //promenljiva b zauzima onoliko mesta u memoriji koliko zauzima promenljiva tipa int
	cout << "Unesi vrednost broja B: ";
	cin >> *B; //unos vrednosti promenljive B

	int* aPok; //kreiranje pokazivača za promenljivu A
	aPok = &A; //dodela memorijske lokacije pokazivaču za promenljivu A

	cout << "Vrednost broja A je: " << A << endl;
	cout << "Memorijska adresa broja A je: " << aPok << endl;
	cout << "Vrednost broja B je: " << *B << endl;
	cout << "Memorijska adresa broja B je: " << B << endl;;

	cout << "Zbir brojeva A i B je: " << A + *B << endl;
	cout << "Zbir brojeva A i B preko pokazivaca je: " << *aPok + *B << endl;

	delete B; //oslobadjamo memorijski prostor koji je bio zauzet dinamičkom alokacijom promenljive B
	return 0;
}

/*Kod ispisa vrednosti promenljive B stavljamo *B da bi nam pokazalo vrednost unutar memorijske lokacije,
dok kod ispisa adrese ne stavljamo to, jer nam je neophodna memorijska lokacija*/
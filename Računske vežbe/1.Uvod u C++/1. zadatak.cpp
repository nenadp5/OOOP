#include <iostream>
using namespace std;
int main() {
	int a, b; //kreiranje celobrojnih promenljivih
	cout << "Unesi vrednost broja A: ";
	cin >> a;
	cout << "Unesi vrednost broja B: ";
	cin >> b;

	int* aPok; //kreiranje promenljivih za memorijske adrese (pokazivača) prethodno unetih brojeva
	int* bPok;

	aPok = &a; //pokazivačima dodeljujemo memorijske lokacije promenljivih A i B
	bPok = &b;

	cout << "Vrednost broja A je: " << a << endl;
	cout << "Memorijska adresa broja A je: " << aPok << endl;
	cout << "Vrednost broja B je: " << b << endl;
	cout << "Memorijska adresa broja B je: " << bPok << endl;

	cout << "Zbir brojeva A i B je: " << a + b << endl;
	cout << "Zbir brojeva A i B preko pokazivaca je: " << *aPok + *bPok << endl;

	return 0;
}

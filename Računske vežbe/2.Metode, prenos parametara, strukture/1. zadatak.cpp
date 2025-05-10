#include <iostream>
using namespace std;
int main() {
	int A = 5; //kreiranje promenljive A
	int B = A; //kreiranje promenljive B kao kopija vrednosti promenljive A

	cout << "Vrednosti promenljivih A i B pre bilo kakvih promena, A=" << A << " B=" << B << endl;
	
	B++;
	cout << "Vrednosti promenljivih nakon uvecanja vrednosti jedne promenljive, A=" << A << " B=" << B << endl;
	
	int& C = A; //kreiranje promenljive C kao referenca na promenljivu A
	C++;
	cout << "Vrednosti promenljivih nakon uvecanja druge promenljive, A=" << A << " B=" << B << " C=" << C << endl;
	
	cout << "Adrese promenljivih, A=" << &A << " B=" << &B << " C=" << &C << endl;
	return 0;
}
/* Kod komande B++, ta promena se odnosi samo na B (prikaz ce biti A=5 B=6), nece biti prikaza promenljive C jer ona jos nije uvedena
Kod komande C++, ta promena se odnosi i na promenljivu A jer dele isti memorijski prostor (prikaz ce biti A=6 B=6 C=6)
Kod ispisa memorijskih adresa, A i C dele istu memorijsku adresu, pa ce shodno tome biti ispisane iste adrese, dok ce B imati razlicitu adresu */
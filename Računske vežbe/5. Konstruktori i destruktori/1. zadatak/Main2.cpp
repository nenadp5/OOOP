#include "Tacka.h"
#include <iostream>
using namespace std;
int main() {
	Tacka niz[100]; //kreiramo niz tacaka u statickoj zoni memorije
	int n;
	cout << "Unesi koliko elemenata ima vas niz: ";
	cin >> n;
	float argX, argY; //pomocne promenljive koje kasnije prosledjujemo metodama
	
	for (int i = 0; i < n; i++) {
		cout << "Unesi X koordinatu tacke: ";
		cin >> argX;
		cout << "Unesi Y koordinatu tacke: ";
		cin >> argY;
		niz[i].postaviX(argX); //za svaku tacku u nizu postavljamo X i Y koordinatu
		niz[i].postaviY(argY);
	}
	
	float duzina = 0; //pomocna promenljiva za duzinu
	for (int i = 0; i < n-1; i++) { //ide se do pretposlednjeg elementa, jer poslednji element nema sa kim da se upari
		duzina += niz[i].rastojanje(niz[i + 1]);
	}
	
	cout << endl;
	cout << "Duzina izlomljene linije nastala od unetih tacka je: " << duzina;
	return 0;
}
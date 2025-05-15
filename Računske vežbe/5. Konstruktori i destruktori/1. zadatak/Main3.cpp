#include <iostream>
#include "Tacka.h"
using namespace std;
int main() {
	Tacka* niz[20]; //kreiramo niz pokazivaca tipa tacka
	int n;
	cout << "Unesi koliko elemenata ima vas niz: ";
	cin >> n;
	float argX, argY; //pomocne promenljive koje kasnije prosledjujemo metodama i konstruktorima
	
	for (int i = 0; i < n; i++) {
		cout << "Unesi X koordinatu tacke: ";
		cin >> argX;
		cout << "Unesi Y koordinatu tacke: ";
		cin >> argY;
		niz[i] = new Tacka(argX, argY); //za svaku tacku u nizu kreiramo novu promenljivu uz pomoc konstruktora za dodelu vrednosti
	}
	
	float duzina = 0;
	for (int i = 0; i < n - 1; i++) { //duzina se racuna do pretposlednje tacke, jer poslednja tacka nema sa cime da se upari
		duzina+=niz[i]->rastojanje(*niz[i + 1]); //koristimo operator strelice, takodje i u zagradi prosledjujemo pokazivac (odnosno prisutna je *) jer je svaka tacka u nizu zapravo smestena u dinamickoj zoni memorije
	}
	
	cout << endl;
	cout << "Duzina izlomenljene linije nastala od unetih tacaka je: " << duzina;
	
	for (int i = 0; i < n; i++) {
		delete niz[i]; //oslobadjamo memoriju koja je zauzeta prilikom dinamicke alokacije, svaka tacka u nizu se posebno brise jer svaka predstavlja poseban deo u memoriji
	}
	return 0;
}
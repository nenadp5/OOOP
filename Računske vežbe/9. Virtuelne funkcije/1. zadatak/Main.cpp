#include "Krug.h"
#include "Valjak.h"
#include <iostream>
using namespace std;
int main() {
	Krug K1(7); //kreiramo promenljivu Krug u statickoj zoni memorije
	Valjak V1(4, 5); //kreiramo promenljivu Valjak u statickoj zoni memorije
	K1.prikaz(); //pozivamo metode za prikaz
	V1.prikaz();
	cout << endl;

	Krug* K2; //kreiramo promenljive za Krug i Valjak u dinamickoj zoni memorije
	Krug* K3;
	K2 = new Krug(7); //pozivamo konstruktore za postavljanje vrednosti
	K3 = new Valjak(4, 5);
	K2->prikaz(); //pozivamo metode za ispis rezultata, u ovom slucaju ce se sve lepo ispisati jer je metoda prikaz virtuelna metoda
	K3->prikaz();
	cout << endl;

	cout << "Povrsina kruga je: " << K2->povrsina() << endl;  //ovde ce biti problem prilikom ispisa, ispisace rezultat za krug, jer je K3 promenljiva tipa "Krug" i ne pokazuje na valjak
	cout << "Povrsina valjka je: " << K3->povrsina() << endl; //bez virtuelne metode poziva se metoda osnovne klase "Krug" za izracunavanje povrsine, kako bi se ovaj problem resio, neophodno je da metoda "povrsina" bude virtuelna
	delete K2;
	delete K3; //oslobadjamo memorijski prostor zauzet prilikom dinamicke alokacije
	cout << endl;

	Krug* K4 = new Krug(7); //kreiramo novu promenljivu tipa Krug
	Valjak* V2 = new Valjak(4, 5); //kreiramo novu promenljivu tipa Valjak
	cout << "Povrsina kruga je: " << K4->povrsina() << endl;
	cout << "Povrsina valjka je: " << V2->povrsina() << endl; //ovde ce sve ispravno raditi, zato sto smo rekli da je V2 promenljiva tipa Valjak i onda zna na koju metodu treba da prosledi vrednosti
	delete K4;
	delete V2; //oslobadjamo metodu zauzetu prilikom dinamicke alokacije
	cout << endl;

	return 0;
}
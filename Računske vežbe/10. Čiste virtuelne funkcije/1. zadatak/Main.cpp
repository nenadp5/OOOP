#include "GeometrijskaFigura.h"
#include "Krug.h" //ukljucujemo sve neophodne biblioteke i header fajlove za rad
#include "Kvadrat.h"
#include <iostream>
using namespace std;
int main() {
	int n,i;
	cout << "Unesi koliko geometrijskih tela je u pitanju: ";
	cin >> n; //unosimo koliko geometrijskih tela je u pitanju

	GeometrijskaFigura** niz = new GeometrijskaFigura * [n]; //kreiramo pokazivac na pokazivace i dinamicki alociramo prostor za pokazivace

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) { //na parnim mestima u nizu se unose krugovi
			cout << "Unesi poluprecnik kruga: ";
			float r;
			cin >> r;
			niz[i] = new Krug(r); //kreiramo i vrsimo dinamicku alokaciju za vrednost u nizu
		}
		else { //na neparnim mestima u nizu se unose kvadrati
			cout << "Unesi stranicu kvadrata: ";
			float a;
			cin >> a;
			niz[i] = new Kvadrat(a); //kreiramo i vrsimo dinamicku alokaciju za vrednost u nizu
		}
	}

	for (i = 0; i < n; i++) {
		niz[i]->prikaz(); //pozivamo metodu za prikaz, posebno za svaki element u nizu
		cout << endl;
	}

	for (i = 0; i < n; i++) {
		delete niz[i]; //oslobadjamo prostor koji je zauzet u dinamickoj alokaciji za svaki element niza posebno, jer je svaki posebno alociran
	}

	delete []niz; //nakon toga brisemo celokupan niz jer je i on smesten u dinamickoj zoni
	return 0;
}

/* Objasnjenje za "GeometrijskaFiruga**niz=new GeomtrijskaFigura*[n]"
1) GeometrijskaFigura* - Ovo je pokazivac na objekat GeometrijskaFigura;
2) GeometrijskaFigura** - Ovo je pokazivac na pokazivac, tj dvostruki pokazivac. Koristi se za kreiranje niza pokazivaca na objekte tipa GeometrijskaFigura;
3) new GeometrijskaFigura*[n] - Dinamicki alocira prostor za n pokazivaca na objekte tipa GeometrijskaFigura.
*/
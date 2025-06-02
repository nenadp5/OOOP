#include "Film.h"
#include "CrtaniFilm.h"
#include <iostream> //ukljucujemo neophodne metode za rad
using namespace std;
int main() {
	Film* niz[4]; //niz od 4 pokazivaca na filmove
	niz[0] = new CrtaniFilm("Top Gun", 25, 950, 0, 0); //kreiramo sve promenljive da budu tipa CrtaniFilm jer je Film apstraktna klasa i onda ne mozemo na ovaj nacin da je kreiramo
	niz[1] = new CrtaniFilm("Crvenkapa", 15, 800, 10, 0.2); //kada kreiramo Film samo vrednosti za decu i popust stavimo na 0 i na taj nacin dobijamo odgovarajuce vrednosti
	niz[2] = new CrtaniFilm("Paklene ulice", 17, 770, 0, 0);
	niz[3] = new CrtaniFilm("Sundjer Bob", 12, 850, 9, 0.3);

	for (int i = 0; i < 4; i++) {
		niz[i]->prikaz(); //prolazimo kroz ceo niz i pozivamo metodu za prikaz svakog filma
		cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		delete niz[i]; //oslobadjamo memoriju koju smo zauzeli dinamickom alokacijom
	}

	return 0;

}
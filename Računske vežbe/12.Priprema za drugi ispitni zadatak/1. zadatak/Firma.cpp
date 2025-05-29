#include "Firma.h"
#include <iostream>
using namespace std;

Firma::Firma() { //podrazumevani konstruktor koji postavlja vrednosti na 0
	n = 0;
}

void Firma::dodajRadnika(Radnik& r) {
	niz[n] = &r; //metoda koja dodaje prosledjenog radnika u firmu i povecava broj zaposlenih mesta
	n++;
}

float Firma::zbir() { //metoda za racunanje ukupne plate
	float suma = 0; //kreiramo pomocnu promenljivu
	for (int i = 0; i < n; i++) {
		suma += niz[i]->vratiPlatu(); //prolazimo kroz ceo niz, i za svakog radnika pozivamo metodu koja vraca platu i vrsimo njihovo sumiranje
	}
	return suma;
}

Radnik* Firma::direktor() { //metoda koja pronalazi direktora
	Radnik* direktor = NULL; //kreiramo pomocnu promenljivu koja je prazna i u koju ce biti smestene vrednosti direktora
	for (int i = 0; i < n; i++) {
		if (niz[i]->vratiSefa() == NULL) { //prolazimo kroz ceo niz i trazimo slucaj kada metoda koja vraca sefa vraca praznu vrednost,
			direktor = niz[i]; //to znaci da zaposleni nema nadredjenog i da je on glavni odnosno direktor
		} //vrsi se dodela tog elementa pomocnoj promenljivoj i na kraju je ta pomocna promenljiva povratna vrednost
	}
	return direktor;
}

Radnik* Firma::maxPlata(Sef& sef) { //metoda koja nalazi radnika sa najvecom platom pod okriljem prosledjenog sefa
	Radnik* max = NULL; //kreiramo pomocnu promenljivu koja je prazna
	for (int i = 0; i < n; i++) {
		if (niz[i]->vratiSefa() != NULL && *(niz[i]->vratiSefa()) == sef) { //objasnjenje ispod, uglavnom proveravamo da li je to prosledjeni sef
			if (max == NULL) {
				max = niz[i]; //Ako još nismo postavili max, tj. prvi put nailazimo na radnika pod ovim sefom — postavljamo max na tog radnika
			}
			else if (niz[i]->vratiPlatu() > max->vratiPlatu()) { //ukoliko smo nasli radnika sa vecom platom, vrsimo poredjenje sa ostalim elementima niza
				max = niz[i]; 
			}
		}
	}
	return max; //na kraju vracamo podatak tipa Radnik koji sadrzi sve neophodne informacije
}

/* Objasnjenje za metodu koja trazi radnika sa najvecom platom:
niz[i]->vratiSefa() != NULL` — Radnik ima sefa
*(niz[i]->vratiSefa()) == sef` — Taj sef je bas **isti** kao sef koji je prosle?en u funkciju (pore?enje se vrši pomocu `operator==`, koji poredi JMBG)
*/
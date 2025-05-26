#include "KompleksniBroj.h"
#include "DekartovKompleksniBroj.h"
#include "PolarniKompleksniBroj.h"
#include "Kolekcija.h"
#include <iostream>
int main() {
	Kolekcija K; //kreiramo promenljivu tipa Kolekcija

	K.dodaj(new DekartovKompleksniBroj(1, 2)); //dodajemo dekartove kompleksne brojeve
	K.dodaj(new DekartovKompleksniBroj(2, 3)); //odmah prilikom poziva kreiramo i odgovarajuce kompleksne brojeve 
	K.dodaj(new DekartovKompleksniBroj(6, 4));

	K.dodaj(new PolarniKompleksniBroj(4, 45)); //kreiramo polarne kompleksne brojeve
	K.dodaj(new PolarniKompleksniBroj(5, 23)); //odmah prilikom poziva kreiramo i odgovarajuce kompleksne brojeve
	K.dodaj(new PolarniKompleksniBroj(3, 30));


	K.prikaz(); //prikazujemo sve kompleksne brojeve
	K.sort(); //pozivamo funkciju za sortiranje brojeva
	K.prikaz(); //nakon izvrsenog sortiranja ponovo prikazujemo brojeve
	return 0;
}
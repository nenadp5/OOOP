#pragma once
#include "Vozilo.h"
class Kamion :public Vozilo { //kreiramo klasu "Kamion" koja je izvedena iz klase "Vozilo"
private: //privatni atributi klase
	float masaTereta;
	float nosivost;

public: //javni atributi klase
	Kamion(float nosivost); //konstruktor koji postavlja nosivost
	void dodajTeret(float masa); //metoda za dodavanje tereta kojeg prosledimo iz glavnog programa
	void ukloniTeret(float masa); //metoda za uklanjanje tereta kojeg prosledimo iz glavnog programa
};
/* Najbolji nacin za shvatanje nasladjivanje je da zamislis kako u stvarnom svetu stvari mogu biti podvrste drugih stvari (Pas -> Sisar -> Zivotinja),
i kako svaka "dete" kategorija nasledjuje opste osobine svojih "roditelja". Koriscenjem nasledjivanja, optimizujemo kod i nema potrebe da dva puta pisemo iste stvari.*/
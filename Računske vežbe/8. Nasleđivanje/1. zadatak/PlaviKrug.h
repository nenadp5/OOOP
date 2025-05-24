#pragma once
#include "ObojeniKrug.h" //ukljucujemo header fajl "ObojeniKrug" jer je klasa "PlaviKrug" izvedena iz klase "ObojeniKrug"
class PlaviKrug :public ObojeniKrug { //nema privatnih atributa jer sve koristi iz klase "ObojeniKrug"
public:
	PlaviKrug(); //podrazumevani konstruktor
	PlaviKrug(double r, int plava); //konstruktor koji postavlja vrednosti
	~PlaviKrug(); //destruktor
};
/* Najbolji nacin za shvatanje nasladjivanje je da zamislis kako u stvarnom svetu stvari mogu biti podvrste drugih stvari (Pas -> Sisar -> Zivotinja),
i kako svaka "dete" kategorija nasledjuje opste osobine svojih "roditelja". Koriscenjem nasledjivanja, optimizujemo kod i nema potrebe da dva puta pisemo iste stvari.*/
#pragma once
#include "Vozilo.h"
class Avion : public Vozilo { //kreiramo klasu "Avion" koja je nastala od klase "Vozilo"
private: //privatni atributi klase "Avion"
	float visina;
	float MaxVisina;

public: //javni atributi klase
	Avion(float MaxVisina); //konstruktor koji postavlja maksimalnu visinu
	void povecajVisinu(); //metoda koja povecava visinu
	void smanjiVisinu(); //metoda koja smanjuje visinu
};
/* Najbolji nacin za shvatanje nasladjivanje je da zamislis kako u stvarnom svetu stvari mogu biti podvrste drugih stvari (Pas -> Sisar -> Zivotinja),
i kako svaka "dete" kategorija nasledjuje opste osobine svojih "roditelja". Koriscenjem nasledjivanja, optimizujemo kod i nema potrebe da dva puta pisemo iste stvari.*/
#include "Avion.h"
#include <iostream>
using namespace std;

Avion::Avion(float MaxVisina) { //konstruktor koji postavlja vrednosti
	this->MaxVisina = MaxVisina;
	this->visina = 0;
}

void Avion::povecajVisinu() { //metoda koja poveca visinu
	if (this->visina < MaxVisina) { //prvo proveravamo da trenutna visina ne predje maksimalnu dozvoljenu visinu
		cout << "Povecavamo visinu..." << endl;
		visina++; //potom uvecavamo visinu i ispisujemo odgovarajucu poruku
		cout << "Trenutna visina je: " << visina << endl;
	}
	else {
		cout << "Nije moguce povecati visinu, jer bi presla maksimalnu dozvoljenu! ";
	}
}

void Avion::smanjiVisinu() {
	if (this->visina > 0) { //proveravamo da li je moguce smanjiti visinu
		cout << "Smanjujem visinu..." << endl;
		visina--; //smanjimo trenutnu visinu i ispisujemo odgovarajucu poruku
		cout << "Trenutna visina je: " << visina << endl;
	}
}


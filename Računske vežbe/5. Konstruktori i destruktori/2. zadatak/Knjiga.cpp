#include "Knjiga.h"
#include <iostream>
#include <cstring> //ukljucujemo biblioteku za rad sa stringovima
using namespace std;

Knjiga::Knjiga(char* naslov, char* autor, int godina, const char* zemlja, int izdanje) {
	int duzina = strlen(naslov) + 1; //odredjujemo duzinu naslova knjige u bajtovima, kako bi znali koliko mesta u memoriji da zauzmemo prilikom dinamicke alokacije
	this->naslov = new char[duzina]; //obavljamo dinamicku alokaciju, gde parametar "naslov" zauzima onoliko mesta u memoriji koliko smo uneli slova u reci
	strcpy_s(this->naslov, duzina, naslov); //obavlja se upisivanje prosledjenog elementa u odgovarajuci atribut

	duzina = strlen(autor) + 1; //ponovo brojimo koliko bajtova zauzima prosledjeni parametar, kako bismo mogli da uspesno izvrsimo dinamicku alokaciju, dodaje se +1 zbog /0 karaktera na kraju svakog stringa
	this->autor = new char[duzina];
	strcpy_s(this->autor, duzina, autor);
	
	this->godina = godina;
	strcpy_s(this->zemlja,4, zemlja); //buduci da je smesteno u statickoj zoni memorije, nema potrebe da proveravamo broj bajtova, vec odmah mozemo primeniti metodu iz biblioteke cstring
	this->izdanje = izdanje;
}
Knjiga::Knjiga(const Knjiga& original) { //konstruktor za kopiranje, objasnjenje je isto kao gore, samo sto pored prosledjenog elementa dodajemo "original."
	int duzina = strlen(original.naslov) + 1;
	this->naslov = new char[duzina];
	strcpy_s(this->naslov, duzina, original.naslov);

	duzina = strlen(original.autor)+1;
	this->autor = new char[duzina];
	strcpy_s(this->autor, duzina, original.autor);

	strcpy_s(this->zemlja, 4, original.zemlja);
	this->godina = original.godina;
	this->izdanje = original.izdanje;
}

Knjiga::~Knjiga() { //destruktor, koji brise sve sto je zauzeto u procesu dinamicke alokacije
	delete[]naslov;
	delete[]autor;
}

Knjiga Knjiga::narednoIzdanje() { //metoda za kreiranje narednog izdanja
	Knjiga novoIzdanje(*this); //pravi se novi objekat novoIzdanje koje je kopija trenutnog objekta. Kopiranje se obavlja konstruktorom kopije jer prosledjujemo *this. Svi atributi se kopiraju iz originalnog objekta
	novoIzdanje.godina = 2020; //stavljamo bilo koju godinu za novonastalu knjigu
	novoIzdanje.izdanje++; //uvecavamo broj izdanja
	return novoIzdanje; //vracamo sve podatke 
}

bool Knjiga::podZastitom() { //metoda za proveru da li je knjiga pod zastitom, realizovali smo kao logicku metodu, tj. ima povratnu vrednost TRUE ili FALSE
	return (strcmp(this->zemlja, "SRB") == 0 && this->godina < 1900); //poredi da li se atribut zemlja poklapa sa Srbijom (ukoliko se sve poklapa onda je povratna vrednost 0) i istovremeno proverava da li je godina manja od 1900
} //ukoliko su ispunjena oba uslova, onda vraca povratnu vrednost TRUE (odnosno bilo koji pozitivan broj), dok ukoliko se nesto ne poklapa vraca vrednost FALSE (odnosno 0)

void Knjiga::prikaz() { //standardna metoda za prikaz
	cout << naslov << " " << autor << " " << " " << godina << " " << zemlja << " " << izdanje;
} 

#include "Film.h" //ukljucujemo sve neophodne biblioteke i header fajlove
#include <iostream>
#include <cstring> //ukljucujemo biblioteku za rad sa stringovima
using namespace std;

Film::Film(const char* naziv, int sat, int minut, int trajanje) { //konstruktor za postavljanje vrednosti
	int duzina = strlen(naziv) + 1; //racunamo duzinu koju cemo da rezervisemo u dinamickoj zoni memorije
	this->naziv = new char[duzina]; //vrsimo dinamicku alokaciju, gde ce naziv zauzeti onoliko mesta koliko smo prethodno izracunali da nam je potrebno
	strcpy_s(this->naziv, duzina, naziv); //vrsimo kopiranje jedne vrednosti u drugu

	this->sat = sat; //klasicna dodela vrednosti
	this->minut = minut;
	this->trajanje = trajanje;
}

Film::~Film() {
	delete[]naziv; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
}

bool Film::operator<(const Film& drugi) { //logicki operator za poredjenje, koji vraca vrednost true ili false
	return this->sat < drugi.sat || this->sat == drugi.sat && this->minut < drugi.minut; //prvo proverava da li se satovi pocetka razlikuju, ukoliko su oni pak isti onda vrsi dodatnu proveru vezanu za minut pocetka projekcije
}

Film& Film::operator=(const Film& drugi) { //operator dodele vrednosti jednog objekta drugom, izmene se vrse direktno u memoriji uz pomoc prisutnog operatora &
	if (this != &drugi) { //proveravamo da li se tekuci i prosledjeni objekat razlikuju
		if (this->naziv != NULL) { //potom proveravamo da li je vec zauzet element u dinamickoj zoni, ukoliko jeste brisemo njegovu vrednost
			delete[]naziv;
		}
		int duzina = strlen(drugi.naziv) + 1; //racunamo vrednost koja ce biti zauzeta dinamickom alokacijom
		this->naziv = drugi.naziv; //vrsimo samo dodelu vrednosti tekucem objektu 
		strcpy_s(this->naziv, duzina, drugi.naziv);
		this->sat = drugi.sat;
		this->minut = drugi.minut;
		this->trajanje = drugi.trajanje;
	}
	return *this; //povratna vrednost nam je pokazivac na tekuci objekat i sve njegove elemente
}

ostream& operator<<(ostream& izlaz, const Film& film) { //prijateljska operatorska funkcija za prikaz, koja se uglavnom definise na ovakav nacin
	int minutKraja = film.minut + film.trajanje; //pomocna promenljiva za minut kraja filma, vrednost se dobija tako sto pocetak filma u minutima saberemo sa vremenom trajanja filma u minutima
	int satKraja = film.sat + minutKraja / 60; //pomocna promenljiva za kraj filma u satima, vrednost se dobija tako sto pocetak filma u satima saberemo sa celobrojnom vrednoscu kraja filma u satima (koje dobijamo kada minut kraja podelimo sa 60, npr 125/60=2)
	minutKraja = minutKraja % 60; //azuriramo vrednost za minut kraja tako sto nad prethodnom vrednoscu izvsrimo deljenje sa ostatkom (npr 125%60=5)
	
	izlaz << film.naziv <<" " << film.sat << ":" << film.minut << "-" << satKraja << ":" << minutKraja; //potom prikazemo sve vrednosti
	return izlaz;
} //prikaz ce izgledati npr: Titanik 11:30 - 13:10 
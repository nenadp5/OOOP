#include <iostream>
#include <cstring> //ukljucivanje biblioteke koja omogucava rad sa stringovima
#include "Vozilo.h"
using namespace std;

float Vozilo::BrzinaVanNaselja; //obavezno definisanje statickih atributa pre pocetka definisanja ostalih metoda
float Vozilo::BrzinaUNaselju;
float Vozilo::BrzinaNaAutoputu;

void Vozilo::postaviNaziv(const char* naziv) { //metoda za postavljanje naziva
	strcpy_s(this->naziv, 20, naziv); //koristi se funkcija strcpy_s iz biblioteke cstring koja omogucava rad sa stringovima
}

void Vozilo::postaviBrzinu(float maxBrzina) { //metoda za postavljanje brzine
	this->maxBrzina = maxBrzina; //ukoliko ne prosledimo vrednost ovoj metodi, ona ce obavljati svoju funkciju kako treba, jer je u okviru klase vec definisana dodeljena vrednost
}

void Vozilo::postaviOgranicenje(float UNaselju, float VanNaselja, float NaAutoputu) { //metoda za dodeljivanje vrednosti statickih atributa
	Vozilo::BrzinaUNaselju = UNaselju; //pristupamo statickom atributu na vec definisan nacin (naziv_klase::naziv_atributa)
	Vozilo::BrzinaVanNaselja = VanNaselja; //ukoliko nista ne prosledimo ovoj metodi iz glavnog programa, ona ce svakako obavljati svoj posao, jer su u okviru klase definisane vrednosti koje ce biti dodeljene
	Vozilo::BrzinaNaAutoputu = NaAutoputu;
}

float Vozilo::ukupnoVreme(float kmUNaselju, float kmVanNaselja, float kmNaAutoputu) { //metoda za racunanje ukupno provedenog vremena na odredjenim deonicama puta
	float brzina_uNaselju = (this->maxBrzina < Vozilo::BrzinaUNaselju ? this->maxBrzina : Vozilo::BrzinaUNaselju);
	float brzina_vanNaselja = (this->maxBrzina < Vozilo::BrzinaVanNaselja ? this->maxBrzina : Vozilo::BrzinaVanNaselja);
	float brzina_naAutoputu = (this->maxBrzina < Vozilo::BrzinaNaAutoputu ? this->maxBrzina : Vozilo::BrzinaNaAutoputu);
	float ukupno = kmUNaselju / brzina_uNaselju + kmVanNaselja / brzina_vanNaselja + kmNaAutoputu / brzina_naAutoputu;
	return ukupno;
}
/* Objasnjenje za funkciju float Vozilo::ukupnoVreme(float kmUNaselju, float kmVanNaselja, float kmNaAutoputu)
  brzina_uNaselju - kreiramo novu promenljivu 
  this->maxBrzina < Vozilo::BrzinaUNaselju ? this->maxBrzina : Vozilo::BrzinaUNaselju - poredimo vrednosti maxBrzine i statickog atributa za brzinu u naselju
  ukoliko je maksimalna brzina manja od granicne, onda se ona pamti u novoj promenljivoj, dok ukoliko je maksimalna brzina veca od granicne onda se u novoj promenljivoj pamti vrednost granicne brzine
  ukupno - predstavlja promenljivu gde se broj kilometara koje je vozilo provelo na toj deonici (broj kilometara prosledjujemo mi iz glavnog programa) deli sa brzinom kojom se kretalo. Tako se obavi za svaku deonicu i onda se sabere
  objasnjenje je isto za svaku deonicu puta, u pitanju je rad sa operatorima grananja 
  */
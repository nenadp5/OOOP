#include "Proizvod.h" //ukljucujemo header fajl
#include <iostream>
#include <cstring> //ukljucujemo biblioteku za rad sa stringovima, jer su nam potrebne neke funkcije odatle
using namespace std;

float Proizvod::pdv; //svaki staticki atribut je neophodno uvek definisati na ovaj nacin

void Proizvod::postaviNaziv(char* naziv) { //metoda za postavljanje naziva
	strcpy_s(this->naziv, naziv); //koristimo funkciju strcpy_s koja omogucava kopiranje jednog stringa
}

void Proizvod::postaviCenu(float osnovna_cena) { //metoda za postavljanje osnovne cene
	this->osnovna_cena = osnovna_cena;
}

void Proizvod::postaviPDV(float pdv) { //metoda za postavljanje statickog atributa PDV
	Proizvod::pdv = pdv; //statickom atributu uvek pristupamo na ovakav nacin (klasa::naziv_atributa)
}

float Proizvod::cenaSaPDV() { //metoda za racunanje cene sa pdv
	return osnovna_cena + osnovna_cena * Proizvod::pdv / 100; //matematicka formula za racunanje cene, takodje se statickom atributu pristupa Proizvod::pdv (odnosno klasa::naziv_atributa)
}
#pragma once
#include <iostream> //ukljucujemo biblioteku zbog funckija "ostream" i "istream"
using namespace std;
class Proizvod { //kreiramo klasu "Proizvod"
private: //privatni atributi klase
	char naziv[20]; //atribut naziv smesten u statickoj zoni memorije
	float cena; //cena i kod takodje smesteni u statickoj zoni memorije
	int kod;

public:
	friend ostream& operator<<(ostream& izlaz, const Proizvod& pr);  //prijateljska operatorska funkcija za prikaz rezultata iz klase "Proizvod"
	friend istream& operator>>(istream& ulaz, Proizvod& pr); //prijateljska operatorska funkcija za unos podataka
};

/*Iako u okviru zadatka nisu navedene ove prijateljske operatorske funkcije, mi ih moramo uvesti,
jer u suprotnom se javlja greska kod metode za rad sa fajlovima, koja javlja da su operaotori << i >> nepoznati.
Dakle ovi operatori nam omogucavaju da kasnije u okviru fajla imamo unos i ispis podataka iz klase "Proizvod" */
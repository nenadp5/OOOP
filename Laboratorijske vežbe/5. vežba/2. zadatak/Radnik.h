#pragma once
#include <iostream> //ukljucujemo biblioteku zbog funckija "ostream" i "istream"
#include <fstream>
using namespace std;
class Radnik { //kreiramo klasu "Radnik"
private: //privatni atributi klase
	char ime[20]; //ime i prezime radnika su smesteni u statickoj zoni memorije
	char prezime[20];
	float plata; //plata i jmbg radnika su takodje smesteni u statickoj zoni memorije
	int JMBG;
public:
	friend ostream& operator<<(ostream& izlaz, const Radnik& radnik); // prijateljska operatorska funkcija za prikaz rezultata iz klase "Radnik"
	friend istream& operator>>(istream& ulaz, Radnik& radnik); //prijateljska operatorska funkcija za unos podataka
};

/*Iako u okviru zadatka nisu navedene ove prijateljske operatorske funkcije, mi ih moramo uvesti,
jer u suprotnom se javlja greska kod metode za rad sa fajlovima, koja javlja da su operaotori << i >> nepoznati.
Dakle ovi operatori nam omogucavaju da kasnije u okviru fajla imamo unos i ispis podataka iz klase "Radnik" */
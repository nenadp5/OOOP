#pragma once
#include <iostream> //ukljucujemo biblioteku zbog funckija "ostream" i "istream"
#include <fstream>
using namespace std;
class Lekar { //kreiramo klasu "Lekar"
private: //privatni atributi klase
	char ime[20]; //atribut ime smesten u statickoj zoni memorije
	float plata; //atribut za platu i broj radnih sati takodje smesteni u statickoj zoni memorije
	float brSati;
public:
	friend ostream& operator<<(ostream& izlaz, const Lekar& l); //prijateljska operatorska funkcija za prikaz rezultata iz klase "Lekar"
	friend istream& operator>>(istream& ulaz, Lekar& l); //prijateljska operatorska funkcija za unos podataka
};

/*Iako u okviru zadatka nisu navedene ove prijateljske operatorske funkcije, mi ih moramo uvesti,
jer u suprotnom se javlja greska kod metode za rad sa fajlovima, koja javlja da su operaotori << i >> nepoznati.
Dakle ovi operatori nam omogucavaju da kasnije u okviru fajla imamo unos i ispis podataka iz klase "Lekar" */
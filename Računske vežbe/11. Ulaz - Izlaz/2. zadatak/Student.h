#pragma once
#include <iostream> //ukljucujemo zbog ostream i istream
#include <fstream> //ukljucujemo biblioteku za rad sa fajlovima
using namespace std;
class Student { //kreiramo klasu Student
private: //privatni atributi klase
	char ime[20]; //buduci da nije receno da treba da se smesti u dinamicku zonu memorije, smestili smo je u staticki deo
	char prezime[20];
	int indeks;

public:
	Student(); //podrazumevani konstruktor
	Student(const char* ime, const char* prezime, int indeks); //konstruktor koji postavlja vrednosti
	
	void ulazBin(ifstream& ulaz); //metoda za rad sa binarnim fajlovima
	void izlazBin(ofstream& izlaz);

	friend ostream& operator<<(ostream& izlaz, const Student& s); //prijateljski operator za prikaz podataka na izlazu
	friend istream& operator>>(istream& ulaz, Student& s); //prijateljski operator za upis podataka
};

/*Objasnjenje za: "void ulazBin(ifstream& ulaz);" i "void izlazBin(ofstream& izlaz)"
Da bismo mogli da pozovemo ulaz/izlaz za vise studenata u nizu iz klase "Ucionica", funkcije "izlazBin" i "ulazBin" treba da imaju kao argumente objekte ofstream/ifstream.
U implementaciji ovih funkcija predpostavljamo da su ovi tokovi vec otvoreni.
*/
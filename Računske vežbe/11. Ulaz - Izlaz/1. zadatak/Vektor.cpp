#include "Vektor.h"
#include <iostream>
#include <fstream> //ukljucujemo biblioteku za rad sa fajlovima
using namespace std;

Vektor::Vektor() { //podrazumevani konstruktor koji postavlja vrednosti na 0 ili NULL
	this->niz = NULL;
	this->brEl = 0;
}

Vektor::Vektor(int brEl) { //konstruktor koji postavlja vrednosti
	this->brEl = brEl;
	this->niz = new int[this->brEl]; //vrsi se dinamicka alokacija memorije za niz
}

Vektor::~Vektor() { //destruktor
	delete[]niz; //oslobadjamo prostor koji je zauzet prilikom dinamicke alokacije
}

void Vektor::ulazTxt(const char* fajlPutanja) { //metoda za ucitavanja podataka iz fajla
	ifstream ulaz(fajlPutanja); //ukljucujemo funkciju koja otvara fajl kako bi ucitala podatke iz njega (ifstream), takodje kreiramo neki vid promenljive kojoj dodeljujemo naziv "ulaz".
	if (ulaz) { //ukoliko je uspesno obavljeno otvaranje fajla za citanje obavljaju se sledece operacije
		ulaz >> brEl; //prvo se ucitava prva vrednost iz fajla, odnosno broj elemenata niza
		if (niz != NULL) { 
			delete[]niz; //ukoliko je kojim slucajem niz vec zauzet, vrsi se brisanje tih elemenata, kako bi se napravilo mesta za upis novih elemenata
		}
		niz = new int[brEl]; //potom vrsimo ponovo dinamicku alokaciju memorije, na osnovu broja procitanih elemenata
		for (int i = 0; i < brEl; i++) {
			ulaz >> niz[i]; //nakon toga ucitavamo vrednosti iz fajla redom i smestamo ih u niz
		}
	}
	ulaz.close(); //na kraju moramo obavezno da zatvorimo fajl
}

void Vektor::izlazTxt(const char* fajlPutanja) { //metoda za upisivanje podataka u fajl
	ofstream izlaz(fajlPutanja); //pozivamo funkciju koja otvara prosledjeni fajl za upis podataka u njega
	if (izlaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		izlaz << brEl << endl;  //prvo se ispisuje element koji predstavlja broj elementa
		for (int i = 0; i < brEl; i++) {
			izlaz << niz[i] << endl; //potom sledi upisivanje elemenata redom u otvoreni fajl
		}
	}
	izlaz.close();
}

void Vektor::ulazBin(const char* fajlPutanja) { //metoda za ucitavanje podataka iz binarnog fajla
	ifstream ulaz(fajlPutanja, ios::binary); //pozivamo funkciju koja otvara prosledjeni fajl za ucitavanje podataka iz fajla, i uz pomoc komande "ios:binary" nagovestamo da se radi sa binarnim fajlovima
	if (ulaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		ulaz.read((char*)&brEl, sizeof(brEl)); //ucitavamo prvi element iz fajla, vrsimo promenu njegov tipa u char i racunamo njegovu dimenziju kako bi kasnije mogao da se upise u fajl
		if (niz != NULL) {
			delete[]niz; //ukoliko je niz zauzet onda vrsimo brisanje elemenata kako bi mogli da smestimo nove elemente
		}
		niz = new int[brEl]; //kreiramo niz u dinamickoj zoni memorije
		for (int i = 0; i < brEl; i++) {
			ulaz.read((char*)&niz[i], sizeof(niz[i])); //nakon toga sledi ucitavanje svih elememata redom i smestanje u niz, takodje je prisutna transformacija u format char i merenje velicine podataka
		}
	}
	ulaz.close(); //na kraju je obavezno zatvoriti sam fajl
}

void Vektor::izlazBin(const char* fajlPutanja) { //metoda za upisivanje podataka u binarni fajl
	ofstream izlaz(fajlPutanja, ios::binary); //pozivamo funkciju koja otvara prosledjeni fajl za upis podataka u njega, nagovestavamo da je rec o binarnom fajlu uz pomoc ("ios:binary")
	if (izlaz) { //ukoliko je fajl uspesno otvoren obavljaju se sledece operacije
		izlaz.write((char*)&brEl, sizeof(brEl)); //upisuje se prva vrednost koja predstavlja broj elemenata
		for (int i = 0; i < brEl; i++) {
			izlaz.write((char*)&niz[i], sizeof(niz[i])); //nakon toga sledi ispis svih elemenata redom u sam fajl
		}
	}
	izlaz.close(); //i potom sledi obavezno zatvaranje fajla
}

ostream& operator<<(ostream& izlaz, const Vektor& v) { //prijateljski operator za prikaz rezultata
	izlaz << v.brEl << endl; //ispisuje se broj elemenata prosledjenog vektora
	for (int i = 0; i < v.brEl; i++) {
		izlaz << v.niz[i] << " "; //nakon toga se ispisuju svi elementi niza
	} //kod operatora za prikaz prosledjena vrednost je const kako ne bi doslo do izmene vrednosti
	return izlaz;
}

istream& operator>>(istream& ulaz, Vektor& v) { //prijateljski operator za upis rezultata
	ulaz >> v.brEl; //prvo upisujemo broj elementa
	if (v.niz != NULL) {
		delete[]v.niz; //proveravamo da li niz nije kojm slucajem popunjen, ukoliko je popunjen, vrsi se brisanje tih elemenata
	} //kod operatora za upis nemamo const zato sto se prosledjeni parametar menja
	v.niz = new int[v.brEl]; //dinamicka alokacija memorije
	for (int i = 0; i < v.brEl; i++) {
		ulaz >> v.niz[i]; //upis svih elemenata u niz
	}
	return ulaz;
}
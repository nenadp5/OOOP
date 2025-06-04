#include "Radnik.h"
#include <iostream>
#include <cstring> //ukljucujemo biblioteku za rad sa stringovima
using namespace std;

Radnik::Radnik(const char* ime, const char* prezime, int maxBr, int trBr, float cenaPoSatu, float* niz) {
	int duzina = strlen(ime) + 1; //brojimo koliko mesta ce zauzeti promenljiva "ime", to postizemo uz pomoc funkcije strlen
	this->ime = new char[duzina]; //vrsimo dinamicku alokaciju memorije za parametar "ime"
	strcpy_s(this->ime, duzina, ime); //obavlja se dodela vrednosti

	duzina = strlen(prezime) + 1; //brojimo koliko mesta ce zauzeti promenljiva "prezime", to postizemo uz pomoc funkcije strlen
	this->prezime = new char[duzina]; //vrsimo dinamicku alokaciju memorije za parametar "ime"
	strcpy_s(this->prezime, duzina, prezime); //obavlja se dodela vrednosti

	this->maxBr = maxBr; //dodeljujemo ostale vrednosti atributima
	this->trBr = trBr;
	this->cenaPoSatu = cenaPoSatu;

	this->niz = new float[maxBr]; //obavlja se memorijska alokacija za atribut "niz"
	for (int i = 0; i < trBr; i++) { //za niz idemo od 0 do trenutnog broja elemenata, a ne do maksimalnog jer ce se onda zauzimati bespotrebne memorijske lokacije
		this->niz[i] = niz[i]; //prolazimo kroz ceo niz i upisujemo elemente
	}
}

Radnik::Radnik() {
	this->maxBr = 0; //podrazumevani konstruktor koji atributima dodeljuje vrednosti 0, NULL ili prazan element u zavisnosti od slucaja
	this->trBr = 0;
	this->cenaPoSatu = 0;
	this->niz = NULL;
	this->prezime = new char[1];
	strcpy_s(this->prezime, 1, "");
	this->ime = new char[1];
	strcpy_s(this->ime, 1, "");
}

Radnik::Radnik(const Radnik& original) { //konstruktor za kopiranje, gde upisujemo vrednosti prosledjenog objekta "Radnik"
	int duzina = strlen(original.ime) + 1; //brojimo koliko mesta ce zauzeti promenljiva "ime" od prosledjenog objekta, to postizemo uz pomoc funkcije strlen
	this->ime = new char[duzina]; //vrsimo dinamicku alokaciju memorije za parametar "ime"
	strcpy_s(this->ime, duzina, original.ime); //obavlja se dodela vrednosti

	duzina = strlen(original.prezime) + 1; //brojimo koliko mesta ce zauzeti promenljiva "prezime" od prosledjenog objekta, to postizemo uz pomoc funkcije strlen
	this->prezime = new char[duzina]; //vrsimo dinamicku alokaciju memorije za parametar "prezime"
	strcpy_s(this->prezime, duzina, original.prezime); //obavlja se dodela vrednosti, to postizemo uz pomoc funckije "strcpy_s"

	this->maxBr = original.maxBr;
	this->trBr = original.trBr; //dodeljujemo vrednosti atributima koje ima prosledjeni objekat "Radnik"
	this->cenaPoSatu = original.cenaPoSatu;

	this->niz = new float[maxBr]; //vrsimo dinamicku alokaciju za parametar "niz"
	for (int i = 0; i < trBr; i++) {
		this->niz[i] = original.niz[i]; //prolazimo kroz ceo niz i upisujemo vrednosti iz niza prosledjenog objekta
	}
}

Radnik::~Radnik() {
	delete[]ime; //destruktor koji brise elemente koji su smesteni u dinamickoj zoni memorije
	delete[]prezime;
	delete[]niz;
}

float Radnik::zarada() const {
	float zarada = 0; //kreiramo pomocnu promenljivu
	for (int i = 0; i < trBr; i++) {
		zarada += niz[i] * this->cenaPoSatu; //prolazimo kroz niz radnih sati i mnozimo svaki element sa cenom po satu, sve to smestamo u pomocnu promenljivu
	}
	return zarada; //povratna vrednost nam je tipa float i to je upravo prethodno kreirana promenljiva
}

Radnik& Radnik::operator=(const Radnik& drugi) { //operator koji dodeljuje vrednosti objektu od strane prosledjenog objekta, Radnik& znaci da se izmene vrse direktno u memoriji
	if (this != &drugi) { //proveravamo da li se prosledjeni i trenutni objekat razlikuju
		if (this->ime != NULL) {
			delete[]ime; //ukoliko je parametar "ime" zauzet onda brisemo elemente da bi mogli da smestimo nove
		}
		if (this->prezime != NULL) {
			delete[]prezime; //ukoliko je parametar "prezime" zauzet onda brisemo elemente da bi mogli da smestimo nove
		}
		if (this->niz != NULL) {
			delete[]niz //ukoliko je parametar "niz" zauzet onda brisemo elemente da bi mogli da smestimo nove
		}
		int duzina = strlen(drugi.ime) + 1 //brojimo koliko mesta ce zauzeti promenljiva "ime" od prosledjenog objekta, to postizemo uz pomoc funkcije strlen
		this->ime = new char[duzina]; //vrsimo dinamicku alokaciju memorije za parametar "ime"
		strcpy_s(this->ime, duzina, drugi.ime); //obavlja se dodela vrednosti

		duzina = strlen(drugi.prezime) + 1; //brojimo koliko mesta ce zauzeti promenljiva "prezime" od prosledjenog objekta, to postizemo uz pomoc funkcije strlen
		this->prezime = new char[duzina]; //vrsimo dinamicku alokaciju memorije za parametar "prezime"
		strcpy_s(this->prezime, duzina, drugi.prezime); //obavlja se dodela vrednosti

		this->maxBr = drugi.maxBr; //obavlja se dodela vrednosti
		this->trBr = drugi.trBr;
		this->cenaPoSatu = drugi.cenaPoSatu;

		this->niz = new float[maxBr]; //vrsimo dinamicku alokaciju za niz, koji ce u memoriji zauzeti maksimalni broj elemenata tog niza
		for (int i = 0; i < trBr; i++) {
			this->niz[i] = drugi.niz[i]; //prolazimo kroz ceo niz i upisujemo vrednosti od prosledjenog elementa
		}
	}
	return *this; //povratna vrednost je trenutni azurirani objekat
}

Radnik Radnik::operator++(int n) { //postfiksni operator za uvecanje vrednosti, parametar n se nigde ne koristi vec samo sluzi da razlikujemo postfiksni od prefiksnog
	Radnik kopija(*this); //kreiramo novu promenljivu od trenutnog objekta
	this->cenaPoSatu += 100; //poveacavamo vrednost cene po satu za trenutni objekat
	return kopija; //vracamo novu promenljivu kojoj nisu promenjene vrednosti
}

Radnik& Radnik::operator--() { //prefiksni operator za smanjenje vrednosti
	this->cenaPoSatu -= 100; //smanjujemo vrednost trenutnog objekta
	return *this; //povratna vrednost je azurirani trenutni objekat
}

Radnik& Radnik::operator+=(float sat) { //operator za dodavanje vrednosti u niz
	if (this->trBr < this->maxBr) { //proveravamo da li ima mesta u nizu za novi upis, odnosno da li trenutni broj ne prelazi maksimalni
		niz[trBr] = sat; //upisujemo novu vrednost u niz
		trBr++; //povecavamo trenutni broj
	}
	else {
		cout << "Greska! Prekoracen je maksimalni broj radnih dana za ovaj mesec! " << endl; //ispisujemo poruku ukoliko je prekoracen opseg
	}
	return *this; //povratna vrednost je azurirani trenutni objekat
}

bool operator>(const Radnik& prvi,const Radnik& drugi) {
	return prvi.zarada() > drugi.zarada(); //logicki operator koji vraca vrednost TRUE ili FALSE u zavisnosti od zarade radnika
}

ostream& operator<<(ostream& izlaz, const Radnik& radnik) { //operator za izlaz, prosledjujemo sa parametrom const da ne bi vrsilo izmenu prosledjenih elemenata
	izlaz << "Podaci o radniku: " << endl;
	izlaz << radnik.ime << " " << radnik.prezime << endl; //ispisujemo sve podatke o radniku i pozivamo neophodne funkcije
	izlaz << "Koji od " << radnik.maxBr << " radnih dana u ovom mesecu, trenutno ima " << radnik.trBr << " radnih dana" << endl;
	izlaz << "Njegov radni sat iznosi: " << radnik.cenaPoSatu << endl;
	izlaz << "Ukupno je zaradio: " << radnik.zarada() << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Radnik& radnik) { //metoda za unos podataka
	if (radnik.ime != NULL) {
		delete[]radnik.ime; //proveravamo da li je parametar "ime" slobodan kod prosledjenog elementa i ukoliko nije brisemo te elemente, kako bi mogli upisati nove
	}
	if (radnik.prezime != NULL) {
		delete[]radnik.prezime; //proveravamo da li je parametar "prezime" slobodan kod prosledjenog elementa i ukoliko nije brisemo te elemente, kako bi mogli upisati nove
	}
	if (radnik.niz != NULL) {
		delete[]radnik.niz; //proveravamo da li je parametar "niz" slobodan kod prosledjenog elementa i ukoliko nije brisemo te elemente, kako bi mogli upisati nove
	}
	char ime[100];
	char prezime[100]; //kreiramo pomocne promenljive u koje smestamo ime i prezime radnika
	cout << "Unesi ime radnika: ";
	ulaz >> ime; //unosimo vrednost za pomocnu promenljivu
	int duzina = strlen(ime) + 1; //prebrojavamo koliko mesta ce zauzeti pomocna promenljiva
	radnik.ime = new char[duzina]; //vrsimo dinamicku alokaciju za parametar "ime" kod prosledjenog objekta
	strcpy_s(radnik.ime, duzina, ime); //dodeljujemo vrednost parametru "ime" iz pomocne promenljve

	cout << "Unesi prezime radnika: ";
	ulaz >> prezime; //unosimo vrednost za pomocnu promenljivu
	duzina = strlen(prezime) + 1; //prebrojavamo koliko mesta ce zauzeti pomocna promenljiva
	radnik.prezime = new char[duzina]; //vrsimo dinamicku alokaciju za parametar "prezime" kod prosledjenog objekta
	strcpy_s(radnik.prezime, duzina, prezime); //dodeljujemo vrednost parametru "prezime" iz pomocne promenljve

	cout << "Unesi maksimalni broj radnih dana u mesecu: ";
	ulaz >> radnik.maxBr; //unosimo vrednosti za elemente prosledjenog objekta
	cout << "Unesi trenutni broj radnih dana: ";
	ulaz >> radnik.trBr;
	cout << "Unesi cenu radnog sata: ";
	ulaz >> radnik.cenaPoSatu;

	cout << "Unesi niz radnih sati: ";
	radnik.niz = new float[radnik.maxBr]; //vrsimo dinamicku alokaciju za niz koji je vezan za prosledjeni objekat
	for (int i = 0; i < radnik.trBr; i++) {
		ulaz >> radnik.niz[i]; //prolazimo kroz ceo niz i upisujemo vrednosti
	}
	return ulaz;
}
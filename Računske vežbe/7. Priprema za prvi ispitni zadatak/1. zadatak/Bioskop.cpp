#include "Bioskop.h"
#include <iostream>
#include <cstring>
using namespace std;

Bioskop::Bioskop() { //podrazumevani konstruktor
	this->naziv = new char[1]; //vrsimo dinamicku alokaciju za naziv i to samo za jedno mesto, jer ce biti smesten prazan element
	strcpy_s(this->naziv, 1, "");
	this->trBr = 0; //postavljamo vrednost na 0 
}

Bioskop::Bioskop(const char* naziv) { //konstruktor za postavljanje vrednosti
	int duzina = strlen(naziv) + 1; //odredjujemo duzinu koju ce zauzeti promenljiva u procesu dinamicke alokacije
	this->naziv = new char[duzina]; //obavljamo dinamicku alokaciju
	strcpy_s(this->naziv, duzina, naziv); //obavljamo proces dodele vrednosti
	this->trBr = 0;
}

Bioskop::~Bioskop() { //destruktor
	delete[]naziv; //brisemo elemente iz dinamicke zone memorije
}

Bioskop& Bioskop::operator+(Film& film) { //dodajemo filmove u bioskop, izmene se vrse direktno u memoriji uz pomoc operatora &
	if (this->trBr < 20) { //ukoliko imamo mesta dodajemo filmove u bioskop
		this->filmovi[trBr] = &film; //dodaju se svi prateci elementi filma
		trBr++; //uvecava se trenutni broj filmova
	}
	else {
		cout << "Greska, repertoar je put! "; //ukoliko je popunjeno onda se ispisuje poruka
	}
	return *this; //povratna vrednost je this odnosno bioskop
}

float Bioskop::prosecnoTrajanje() { //metoda za racunanje prosecnog trajanja
	int ukupnoTrajanje = 0; //kreiramo pomocnu promenljivu za ukupno trajanje filma
	for (int i = 0; i < trBr; i++) {
		ukupnoTrajanje += filmovi[i]->vratiTrajanje(); //prolazimo kroz ceo niz filmova i sabiramo trajanje svih filmova uz pomoc inline metode iz klase "Film"
	}
	return ukupnoTrajanje / trBr; //ukupno trajanja prodelimo sa brojem filmova i to nam bude povratna vrednost
}

void Bioskop::sort() { //metoda za sortiranje, kao i do sada sto smo je imali
	for (int i = 0; i < trBr - 1; i++) {
		int iMin = i; //prvi element u nizu smatramo najmanjim
		for (int j = i + 1; j < trBr; j++) { //kreiramo pomocnu promenljivu koja ide ispred trenutnog elementa
			if (*filmovi[j] < *filmovi[iMin]) { //vrednosti tih promenljivih prosledjujemo operatoru za poredjenje po vremenu pocetka projekcije iz klase Film ("bool operator<(const Film& drugi)")
				iMin = j;
			}
		}
		if (iMin != i) { //ukoliko ima izmena sledi proces rotacije elemenata
			Film* pom = filmovi[iMin]; 
			filmovi[iMin] = filmovi[i];
			filmovi[i] = pom;

		}
	}
}

Film& Bioskop::najduzi() const{ //metoda za vracanje najduzeg filma
	Film* NajduziFilm = filmovi[0]; //kreiramo pomocnu promenljivu koja uzima prvi element iz niza kao najduzi
	for (int i = 1; i < trBr; i++) { //potom prolazimo kroz ceo niz
		if (filmovi[i]->vratiTrajanje() > NajduziFilm->vratiTrajanje()) { //za svaki element iz niza i trenutno najduzi film vrsimo poredjenje (tako sto iskoristimo metodu za trajanje iz klase Film)
			NajduziFilm = filmovi[i];
		}
	}
	return *NajduziFilm; //povratna vrednost nam je najduzi film i svi njegovi prateci elementi
}

ostream& operator<<(ostream& izlaz, const Bioskop& b) { //prijateljska operacija za prikaz
	izlaz << b.naziv << endl; //ispisujemo naziv bioskopa
	for (int i = 0; i < b.trBr; i++) {
		izlaz << *b.filmovi[i]<<endl; //prikazujemo niz filmova, gde se svaki film prosledjuje metodi za prikaz iz klase Film, zato i imamo prisutnu *
	}
	izlaz << "Najduze traje film: "<< b.najduzi(); //ispisuje se najduzi film, ovde ne treba da prosledjujemo sa zvezdicom, jer metoda u sebi poseduje &
	return izlaz;
}
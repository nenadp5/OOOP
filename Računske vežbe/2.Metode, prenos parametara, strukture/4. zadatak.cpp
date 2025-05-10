#include <iostream>
#include <cmath> //ukljucujemo dodatnu biblioteku za matematicke funkcije koje su nam potrebne kada racunamo ocenu u ovom programu
using namespace std;

struct Student { //kreiramo strukturu student
	char ime[20];
	char prezime[20];
	int indeks;
	int pismeni;
	int usmeni;
	int ocena;
};

void unos(struct Student& s) { //funkcija za unos podataka o studentu
	cout << "Unesi ime studenta: ";
	cin >> s.ime;
	cout << "Unesi prezime studenta: ";
	cin >> s.prezime;
	cout << "Unesi indeks studenta: ";
	cin >> s.indeks;
	cout << "Unesi broj poena na pismenom delu ispita (0-50): ";
	cin >> s.pismeni;
	cout << "Unesi broj poena na usmenom delu ispita (0-50): ";
	cin >> s.usmeni;
}

void prikaz(struct Student* s) { //funkcija za prikaz svih informacija o studentu
	cout << s->indeks << " " << s->ime << " " << s->prezime << " " << s->ocena << endl;
}

int izracunajOcenu(struct Student* s) { //funkcija za izracunavanje ocena studenata
	s->ocena = (int)roundf((s->usmeni + s->pismeni) / 10);
	if (s->ocena < 5) {
		s->ocena = 5;
	}
	return s->ocena;
}

void sort(struct Student studenti[], int duzina) { //funkcija za sortiranje studenata 
	int imax;
	for (int i = 0; i < duzina - 1; i++) {
		imax = i; //smatramo da je trenutni (pocetni) student najbolji
		for (int j = i + 1; j < duzina; j++) {
			if (studenti[j].ocena > studenti[imax].ocena) { //ocene svakog sledeceg studenta se porede sa trenutnim najboljim studentom
				imax = j; //kada naidje student sa boljom ocenom, on postaje trenutni najbolji student
			}
		}
		if (imax != i) { //ukoliko se najbolji student razlikuje od pocetnog onda se vrsi zamena svih vrednosti, odnosno proces sortiranja
			struct Student pom = studenti[i]; //kreiramo novu promenljivu POM koja poprima sve informacije o studentu
			studenti[i] = studenti[imax];
			studenti[imax] = pom;
		}
	}
}

int main() {
	int n, i; //kreiranje celobrojnih promenljivih za ukupan broj studenata i brojac
	cout << "Unesi broj studenata: ";
	cin >> n;
	
	struct Student* niz;  
	niz = new struct Student[n]; //kreiramo niz studenata (koji sadrzi sve informacije o studentu) u dinamickoj zoni memorije
	
	for (i = 0; i < n; i++) {
		unos(niz[i]); //unos svih vrednosti za studenta uz pomoc prethodno kreirane funkcije
	}
	
	cout << "Podaci i vrednosti o unetim studentima: " << endl;
	for (i = 0; i < n; i++) {
		izracunajOcenu(&niz[i]); //izracunavamo ocenu studenta, prosledjujemo memorijsku lokaciju, jer je u okviru funkcije prisutan pokazivac
		prikaz(&niz[i]); //ispisujemo sve informacije o studentu, takodje se prosledjuje memorijska lokacija jer je u okviru funkcije prisutan pokazivac
	}
	
	cout << endl;
	cout << "Sortirani studenti: " << endl;
	sort(niz, n); //uz pomoc funkcije za sortiranje studenata obavlja se sortiranje
	for (i = 0; i < n; i++) {
		prikaz(&niz[i]); //ponovo ispisujemo sve informacije o studentima, samo sto je ovog puta sve sortirano
	}

	delete[]niz; //oslobadjamo prostor koji je zauzeo niz studenata u procesu dinamicke alokacije
	return 0;
}

/* Dodatno objasnjenje:
void unos(struct Student& s) -- operacije u ovoj funkciji se obavljaju nad memorijskom lokacijom koja je formata strukture Student, to smo postigli uz pomoc operatora & 

void prikaz(struct Student* s) -- zbor operatora * se ne pravi kopija celog objekta, vec se prenese samo pokazivac i radi se sa postojecim objektom.
Kada radimo sa pokazivacem na strukturu, clanovima strukture se pristupa operatorom -> umesto operatorom . 
Kada imamo ovakav slucaj, mi funkciji prosledjujemo memorijsku lokaciju, kao sto je primer "prikaz(&niz[i])"

void sort(struct Student studenti[], int duzina) sta je sta ovde:
struct Student - posmatramo kao tip podatka (int,float...) samo sto je ovde u pitanju strukturni tip
studenti[] - nov naziv za prosledjeni niz iz glavnog programa
duzina - duzina prosledjenog niza iz glavnog programa
*/
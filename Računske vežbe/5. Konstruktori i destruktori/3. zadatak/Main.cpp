#include <iostream>
#include "Biblioteka.h"
#include "Knjiga.h"
using namespace std;
int main() {
	Biblioteka b; //kreiramo promenljivu tipa biblioteka
	bool petlja = true; //pravimo novu promenljivu logickog tipa koja moze imati vrednost TRUE ili FALSE sto nam je neophodno zbog WHILE petlje koja omogucava unos vise knjiga kada im se ne zna tacan broj
	while (petlja) { //sve dok je petlja TRUE ona ce se izvrsavati, odnosno sve dok je vrednost razlcita od 0
		cout << "Unesite 0 ukoliko zelite da prekinete unos: ";
		int uslov; //uvodimo novu promenljivu uz pomoc koje mozemo promeniti uslov za petlju i prekinuti njeno izvrsavanje
		cin >> uslov;
		petlja = (uslov != 0); //povezujemo petlju i uslov za petlju kako bi mogli da je prekinemo, stavili smo da uslov mora da bude razlcitim od 0 sto name predstavlja TRUE vrednost
		if (petlja) {
			char naslov[40], autor[40], zemlja[4]; //kreiramo pomocne promenljive koje kasnije prosledjujemo konstruktorima prilikom kreiranja promenljivih tipa knjiga
			int godina, izdanje;
			cout << "Unesi naslov knjige: ";
			cin >> naslov;
			cout << "Unesi ime autora: ";
			cin >> autor;
			cout << "Unesi zemlju porekla knjige: ";
			cin >> zemlja;
			cout << "Unesi godinu nastanka knjige: ";
			cin >> godina;
			cout << "Unesi broj izdanja knjige: ";
			cin >> izdanje;
			Knjiga* knjiga=new Knjiga(naslov, autor, godina, zemlja, izdanje); //kreiramo novu promenljivu knjiga koja ima prethodno unete elemente
			b.dodaj(*knjiga); //dodajemo knjigu u biblioteku uz pomoc metode, stavljamo * jer metoda izgleda "void dodaj(Knjiga& k)" i ocekuje memorijsku lokaciju
		}
	}
	cout << "Pre uredjivanja biblioteke: " << endl;;
	b.prikaz(); //prosledjujemo celu biblioteku metodi za prikaz
	cout << endl;
	
	cout << "Nakon uredjivanja biblioteke po abecednom redu: " << endl;;
	b.uredi(); //prosledjujemo celu biblioteku metodi za uredjivanje i potom ponovo za prikaz
	b.prikaz();

	return 0;
}
/* Objasnjenje oko petlje:
Dakle na pocetku smo definisali promenljivu PETLJA kao true i tu promenljivu stavili kao uslov u WHILE petlju, opste je poznato da se while izvrsava dok je uslov ispunjen sto je u nasem slucaju TRUE
Kasnije u telu petlje, kako bismo pogli da prekinemo petlju da ne bi upali u beskonacnu, uveli smo dodatnu promenljivu USLOV. Promenljivu USLOV smo povezali sa promenljivom PETLJA i rekli da ce PETLJA imati vrednost TRUE sve dok se USLOV razlikuje od 0 zbog teksta u cin
Dakle ukoliko korisnik unese bilo koji broj sem 0, onda ce unositi sve informacije o knjizi i puniti biblioteku sve dok ne unese 0 ili unese 100 knjiga. Kada unese 0, prekida se unos i vrsi se prikaz i uredjivanje biblioteke
Najlaksi i najrazumniji nacin za resavanje je upravo preko WHILE petlje jer je u teksu receno da korisnik unosi vise knjiga na ulazu, nije recen striktni broj!*/
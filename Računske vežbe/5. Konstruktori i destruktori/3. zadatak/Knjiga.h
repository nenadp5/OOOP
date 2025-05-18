#pragma once
class Knjiga {
private: //privatni	atributi klase
	char* naslov; //naslov knjige koji ce biti smesten u dinamickoj zoni memorije
	char* autor; //ime autora koje ce takodje biti smesteno u dinamickoj zoni memorije
	int godina;
	char zemlja[4]; //ime zemlje cemo staviti u staticki deo memorije
	int izdanje;

public:
	Knjiga(char* naslov, char* autor, int godina, const char* zemlja, int izdanje); //konstruktor za postavljanje svih informacija o knjizi
	Knjiga(const Knjiga& original); //konstruktor za kopiranje
	~Knjiga(); //iako nije receno u tekstu zadatka, neophodno je da uvek imamo destruktor

	bool podZastitom(); //metoda koja odredjuje da li je knjiga pod zastitom, realizovali smo je preko logickog tipa podatka
	Knjiga narednoIzdanje(); //metoda koja kreira naredno izdanje od prosledjene knjige
	void prikaz(); //metoda za prikaz
	
	char* vratiAutora() { //inline metoda za vracanje autora
		return this->autor;
	}
};
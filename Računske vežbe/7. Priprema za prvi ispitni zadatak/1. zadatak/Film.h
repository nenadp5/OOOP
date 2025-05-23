#pragma once
#include<iostream> //ukljucujemo biblioteku iostream kako bi mogli da koristimo operatore istream i ostream
using namespace std;
class Film {
private: //privatni atributi klase
	char* naziv; //naziv koji je smesten u dinamickoj zoni memorije
	int sat;
	int minut;
	int trajanje;

public:
	Film(const char* naziv, int sat, int minut, int trajanje); //konstruktor za postavljanje vrednosti
	~Film(); //destruktor
	
	int vratiTrajanje() { //inline metoda koja vraca trajanje film
		return this->trajanje;
	}

	bool operator<(const Film& drugi); //logicki operator koji poredi filmove po vremenu pocetka projekcije
	Film& operator=(const Film& drugi); //operatorska funkcija za dodelu vrednosti jednog filma drugom

	friend ostream& operator<<(ostream& izlaz, const Film& film); //prijateljska operacija za prikaz svih vrednosti o filmu
};
#pragma once
class Student { //kreiramo klasu Student
private: //privatni atributi
	char* ime; //ime i prezime studenta je smesteno u dinamickoj zoni memorije
	char* prezime;
	int indeks;

protected:
	virtual float brojBodova() = 0; //cista virtuelna funkcija za racunanje broja bodova

public:
	Student(const char* ime, const char* prezime, int indeks); //konstruktor za postavljanje vrednosti
	virtual ~Student(); //virtuelni destruktor
	void prikaz(); //metoda za prikaz
	bool operator<(Student& s); //operatorska funkcija koja poredi trenutnog studenta i prosledjenog studenta na osnovu broja bodova
};
#pragma once
class Student {
private: //privatni atributi klase student
	char ime[20];
	char prezime[20];
	int indeks;
	int pismeni;
	int usmeni;

public:
	void unos(); //metoda za unos
	void prikaz(); //metoda za prikaz
	int ocena(); //metoda za racunanje ocene
};
//nemamo prosledjene elemente, jer cemo direktno baratati sa privatnim atributima uz pomoc this->
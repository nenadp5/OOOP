#pragma once
#include "Student.h"
class StudentViseGodine :public Student { //kreiramo klasu "StudentViseGodine" koja je izvedena iz klase "Student"
private: //privatni atributi klase
	float prosecnaOcena;
	int godina;
	int brojIspita;

public:
	StudentViseGodine(const char* ime, const char* prezime, int indeks, float prosecnaOcena, int godina, int brojIspita); //konstruktori za postavljanje vrednosti
	~StudentViseGodine(); //destruktor
	float brojBodova(); //cista virtuelna funkcija iz klase "Student" koja i ovde mora da se definise
};
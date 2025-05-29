#pragma once
#include "Student.h"
class Brucos :public Student { //kreiramo klasu "Brucos" koja je izvedena iz klase Student
private:
	float prosecnaOcenaIzSrednje; //privatni atribut

public:
	Brucos(const char* ime, const char* prezime, int indeks, float prosecnaOcenaIzSrednje); //konstruktor za postavljanje vrednosti
	~Brucos(); //destruktor
	float brojBodova(); //cisto virtuelna funkcija iz klase "Student" koja se ovde mora definisati
};
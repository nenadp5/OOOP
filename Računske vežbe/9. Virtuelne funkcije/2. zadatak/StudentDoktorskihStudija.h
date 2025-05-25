#pragma once
#include "Student.h" //ukljucujemo biblioteku "Student.h" zato sto je "StudentDoktorskihStudija" izveden iz klase "Student"
class StudentDoktorskih :public Student {
private:
	char* oblastIstrazivanja; //privatni atribut klase "StudentDoktorskih" smesten u dinamicki deo memorije

public:
	StudentDoktorskih(); //podrazumevani konstruktor
	StudentDoktorskih(const char* ime, const char* prezime, int indeks, int maxBrojIspita, const char* oblastIstrazivanja); //konstruktor za postavljanje vrednosti
	~StudentDoktorskih(); //destruktor
	
	void postaviOblast(const char* oblastIstrazivanja); //metoda za postavljanje oblasti istrazivanja
	void prikaz(); //metoda za prikaz
};
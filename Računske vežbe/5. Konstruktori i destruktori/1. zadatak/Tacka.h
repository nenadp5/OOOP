#pragma once
class Tacka {
private:  //privatni atributi klase tacka
	float x;
	float y;

public: //javni atributi klase tacka
	Tacka(float x, float y); //konstruktor koji postavlja vrednosti X i Y koordinate
	Tacka(); //podrazumevani konstruktor
	Tacka(Tacka& original); //konstruktor za kopiranje
	~Tacka(); //destruktor

	void postaviX(float x) { //inline metoda za postavljanje X koordinate
		this->x = x; //koristimo this-> kako ne bi prilikom kompajliranja doslo do zabune, buduci da privatni atribut i prosledjena vrednost dele isto ime
	}
	void postaviY(float y) {//inline metoda za postavljanje Y koordinate
		this->y = y;
	}
	
	void pomeri(float pomX, float pomY); //metoda za pomeranje tacke
	float rastojanje(const Tacka& druga); //metoda koja racuna rastojanje izmedju tekuce tacke i prosledjene tacke
};
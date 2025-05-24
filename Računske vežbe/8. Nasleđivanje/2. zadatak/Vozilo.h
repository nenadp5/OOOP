#pragma once
class Vozilo {
private: //privatni atributi klase "Vozilo"
	float brzina;
	float stanjeRezervoara;

protected: //zasticeni atributi klase "Vozilo", ne razlikuju se toliko od obicnih, samo po nacinu pristupa
	void povecajDotokGoriva(); //metoda za povecanje dotoka goriva
	void aktivirajSistemKocenja(); //metoda za aktiviranje sistema kocenja

public:
	Vozilo(); //podrazumevani konstruktor
	void ubrzaj(); //metoda za ubrzavanje
	void uspori(); //metoda za usporavanje
};
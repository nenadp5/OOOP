#pragma once
#include "GeometrijskaFigura.h"
class Kvadrat :public GeometrijskaFigura { //kreiramo klasu "Kvadrat" koja je izvedena iz klase "GeometrijskaFigura"
private:
	float a; //privatni atributi klase

public:
	Kvadrat(float a); //konstruktor za postavljanje vrednosti
	void prikaz(); //metoda za prikaz

	float povrsina(); //ponovo definisemo metode za povrsinu i obim iako su definisane kao ciste virtuelne metode
	float obim();
};
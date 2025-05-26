#pragma once
#define PI 3.14f; //definisemo element koji cemo cesto koristiti
#include "GeometrijskaFigura.h"
class Krug : public GeometrijskaFigura { //kreiramo klasu "Krug" koja je izvedena iz klase "GeometrijskaFigura"
private:
	float r; //privatni atribut klase "Krug"

public:
	Krug(float r); //konstruktor za postavljanje poluprecnika
	void prikaz(); //metoda za prikaz

	float povrsina(); //iako nisu recene u tekstu zadatka, buduci da su definisane kao ciste virtuelne moraju da se definisu u svakoj klasi
	float obim();
};
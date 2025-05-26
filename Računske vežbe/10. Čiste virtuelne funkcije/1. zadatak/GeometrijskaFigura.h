#pragma once
class GeometrijskaFigura { //kreiramo klasu "GeometrijskaFigura"
private:
	char* naziv; //privatni atribut koji se nalazi u dinamickoj zoni memorije

public:
	GeometrijskaFigura(const char* naziv); //konstruktor koji postavlja naziv
	virtual ~GeometrijskaFigura(); //virtuelni destruktor

	virtual float povrsina() = 0; //cista virtuelna funkcija za racunanje povrsine
	virtual float obim() = 0; //cista virtuelna funkcija za racunanje obima

	virtual void prikaz(); //virtuelna metoda za prikaz
	bool operator>(GeometrijskaFigura& figura); //operator koji poredi geometrijske figure na osnovu njihove povrsine
};

/*Cisto virtuelna funkcija je funkcija u baznoj klasi koja nema implementaciju i mora se redefinisati u izvedenim klasama. Oznacava se sa = 0 na kraju deklaracije.
Ako klasa ima bar jednu cisto virtuelnu funkciju, postaje apstraktna klasa (ne moze se instancirati). Sluzi kao sablon za izvedene klase.
Sve izvedene klase moraju dati svoju verziju te funkcije, inace ce i one postati apstraktne.*/
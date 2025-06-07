#pragma once
class GeometrijskoTelo { //kreiramo klasu "GeometrijskaFigura" koja je osnovna klasa u ovom zadatku
public: //sadrzi samo javne atribute
	virtual float povrsina() = 0; //cista virtuelna funkcija za racunanje povrsine
	virtual float zapremina() = 0; //cista virtuelna funkcija za racunanje zapremine
	virtual void prikaz() = 0; //cista virtuelna funkcija za prikaz
	bool operator>(GeometrijskoTelo& telo); //logicka metoda koja poredi zapremine geometrijskih tela
};

/* Cim klasa ima jednu cistu virtuelnu funkciju, ona automatski postaje apstraktna klasa
Ciste virtuelne funkcije se deklarisu na nacin koji je obavljen iznad, odnosno na kraju se stavlja =0
Ciste virtuelne funkcije se ne definisu u okviru CPP fajla ove klase, vec je neophodno za svaku izvrsiti posebno deklarisanje i definisanje*/
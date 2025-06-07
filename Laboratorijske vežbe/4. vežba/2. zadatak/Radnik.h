#pragma once
class Radnik { //kreiramo osnovnu klasu "Radnik"
protected: //zasticeni atributi klase
	char* ime; //ime i prezime radnika smesteno u dinamickoj zoni memorije
	char* prezime;
	virtual float IznosPlate() = 0; //cista virtuelna funkcija za racunanje plate
public:
	Radnik(const char* ime, const char* prezime); //konstruktor za postavljanje vrednosti
	virtual ~Radnik(); //virtuelni destruktor
	bool operator>(Radnik& drugi); //operator koji poredi radnike po plati
	virtual void prikaz() = 0; //cista virtuelna funkcija za prikaz
};

//cista virtuelna funkcija se deklarise tako sto na kraju stavimo "=0"
//njena definicija se ne obavlja u okviru CPP fajla ove klase, vec za svaku podklasu posebno
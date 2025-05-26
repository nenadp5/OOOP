#pragma once
class KompleksniBroj {
protected: //zasticeni atributi klase "KompleksniBroj"
	virtual float moduo() = 0; //cista virtuelna funkcija za racunanje modua kompleksnog broja

public: //javni atributi klase 
	virtual void prikaz() = 0; //cista virtuelna funkcija za prikaz podataka u kompleksnom broju
	bool operator>(KompleksniBroj& broj); //operator koji odredjuje koji je broj veci na osnovu modua kompleksnog broja
};

/*Cisto virtuelna funkcija je funkcija u baznoj klasi koja nema implementaciju i mora se redefinisati u izvedenim klasama. Oznacava se sa = 0 na kraju deklaracije.
Ako klasa ima bar jednu cisto virtuelnu funkciju, postaje apstraktna klasa (ne moze se instancirati). Sluzi kao sablon za izvedene klase.
Sve izvedene klase moraju dati svoju verziju te funkcije, inace ce i one postati apstraktne.*/
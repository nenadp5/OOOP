#pragma once
class Proizvod {
private: //privatni atributi klase
	char naziv[20];
	float osnovna_cena;
	static float pdv; //staticki privatni atribut, koji ispred tipa mora da poseduje static

public:
	void postaviNaziv(char* naziv); //metoda za postavljanje naziva
	void postaviCenu(float osnovna_cena); //metoda za postavljanje osnovne cene bez pdv
	static void postaviPDV(float pdv); //metoda za postavljanje vrednosti statickog atributa
	
	char* vratiNaziv() { //inline metoda za vracanje naziva proizvoda, mora da bude formata char* jer je povratna vrednost string
		return this->naziv;
	}

	float vratiCenu() { //inline metoda za vracanje osnovne cene proizvoda bez PDV-a
		return this->osnovna_cena;
	}

	float cenaSaPDV(); //metoda za racunanje cene proizvoda sa PDV-om, koja ce biti definisana u CPP fajlu

};
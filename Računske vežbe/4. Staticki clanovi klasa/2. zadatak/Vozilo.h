#pragma once
class Vozilo {
private: //privatni atributi klase
	char naziv[20];
	float maxBrzina;
	static float BrzinaUNaselju; //staticki privatni atributi za ogranicenje brzine na odredjenim delovima puta
	static float BrzinaVanNaselja;
	static float BrzinaNaAutoputu;
public:
	void postaviNaziv(const char* naziv); //metoda za postavljanje naziva (objasnjenje zasto je ovde -const char* naziv- je u posebnom fajlu u okviru ovog foldera)
	void postaviBrzinu(float maxBrzina = 220); //metoda za postavljanje maksimalne brzina, ukoliko nista ne navedemo prilikom poziva ove metode, njoj ce automatski biti dodeljena definisana vrednost 220
	static void postaviOgranicenje(float UNaselju = 50, float VanNaselja = 80, float NaAutoputu = 130); //metoda za postavljanje vrednosti statickih atributa, ukoliko nista ne prosledimo prilikom poziva ove metode, njoj ce automatski biti dodeljene definisane vrednosti 50,80,130
	
	char* vratiNaziv(){ //inline metoda za vracanje naziva
		return this->naziv;
	}

	float vratiBrzinu() { //inline metoda za vracanje brzine
		return this->maxBrzina;
	}

	float ukupnoVreme(float kmUNaselju=0, float kmVanNaselja=0, float kmNaAutoputu=0); //metoda za racunanje ukupnog vremena koje je vozilo provelo na putu
	 //vrednostima kmUNaselju, kmVanNaselja, kmNaAutoputu su dodeljene vrednosti 0 jer vozilo ne mora da se nalazi na svim deonicama puta
};
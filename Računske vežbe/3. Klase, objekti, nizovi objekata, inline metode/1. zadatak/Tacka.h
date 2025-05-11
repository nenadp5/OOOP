#pragma once
class Tacka {
private:   //privatni atributi klase Tacka
	float x;
	float y;

public: //javni atributi klase Tacka
	void postaviX(float argX); //metoda za postavljane vrednosti atributa X
	void postaviY(float y);  //metoda za postavljanje vrednosti atributa Y
	
	float vratiX() { //inline metoda za vracanje vrednosti atributa X
		return x;
	}
	float vratiY() { //inline metoda za vracanje vrednosti atributa y
		return y;
	}

	void pomeri(float argX, float argY); //metoda koja pomera tekucu tacku za zadati pomeraj
	float rastojanje(const Tacka& druga); //metoda koja racuna rastojanje izmedju tekuce tacke i druge prosledjene tacke
										  //koristimo parametar const zato sto ne trebamo da menjamo vrednost prosledjenog elementa
};


/*Dodatno objasnjenje:
U header fajlu najcesce samo "uvedemo" metode koje cemo kasnije u okviru CPP fajla definisati sta rade.
Ukoliko nam se trazi da imamo inline metodu, onda se njeno definisanje obavlja u okviru header fajla, kao sto je ovde slucaj
*/
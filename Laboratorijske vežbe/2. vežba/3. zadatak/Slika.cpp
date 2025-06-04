#include "Slika.h"
#include <iostream>
using namespace std;

Slika::Slika(int maxBr, int trBr, float* nizR, float* nizG, float* nizB) {
	this->maxBr = maxBr; //dodeljujemo vrednosti privatnim atributima
	this->trBr = trBr;

	this->nizR = new float[maxBr]; //dinamicka alokacija za niz crvene boje
	for (int i = 0; i < trBr; i++) {
		this->nizR[i] = nizR[i]; //prolazimo kroz niz i upisujemo vrednosti
	}
	this->nizG = new float[maxBr];  //dinamicka alokacija za niz zelene boje
	for (int i = 0; i < trBr; i++) {
		this->nizG[i] = nizG[i]; //prolazimo kroz niz i upisujemo vrednosti
	}
	this->nizB = new float[maxBr];  //dinamicka alokacija za niz plave boje
	for (int i = 0; i < trBr; i++) {
		this->nizB[i] = nizB[i]; //prolazimo kroz niz i upisujemo vrednosti
	}
}

Slika::Slika() {
	this->trBr = 0; //podrazumevani konstruktor za postavljanje vrednosti na 0, NULL, ili prazno u zavisnosti od tipa promenljive
	this->maxBr = 0;
	this->nizR = NULL;
	this->nizG = NULL;
	this->nizB = NULL;
}

Slika::~Slika() {
	delete[]nizR;
	delete[]nizG; //destruktor koji brise elemente smestene u dinamickoj zoni memorije
	delete[]nizB;
}

Slika::Slika(const Slika& original) { //konstruktor za kopiranje
	this->maxBr = original.maxBr;
	this->trBr = original.trBr; //dodeljujemo vrednosti privatnim atributima

	this->nizR = new float[maxBr]; //dinamicka alokacija za niz crvene boje
	for (int i = 0; i < trBr; i++) {
		this->nizR[i] = original.nizR[i]; //prolazimo kroz niz i upisujemo vrednosti
	}
	this->nizG = new float[maxBr]; //dinamicka alokacija za niz zelene boje
	for (int i = 0; i < trBr; i++) {
		this->nizG[i] = original.nizG[i]; //prolazimo kroz niz i upisujemo vrednosti
	}
	this->nizB = new float[maxBr]; //dinamicka alokacija za niz plave boje
	for (int i = 0; i < trBr; i++) {
		this->nizB[i] = original.nizB[i]; //prolazimo kroz niz i upisujemo vrednosti
	}
}

float Slika::srednjeR() const {
	float vrednostR = 0; //kreiramo pomocnu promenljivu
	for (int i = 0; i < trBr; i++) {
		vrednostR += this->nizR[i]; //prolazimo kroz ceo niz i sumiramo vrednosti
	}
	return vrednostR / trBr; //delimo pomocnu promenljivu sa trenutnim brojem elemenata u nizu kako bi dobili srednju vrednost
}

float Slika::srednjeG() const {
	float vrednostG = 0; //kreiramo pomocnu promenljivu
	for (int i = 0; i < trBr; i++) {
		vrednostG += this->nizG[i];  //prolazimo kroz ceo niz i sumiramo vrednosti
	}
	return vrednostG / trBr; //delimo pomocnu promenljivu sa trenutnim brojem elemenata u nizu kako bi dobili srednju vrednost
}

float Slika::srednjeB() const {
	float vrednostB = 0; //kreiramo pomocnu promenljivu
	for (int i = 0; i < trBr; i++) {
		vrednostB += this->nizB[i]; //prolazimo kroz ceo niz i sumiramo vrednosti
	}
	return vrednostB / trBr; //delimo pomocnu promenljivu sa trenutnim brojem elemenata u nizu kako bi dobili srednju vrednost
}

float Slika::prebaciUSivu() const {
	return (0.3 * srednjeR() + 0.59 * srednjeG() + 0.11 * srednjeB()); //povratna vrednost nam je vrednost sive boje, koja se dobija po formuli koja je data u tekstu zadatka
}

Slika& Slika::operator=(const Slika& druga) { //operator koji uzima vrednosti od prosledjenog objekta
	if (this != &druga) { //proveravamo da li su prosledjeni i trenutni objekat razliciti
		if (this->nizR != NULL) { //ukoliko su nizovi zauzeti, moramo izbrisati te vrednosti kako bi napravili mesta za nov upis
			delete[]nizR;
		}
		if (this->nizG != NULL) {
			delete[]nizG;
		}
		if (this->nizB != NULL) {
			delete[]nizB;
		}
		this->maxBr = druga.maxBr; //dodeljujemo vrednosti prosledjenog objekta ka trenutnom objektu
		this->trBr = druga.trBr;

		this->nizR = new float[maxBr]; //vrsimo dinamicku alokaciju
		for (int i = 0; i < trBr; i++) {
			this->nizR[i] = druga.nizR[i]; //prolazimo kroz niz crvene boje trenutnog objekta i upisujemo vrednosti niza crvene boje prosledjenog objekta
		}
		this->nizG = new float[maxBr]; //vrsimo dinamicku alokaciju
		for (int i = 0; i < trBr; i++) {
			this->nizG[i] = druga.nizG[i]; //prolazimo kroz niz zelene boje trenutnog objekta i upisujemo vrednosti niza zelene boje prosledjenog objekta
		}
		this->nizB = new float[maxBr]; //vrsimo dinamicku alokaciju
		for (int i = 0; i < trBr; i++) {
			this->nizB[i] = druga.nizB[i]; //prolazimo kroz niz plave boje trenutnog objekta i upisujemo vrednosti niza plave boje prosledjenog objekta
		}
	}
	return *this;
}

Slika& Slika::operator++() { //prefiksni operator za uvecanje vrednosti u nizu
	for (int i = 0; i < trBr; i++) {
		this->nizR[i]++; //prolazimo kroz sve nizove i uvecavamo njihove vrednosti za po jedan
		this->nizG[i]++;
		this->nizB[i]++;
	}
	return *this; //povratna vrednost je azurirani trenutni objekat
}

Slika Slika::operator--(int n) { //postfiksni operator za smanjivanje vrednosti u nizu
	Slika kopija(*this); //kreiramo dodatni objekat uz pomoc trenutnog
	for (int i = 0; i < trBr; i++) {
		this->nizR[i]--; //prolazimo kroz sve nizove i smanjujemo vrednosti
		this->nizG[i]--;
		this->nizB[i]--;
	}
	return kopija; //povratna vrednost je novoformirani objekat, tj onaj gde nisu prisutne izmene
}

Slika Slika::operator+(const Slika& druga) { //operator koji sabira objekte
	Slika nova; //kreiramo novu promenljivu tipa "Slika"
	nova.maxBr = this->maxBr; //dodeljujemo vrednosti novom objektu
	nova.trBr = this->trBr;
	nova.nizR = new float[nova.trBr]; //vrsimo dinamicke alokacije za nizove nove promenljive
	nova.nizG = new float[nova.trBr];
	nova.nizB = new float[nova.trBr];
	if (this->trBr != druga.trBr) { //proveravamo da li su slike istih dimenzija
		cout << "Greska! Razlicite dimenzije slika, pa je shodno tome nemoguce izvrsiti sabiranje! " << endl; //ukoliko su razilicite dimenzije u pitanju, ispisuje se poruka
	}
	else {
		for (int i = 0; i < trBr; i++) {
			nova.nizR[i] = this->nizR[i] + druga.nizR[i]; //ukoliko su iste dimenzije, nizove nove promenljive punimo, tako sto sabiramo vrednosti nizova trenutnog objekta i prosledjenog
			nova.nizG[i] = this->nizG[i] + druga.nizG[i];
			nova.nizB[i] = this->nizB[i] + druga.nizB[i];
		}
	}
	return nova; //povratna vrednost je nova promenljiva tipa "Slika"
}

ostream& operator<<(ostream& izlaz, const Slika& s) { //operator za prikaz vrednosti
	izlaz << "Srednja vrednost crvene boje: " << s.srednjeR() << endl; //pozivamo metode i ispisujemo njihove vrednosti
	izlaz << "Srednja vrednost zelene boje: " << s.srednjeG() << endl;
	izlaz << "Srednja vrednost plave boje: " << s.srednjeB() << endl;
	izlaz << "Vrednost sive boje: " << s.prebaciUSivu() << endl;
	return izlaz;
}
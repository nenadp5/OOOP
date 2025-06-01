#include "Slika.h" //ukljucujemo biblioteke neophodne za rad
#include <iostream>
using namespace std;
int main() {
	int R[] = { 120,130,140,150,160 }; //kreiramo pomocne nizove u koje smestamo vrednosti za boje
	int G[] = { 100,110,120,130,140 };
	int B[] = { 90,100,110,120,130 };
	Slika S1(R, G, B, 10, 5); //kreiramo promenljivu tipa "Slika" uz pomoc konstruktora za postavljanje vrednosti
	cout << "Informacije o originalnoj slici: " << endl;
	S1.prikaz(); //pozivamo metodu za prikaz informacija vezanih za slike
	cout << endl;

	Slika Kopija(S1); //kreiramo promenljivu tipa "Slika" uz pomoc konstruktora za kopiranje, tako sto prosledjujemo prethodno kreiranu promenljivu
	cout << "Informacije o kopiji slike: " << endl;
	Kopija.prikaz(); //pozivamo metodu za prikaz informacija vezanih za kopiju slike

	return 0;
}
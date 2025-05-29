#include "Radnik.h"
#include "Sef.h"
#include "Firma.h"
#include <iostream>
using namespace std;
int main() {
	Firma F;
	Sef direktor("Nikola", "Nikolic", 12345, 100000, "Direktor"); //kreiramo direktora uz pomoc konstruktora za njegovu dodelu
	Sef S1("Jovan", "Jovanovic", 21356, 95000, "Sef prodaje", &direktor); //kreiramo sefa uz pomoc konstruktora za njegovu dodelu 
	Sef S2("Filip", "Filipovic", 435112, 85000, "Sef proizvodnje", &direktor);
	F.dodajRadnika(direktor); //dodajemo novoformirane radnike u firmi
	F.dodajRadnika(S1);
	F.dodajRadnika(S2);

	Radnik R1("Petar", "Pavlovic", 56789, 60000, &S1); //kreiramo radnike uz pomoc konstruktora za dodelu njihovih vrednosti 
	Radnik R2("Pavle", "Paunovic", 98746, 60000, &S1);
	Radnik R3("Milica", "Miletic", 56382, 60000, &S1);
	F.dodajRadnika(R1);
	F.dodajRadnika(R2);
	F.dodajRadnika(R3); //dodajemo novoformirane radnike

	Radnik R4("Marko", "Markovic", 64831, 59000, &S2); //ponovo kreiramo radnike samo za drugog sefa
	Radnik R5("Ilija", "Ilic", 74921, 55000, &S2);
	F.dodajRadnika(R4);
	F.dodajRadnika(R5); //dodajemo nove radnike

	cout << *(F.direktor()) << endl; //pozivamo metodu za pronalazenje direktora firme, i odmah u okviru toga prosledjujemo na ispis
	cout << "Zbir svih plata je: " << F.zbir() << endl; //racunamo zbir plata uz pomoc metode za to

	Radnik* max=F.maxPlata(direktor); //kreiramo pomocnu promenljivu u koju smestamo radnika sa najvecom platom kojeg kontrolise direktor
	cout << "Radnik sa najboljom platom posle direktora je: " << *max<<endl;

	cout << "Promenjena plata radniku R5 je: ";
	S2.postaviPlatuRadniku(R5, 59000); //pozivamo metodu za promenu plate radniku R5 koji je pod komandom sefa S2
	cout << R5;

	return 0;
}
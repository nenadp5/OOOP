#include "Vektor.h"
#include <iostream>
using namespace std;
int main() {
	Vektor V1(4); //kreiramo vektore sa po 4 elementa
	cout << "Unesi elemente vektora V1: ";
	cin >> V1;
	Vektor V2(4);
	cout << "Unesi elemente vektora V2: ";
	cin >> V2; //prilikom unosa, koristi se prijateljska operacija za unos (odnosno operator>>)
	cout << endl;
	cout << "V1: " << V1 << endl; //prilikom ispisa, koristi se prijateljska operacija za prikaz (odnosno operator<<)
	cout << "V2: " << V2 << endl;

	Vektor V3 = V1 + V2; //kreiramo novi Vektor koji se dobija kao zbir prethodna dva u kombinaciji sa operatorom za sabiranje
	cout << "Zbir vektora V1 i V2: " << V3 << endl;
	Vektor V4 = V1 + 4.0f; //primenjujemo operator za sabiranje vektora i skalarne vrednosti i potom rezultat smestamo u novu promenljivu
	cout << "Zbir vektora V1 sa skalarnom vrednoscu 4 je: " << V4 << endl;
	Vektor V5 = 1.0f + V2; //primenjujemo prijateljsku funkcije za sabiranje skalarne vrednosti sa vektorom i rezultat smestamo u novu promenljivu
	cout << "Zbir skalara 1 sa vektorom V2 je: " << V5 << endl;

	cout << "Prefiksni inkrement vektora V1: " << ++V1 << endl; //prefiksno inkrementiranje, gde ce se prikazati uvecane vrednosti na ekranu
	cout << "Postfiksni inkrement vektora V2: " << V2++ << endl; //postfiksno inkrementiranje, gde prilikom prikaza nece biti nikakve izmene
	cout << "Naredni prikaz vektora V2: " << V2 << endl; //naredni prikaz, koji ce prikazati uvecane vrednosti zbog postfiksnog inkrementa

	V1 = V2; //vektor v1 ce imati vrednosti vektora v2 (uvecanu vrednost zbog prethodno upotrebljenog postfiksnog inkrementa) zbor operatora za dodelu vrednosti
	cout << "Vektor V1 nakon prethodne izmene izgleda: " << V1;

	return 0;

}
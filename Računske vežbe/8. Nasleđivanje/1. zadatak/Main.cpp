#include "Krug.h"
#include "ObojeniKrug.h"
#include "PlaviKrug.h"
#include <iostream>
using namespace std;
int main() {
	Krug K1; //Kreiramo promenljive za svaku klasu uz pomoc podrazumevanih konstruktora
	K1.prikaz();
	cout << endl;
	ObojeniKrug K2; 
	K2.prikaz(); //svi podaci ce biti prikazani sa vrednoscu 0 jer je u pitanju podrazumevani konstruktor
	PlaviKrug K3;
	K3.prikaz();

	Krug K4(7); //kreiramo promenljive za svaku klasu uz pomoc konstruktora za dodelu vrednosti
	K4.prikaz();
	cout << endl;
	ObojeniKrug K5(7, 200, 150, 100); 
	K5.prikaz(); //sada ce prikaz imati smisla i prikazace se prave vrednosti
	PlaviKrug K6(5, 100);
	K6.prikaz();

	Krug* K7 = new Krug(8); //kreiramo promenljive za svaku klasu uz pomoc konstruktora za dodelu vrednosti i smestamo ih u dinamicke deo memorije
	K7->prikaz();
	delete K7;
	cout << endl;
	ObojeniKrug* K8 = new ObojeniKrug(8, 200, 150, 100);
	K8->prikaz(); //sada ce prikaz imati smisla i prikazace se odgovarajuce vrednosti
	delete K8;
	PlaviKrug* K9 = new PlaviKrug(6, 100);
	K9->prikaz();
	delete K9; //odmah vrsimo brisanje nakon prikaza kako bi oslobodili zauzetu memoriju
	
	return 0;
}
#include <iostream>
#include "Tacka.h"
using namespace std;
int main() {
	float argX, argY;  //kreiramo pomocne promenljive koje kasnije prosledjujemo konstruktorima i metodama
	cout << "Unesi X koordinatu prve tacke: ";
	cin >> argX;
	cout << "Unesi Y koordinatu prve tacke: ";
	cin >> argY;
	Tacka t1(argX, argY); //odmah prlikom kreiranja smo implementirali i konstrukor za postavljanje vrednosti
	cout << "Unesi X koordinatu druge tacke: ";
	cin >> argX;
	cout << "Unesi Y koordinatu druge tacke: ";
	cin >> argY;
	
	Tacka* t2 = new Tacka(argX, argY); //takodje odmah prilikom obavljanja dinamicke alokacije smo primenili i konstuktor za postavljanje odgovarajucih vrednosti
	cout << endl;

	t1.pomeri(1, 0); //buduci da je t1 u statickoj zoni memorije, kako bismo pristupili metodi koristimo tacku (.)
	t2->pomeri(0, 1); //kako je t2 u dinamickoj zoni memorije, da bismo pristupili metodi koristimo operator strelica(->)

	float duzina = 0;//uvodimo pomocnu promenljivu za rastojanje
	duzina = t1.rastojanje(*t2); //rastojanje racunamo uz pomoc metode, t1 i njeni parametri ce biti u metodi obelezeni sa this->, dok t2 i njeni parametri ce nositi oznaku druga.x i druga.y
	cout << "Rastojanje izmedju ove dve tacke je: " << duzina;
	delete t2; //oslobadjamo memoriju zauzetu prilikom dinamicke alokacije
	return 0;
}
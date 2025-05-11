#include "Tacka.h" //kod ukljucivanja Tacka.h koristimo "" zato sto to predstavlja fajl u okviru ovog programa, dok kod ukljucivanja neke biblioteke koristimo <> zato sto je biblioteka smestena u sistem
#include <iostream>
#include <cmath>

void Tacka::postaviX(float argX) {
	x = argX; //atributu X se dodeljuje vrednost prosledjenog elementa argX
}

void Tacka::postaviY(float y) {
	this->y = y; //moramo ovako obavljati proces dodeljivanja, jer argument i prosledjena vrednost dele isto ime, pa da u procesu kompajliranja ne bi doslo do zabune, koristimo komandu this->
}

void Tacka::pomeri(float argX, float argY) {
	x += argX; //vrednost agrumenata se uvecava za prosledjenu vrednost 
	y += argY;
}

float Tacka::rastojanje(const Tacka& druga) {
	return sqrt(powf(this->x - druga.x, 2) + powf(this->y - druga.y, 2)); //matematicka funkcija za izracunavanje rastojanja izmedju dve tacke
}																		  //x i y su privatne koordinate trenutnog objekta, dok su druga.x i druga.y koordinate druge prosledjene tacke
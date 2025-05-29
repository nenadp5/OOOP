#include "Student.h"
#include "StudentViseGodine.h"
#include "Brucos.h"
#include "Konkurs.h"
#include <iostream>
using namespace std;
int main() {
	Konkurs K; //kreiramo promenljivu K tipa Konkurs
	Student* B1=new Brucos("Nikola", "Nikolic", 12345, 4.5); //kreiramo studente u dinamickoj zoni memorije uz pomoc odgovarajucih konstruktora
	Student *B2=new Brucos("Petar", "Petrovic", 34214, 4.65);
	K.dodajStudenta(B1);
	K.dodajStudenta(B2); //dodajemo studente u konkurs

	Student* S1 = new StudentViseGodine("Milica", "Milovanovic", 51534, 9.3, 3, 2);
	Student* S2 = new StudentViseGodine("Teodora", "Todosijevic", 87123, 9.1, 2, 1); //kreiramo studente u dinamickoj zoni memorije uz pomoc odgovarajucih konstruktora
	Student* S3 = new StudentViseGodine("Marko", "Markovic", 90642, 8.9, 3, 0);
	Student* S4 = new StudentViseGodine("Milos", "Misic", 67453, 9.0, 4, 2);
	K.dodajStudenta(S1);
	K.dodajStudenta(S2); //dodajemo studente u konkurs uz pomoc metode
	K.dodajStudenta(S3);
	K.dodajStudenta(S4);

	cout << endl;
	K.prikaz(); //pozivamo metodu za prikaz, koja prikazuje uneti niz studenata
	cout << endl;
	K.sortiraj(); //pozivamo metodu za soritranje
	cout << endl;
	K.prikaz(); //pozivamo metodu za prikaz, koja prikazuje sortirani niz studenata

	return 0;
}
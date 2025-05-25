#include "Student.h"
#include "StudentOsnovnihStudija.h"
#include "StudentDoktorskihStudija.h"
#include <iostream>
using namespace std;
int main() {
	Student* S[3]; //kreiramo niz od tri pokazivaca na objekte tipa student
	S[0] = new Student("Petar", "Petrovic", 12345, 3); //kreiramo studenta i dodajemo mu ocene
	S[0]->dodajOcenu(7);
	S[0]->dodajOcenu(9);
	S[0]->dodajOcenu(10);

	S[1] = new StudentOsnovnih("Nikola", "Nikolic", 4321, 10, 3); //kreiramo studenta osnovnih studija i dodajemo mu ocene
	S[1]->dodajOcenu(6);
	S[1]->dodajOcenu(7);
	S[1]->dodajOcenu(8);

	S[2] = new StudentDoktorskih("Milos", "Milosevic", 234, 6, "Fotosinteza"); //kreiramo studenta doktorskih studija i dodajemo mu ocene
	S[2]->dodajOcenu(9);
	S[2]->dodajOcenu(10);
	S[2]->dodajOcenu(9);

	for (int i = 0; i < 3; i++) {
		S[i]->prikaz(); //vrsimo prikaz svakog studenta, moguce je ovako jer je metoda prikaz virtuelna (virtual void prikaz()) pa nije potrebno striktno naglasiti na koji prikaz mislimo
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		if (S[i] != NULL) {
			delete S[i]; //oslobadjamo memoriju koju je svaki student posebno zauzeo prilikom dinamicke alokacije
		}
	}
	return 0;
}


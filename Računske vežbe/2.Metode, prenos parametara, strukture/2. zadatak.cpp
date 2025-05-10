#include <iostream>
using namespace std;

int zbir(int x, int y) { //obicna funkcije koja obavlja sabiranje dva prosledjena broja iz glavnog programa
	int c;
	c = x + y;
	return c;
}

void inkrement(int x) { //funkcija koja obavlja inkrementiranje prvi nacin
	x++; //promena parametara je vidljiva samo u funkciji (nece se videtu u glavnom programu)
}

void inkRef(int& x) { //funkcija koja obavlja inkrementiranje drugi nacin
	x++; //buduci da se prosledjuje memorijska lokacija, i da se promene obavljaju nad vrednosti u toj memorijskoj lokaciji, promene ce biti vidljive u glavnom programu
}

void inkPok(int* x) { //funkcija koja obavlja inkrementiranje treci nacin
	(*x)++; //obavlja se dereferenciranje prosledjene memorijske lokacije, tako da promene koje se obave su vidljive u glavnom programu
}

int main() {
	int A, B;
	cout << "Unesi vrednost broja A: ";
	cin >> A;
	cout << "Unesi vrednost broja B: ";
	cin >> B;
	
	cout << "Zbir unetih brojeva je: " << zbir(A, B) << endl;
	inkrement(A);
	cout << "Inkrementiranje broja A preko prve funkcije: " << A << endl;
	inkRef(A);
	cout << "Inkrementiranje broja A preko druge funkcije je: " << A << endl;
	inkPok(&A);
	cout << "Inkrementiranje broja A preko trece funkcije je: " << A << endl;
	
	return 0;
}

/* Dodatno objasnjenje:
void inkrement(int x) -- Podrazumevani nacin prenosa parametara u funkciji je po vrednosti,
buduci da mi na kraju nemamo povratnu vrednost onda ce promena biti vidljiva samo u telu te funkcije

void inkRef(int& x) -- Funkcija ocekuje memorijsku lokaciju, mi iz glavnog programa prosledjujemo promenljivu,
funckija potom pristupa memorijskoj lokaciji te promenljive, i promene koje se obave su vidljive u glavnom programu

void inkPok(int* x) -- Buduci da funkcija ocekuje pokazivac kao prosledjenu vrednost, mi iz glavnom programa prosledjujemo memorijsku adresu,
potom funkcije uz pomoc dereferenciranje pristupa toj memorijskoj lokaciji i obavlja promene koje su vidljive i u glavnom programu.
*/
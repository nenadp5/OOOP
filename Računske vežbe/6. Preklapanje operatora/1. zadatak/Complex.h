#pragma once
class Complex {
private: //privatni atributi klase Complex koji predstavljaju kompleksni broj
	double re;
	double im;

public:
	Complex(double r, double i); //konstruktor za postavljanje vrednosti
	Complex(const Complex& original); //konstruktor za kopiranje
	Complex(); //podrazumevani konstruktor
	~Complex(); //destruktor

	void prikaz(); //metoda za prikaz
	float moduo() const; //metoda za racunanje modua kompleksnog broja

	Complex operator+(const Complex& desni); //operator za sabiranje
	Complex operator*(const Complex& desni); //operator za mnozenje
	Complex& operator=(const Complex& desni); //operator za dodelu vrednosti

	Complex& operator++(); //prefiksni operator za inkrementiranje
	Complex operator++(int n); //postfiksni operator za inkrementiranje

	bool operator<(const Complex& desni); //operator koji poredi da li je prosledjeni element veci od trenutnog
	bool operator>(const Complex& desni); //operator koji poredi da li je prosledjeni element manji od trenutnog
	bool operator==(const Complex& desni); //operator koji poredi da li su prosledjeni i trenutni element isti
};
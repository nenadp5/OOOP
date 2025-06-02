#pragma once
#include "Film.h"
class CrtaniFilm :public Film { //kreiramo klasu "CrtaniFilm" koja je izvedena iz klase "Film"
private: //privatni atributi klase
	int brojDece; //broj dece i popust na kartu su smesteni u statickoj zoni memorije
	float popust;
public:
	CrtaniFilm(); //podrazumevani konstruktor
	CrtaniFilm(const char* naslov, int brojGledalaca, float cena, int brojDece, float popust); //konstruktor koji postavlja vrednosti
	~CrtaniFilm(); //destruktor
	float prihod(); //metoda koja racuna prihod
	void prikaz(); //metoda za prikaz
};
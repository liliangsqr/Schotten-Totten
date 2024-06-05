#ifndef CARTE_H
#define CARTE_H
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Carte
{
protected :
	unsigned int pValeur;
	unsigned int  pCouleur;

public:
	#pragma region GETTERS
	unsigned int GetValeur() const { return pValeur; }
	unsigned int getCouleur() const { return pCouleur; }
	#pragma endregion
	
};

#endif CARTE_H
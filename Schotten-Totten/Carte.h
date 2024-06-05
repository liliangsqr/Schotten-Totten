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
	unsigned int GetValeur() const { return pValeur; }
	unsigned int getCouleur() const { return pCouleur; }
	
	// Sert à faire fonctionner le dynamic cast
	virtual ~Carte() = default;
};

#endif CARTE_H
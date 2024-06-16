#ifndef CARTE_H
#define CARTE_H
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

// Classe servant de base aux différents types de cartes existants
class Carte
{
protected :
	unsigned int pValeur;
	unsigned int  pCouleur;

public:
	Carte(unsigned int initValeur, unsigned int initCouleur) : pValeur(initValeur), pCouleur(initCouleur) {}
	unsigned int getValeur() const { return pValeur; }
	unsigned int getCouleur() const { return pCouleur; }
	
	// Sert à faire fonctionner le dynamic cast
	virtual ~Carte() = default;
};

#endif CARTE_H
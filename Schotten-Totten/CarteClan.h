#ifndef CARTECLAN_H
#define CARTECLAN_H
#include "Carte.h"

// Carte de base avec une couleur et une valeur
using namespace std;
class CarteClan : public Carte
{
private:
	// unsigned int pCouleur;
	// unsigned int pValeur;

public:
	CarteClan(unsigned int initValeur, unsigned int initCouleur) : Carte(initValeur, initCouleur) {}

    unsigned int getValeur() const { return pValeur; }

	void toString() { cout << "Carte [" << pValeur << "," << pCouleur << "]" << endl; }
};

#endif CARTECLAN_H
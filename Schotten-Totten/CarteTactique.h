#ifndef CARTETACTIQUE_H
#define CARTETACTIQUE_H
#include "Carte.h"
#include "iomanip"
class CarteTactique : public Carte
{
private:
	unsigned int pValeur;
	// unsigned int pCouleur
	unsigned int pEffet; 
public:
	CarteTactique(unsigned int initVal, unsigned int initCoul, unsigned int initEffet) {
		pValeur = initVal;
		pCouleur = initCoul;
		pEffet = initEffet;

	}

	unsigned int getValeur() { return pValeur; }
	unsigned int getEffet() { return pEffet; }

	void toString() { cout << "Carte [" << pEffet << "," << pCouleur << "] et as pour effet : " << pEffet << endl; }
};

#endif CARTETACTIQUE_H
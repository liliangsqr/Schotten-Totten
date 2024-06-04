#ifndef CARTETACTIQUE_H
#define CARTETACTIQUE_H
#include "Carte.h"
#include "iomanip"
class CarteTactique : public Carte
{
private:
	// unsigned int pCouleur
	unsigned int pNom;
	unsigned int pEffet; 
public:
	CarteTactique(unsigned int initVal, unsigned int initCoul, unsigned int initNom) {
		pValeur = initVal;
		pCouleur = initCoul;
		pEffet = initEffet;

	}

	unsigned int& getValeur() { return pNom; }
	unsigned int& getEffet() { return pEffet; }

	void toString() { cout << "Carte [" << pNom << "," << pCouleur << "] et as pour effet : " << pEffet << endl; }
};

#endif CARTETACTIQUE_H
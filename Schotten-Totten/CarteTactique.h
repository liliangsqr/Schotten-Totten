#pragma once
#include "Carte.h"
#include "iomanip"
class CarteTactique : public Carte
{
private:
	// unsigned int pCouleur
	unsigned int pNom;
	unsigned int pEffet; 
public:
	CarteTactique( unsigned int initNom,  unsigned int initCoul,  unsigned int initEffet) {
		pNom = initNom;
		pCouleur = initCoul;
		pEffet = initEffet;

	}

	unsigned int& getValeur() { return pNom; }
	unsigned int& getEffet() { return pEffet; }

	void toString() { cout << "Carte [" << pNom << "," << pCouleur << "] et as pour effet : " << pEffet << endl; }
};


#ifndef CARTETACTIQUE_H
#define CARTETACTIQUE_H
#include "Carte.h"
class CarteTactique : public Carte
{
private:
	// unsigned int pCouleur
	unsigned int pValeur;
	unsigned int pNom; 
public:
	CarteTactique(unsigned int initVal, unsigned int initCoul, unsigned int initNom) {
		pValeur = initVal;
		pCouleur = initCoul;
		pNom = initNom;
	}
};

#endif CARTETACTIQUE_H
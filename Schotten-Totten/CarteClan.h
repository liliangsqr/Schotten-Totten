#pragma once
#include "Carte.h"
class CarteClan : public Carte
{
private:
	// unsigned int pCouleur
	unsigned int pValeur;

public:
	CarteClan(unsigned int initValeur, unsigned int initCouleur) {
		pValeur = initValeur;
		pCouleur = initCouleur;
	}
};


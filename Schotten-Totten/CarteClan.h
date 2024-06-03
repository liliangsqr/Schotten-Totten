#pragma once
#include "Carte.h"
class CarteClan : public Carte
{
private:
	// string pCouleur
	int pValeur;

public:
	CarteClan(const unsigned int& initValeur, const string& initCouleur) {
		Carte::pValeur = initValeur;
		Carte::pCouleur = initCouleur;
	}
};


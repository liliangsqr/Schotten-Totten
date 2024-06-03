#pragma once
#include "Carte.h"
class CarteClan : public Carte<int>
{
private:
	// valeur 
	// couleur
public:
	CarteClan(const unsigned int& initValeur, const string& initCouleur) {
		Carte::pValeur = initValeur;
		Carte::pCouleur = initCouleur;
	}
};


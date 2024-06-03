#pragma once
#include "Carte.h"
class CarteTactique : public Carte<string>
{
private:
	// string pValeur
	// string pCouleur
	string pEffet; 
public:
	CarteTactique(const string& initNom, const string& initCoul, const string& initEffet){
		pValeur = initNom;
		pCouleur = initCoul;
		pEffet = initEffet;
	}
};


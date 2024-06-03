#pragma once
#include "Carte.h"
class CarteTactique : public Carte<string>
{
private:
	// string Nom (Valeur)
	// string couleur (couleur)
public:
	CarteTactique(const string& initNom, const string& initEffet){
		Carte::pValeur = initNom;
		Carte::pCouleur = initEffet;
	}
};


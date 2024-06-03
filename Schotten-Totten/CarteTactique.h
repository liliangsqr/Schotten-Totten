#pragma once
#include "Carte.h"
class CarteTactique : public Carte<string>
{
private:
	// string Nom (Valeur)
	// string Effet (couleur)
	string pEffet; 
public:
	CarteTactique(const string& initNom = "", const string& initCouelur = "", const string& initEffet = "") {
		Carte::pValeur = initNom;
		Carte::pCouleur = initCouelur	;
		pEffet = initEffet;
	}
};


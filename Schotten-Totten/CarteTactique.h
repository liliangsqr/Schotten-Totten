#pragma once
#include "Carte.h"
#include "iomanip"
class CarteTactique : public Carte
{
private:
	// string pCouleur
	string pNom;
	string pEffet; 
public:
	CarteTactique(const string& initVal, const string& initCoul, const string& initEffet){
		pValeur = initVal;
		pCouleur = initCoul;
		pEffet = initEffet;

	}

	string& getValeur() { return pNom; }
	string& getEffet() { return pEffet; }

	void toString() { cout << "Carte [" << pNom << "," << pCouleur << "] et as pour effet : " << quoted(pEffet) << endl; }
};


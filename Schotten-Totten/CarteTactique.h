#ifndef CARTETACTIQUE_H
#define CARTETACTIQUE_H
#include "Carte.h"
#include "iomanip"
class CarteTactique : public Carte
{
private:
	// unsigned int pValeur;
	// unsigned int pCouleur
	string pNom;
public:
	CarteTactique(unsigned int initVal, unsigned int initCoul, const string& initNom) {
		pValeur = initVal;
		pCouleur = initCoul;
		pNom = initNom;
	}

	const string& getNom() { return pNom; }

	void toString() { cout << "Carte [" << pNom << "," << pCouleur << "] et as pour effet : " << pNom << endl; }
};

#endif CARTETACTIQUE_H
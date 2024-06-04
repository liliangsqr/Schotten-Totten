#ifndef CARTECLAN_H
#define CARTECLAN_H
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

#endif CARTECLAN_H
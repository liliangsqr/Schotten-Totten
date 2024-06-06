#ifndef CARTECLAN_H
#define CARTECLAN_H
#include "Carte.h"
using namespace std;
class CarteClan : public Carte
{
private:
	// unsigned int pCouleur
	// unsigned int pValeur;

public:
	CarteClan(unsigned int initValeur, unsigned int initCouleur) {
		pValeur = initValeur;
		pCouleur = initCouleur;
	}

	void toString() { cout << "Carte [" << pValeur << "," << pCouleur << "]" << endl; }
};

#endif CARTECLAN_H
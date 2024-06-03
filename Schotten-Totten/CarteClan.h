#pragma once
#include "Carte.h"
using namespace std;
class CarteClan : public Carte
{
private:
	// unsigned int pCouleur
	unsigned int pValeur;

public:
	CarteClan(const unsigned int& initValeur, const string& initCouleur) {
		pValeur = initValeur;
		pCouleur = initCouleur;
	}

	void toString() { cout << "Carte [" << pValeur << "," << pCouleur << "]" <<endl; }

	int& getValeur() { return pValeur; }

};


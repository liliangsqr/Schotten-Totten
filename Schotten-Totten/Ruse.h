#ifndef RUSE_H
#define RUSE_H
#include "CarteTactique.h"

// Carte tactique se jouant dans la défausse
class Ruse : public CarteTactique
{
private:
	//pNom
	//pValeur
	//pCouleur
public:
	Ruse(unsigned int initValeur, unsigned int initCouleur, const string& initNom) :CarteTactique(initValeur, initCouleur, initNom) {}
};

#endif RUSE_H
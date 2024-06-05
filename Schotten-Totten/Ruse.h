#ifndef RUSE_H
#define RUSE_H
#include "CarteTactique.h"
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
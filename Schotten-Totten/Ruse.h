#ifndef RUSE_H
#define RUSE_H
#include "CarteTactique.h"
class TroupeRuse : public CarteTactique
{
private:
	//pNom
	//pValeur
	//pCouleur
public:
	TroupeRuse(unsigned int initValeur, unsigned int initCouleur, const string& initNom) :CarteTactique(initValeur, initCouleur, initNom) {}

};

#endif RUSE_H
#ifndef MODECOMBAT_H
#define MODECOMBAT_H
#include "CarteTactique.h"
class ModeCombat : public CarteTactique
{
private:
	//pNom
	//pValeur
	//pCouleur
public:
	ModeCombat(unsigned int initValeur, unsigned int initCouleur, const string& initNom):CarteTactique(initValeur, initCouleur, initNom) {}
};

#endif MODECOMBAT_H
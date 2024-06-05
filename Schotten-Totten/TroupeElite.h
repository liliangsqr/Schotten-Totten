#ifndef TROUPEELITE_H
#define TROUPEELITE_H
#include "CarteTactique.h"
class TroupeElite : public CarteTactique
{
private:
	//pNom
	//pValeur
	//pCouleur
public:
	TroupeElite(unsigned int initValeur,unsigned int initCouleur,const string& initNom):CarteTactique(initValeur,initCouleur,initNom) {}
};

#endif TROUPEELITE_H